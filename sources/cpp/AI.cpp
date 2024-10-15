#include "AI.h"
#include "Buildings.h"
#include "CONSTANTS.h"
#include "TileStructure.h"
#include "raylib.h"
#include "iostream"
#include "GameMaster.h"
#include <iterator>
#include <random>


void ConductAILogic(GameInformation *GMInfo, Market *AIMarket) //Old and deprecated
{
  if (DEBUGMODE) {  std::cout << "ConductAILogic - Start" << "\n";}
  //AI WIN
  if (AIMarket->Money >= WINCONMONEYCOST)
    {
      std::cout << "AI WON, MARKET: " << AIMarket->IndexID;
      GMInfo->EndGame = true;
    }

  //Expansion
  if (AIMarket->Influence >= INFLUENCEEXPANSIONCOST) //No protection against full world
    {
      GameTileGeneric* RandomTile = &GMInfo->Tiles[GetRandomValue(0, MAPTILEWIDTH)][GetRandomValue(0, MAPTILEHEIGHT)];

      if (RandomTile->Owner == nullptr)
        {
          AIMarket->MarketTiles.push_back(RandomTile);
          AIMarket->Influence -= INFLUENCEEXPANSIONCOST;
          RandomTile->Owner = AIMarket;
        }
    }

  if (DEBUGMODE) {  std::cout << "ConductAILogic - Mid" << "\n";}

  //Buildings
  if (AIMarket->MarketTiles.size() == 0) {return;}

  BuildingType BType = static_cast<BuildingType>(GetRandomValue(1, 7));

  if (AIMarket->Money < CBBUILDINGS[BType]->MoneyCost) {return;}
  AIMarket->Money -= CBBUILDINGS[BType]->MoneyCost;

  if (DEBUGMODE) {  std::cout << "ConductAILogic - Mid2" << "\n";}

  int RandomTile = GetRandomValue(0, AIMarket->MarketTiles.size() - 1);

  GameTileGeneric* SelectedTile = AIMarket->MarketTiles[RandomTile];

  if (SelectedTile == nullptr) {return;}

  if (SelectedTile->Buildings[GetRandomValue(0, 3)] != NoBuildingType) {return;}

  SelectedTile->Buildings[GetRandomValue(0, 3)] = BType;
  AIMarket->Money -= CBBUILDINGS[BType]->MoneyCost;
  if (DEBUGMODE) {  std::cout << "ConductAILogic - End" << "\n";}
}



bool AI_ExpandTile(GameInformation* ET_GMInfo, GameTileGeneric* TileToExpand, Market* ET_AIMarket, std::multimap<TileType, GameTileGeneric*>* ET_TileKnowledgePointer, AIStruct* ET_AIPointer)
{
  if (DEBUGMODE) {  std::cout << "AI_ExpandTile - Start" << "\n";}

  if (TileToExpand->Owner != nullptr) {return false;}

  ET_AIMarket->MarketTiles.push_back(TileToExpand);
  ET_AIMarket->Influence -= INFLUENCEEXPANSIONCOST;
  TileToExpand->Owner = ET_AIMarket;

  //Add tile to buildingtracker
  ET_AIPointer->AIBuildingTileKnowledge.insert({{TileToExpand->Type, TileToExpand}});


  if (DEBUGMODE) {  std::cout << "AI_ExpandTile - Mid" << "\n";}

  if ((TileToExpand->PositionSmall.x) > 0.f)
    {
      GameTileGeneric* LeftTileExpanded =
        &ET_GMInfo->Tiles[(int)TileToExpand->PositionSmall.x - 1][(int)TileToExpand->PositionSmall.y];
      ET_TileKnowledgePointer->insert({{LeftTileExpanded->Type, LeftTileExpanded}});
    }

  if ((TileToExpand->PositionSmall.x) < MAPTILEWIDTH - 1)
    {
      GameTileGeneric* RightTileExpanded =
        &ET_GMInfo->Tiles[(int)TileToExpand->PositionSmall.x + 1][(int)TileToExpand->PositionSmall.y];
      ET_TileKnowledgePointer->insert({{RightTileExpanded->Type, RightTileExpanded}});
    }

  if ((TileToExpand->PositionSmall.y) > 0)
    {
      GameTileGeneric* DownTileExpanded =
        &ET_GMInfo->Tiles[(int)TileToExpand->PositionSmall.x][(int)TileToExpand->PositionSmall.y - 1];
      ET_TileKnowledgePointer->insert({{DownTileExpanded->Type, DownTileExpanded}});
    }

  if ((TileToExpand->PositionSmall.x) < MAPTILEHEIGHT - 1)
    {
      GameTileGeneric* UpTileExpanded =
        &ET_GMInfo->Tiles[(int)TileToExpand->PositionSmall.x][(int)TileToExpand->PositionSmall.y + 1];
      ET_TileKnowledgePointer->insert({{UpTileExpanded->Type, UpTileExpanded}});
    }


  if (DEBUGMODE) {  std::cout << "AI_ExpandTile - End" << "\n";}

  return true;
}


void AI_Expansion(GameInformation* AE_GMInfo, AIStruct* AE_AIPointer, const AIFocus& AE_Focus, Market* AE_AIMarket)
{
  if (DEBUGMODE) {  std::cout << "AI_Expansion - Start" << "\n";}

  std::multimap<TileType, GameTileGeneric*>* TileKnowledgePointer = &AE_AIPointer->AITileKnowledge;

  if (AE_AIMarket->Influence < INFLUENCEEXPANSIONCOST) {return;}

  //Expansion
  //If this is the first time, do the first time expansion
  if (AE_AIMarket->MarketTiles.empty())
    {
      GameTileGeneric* RandomTile = &AE_GMInfo->Tiles[GetRandomValue(0, MAPTILEWIDTH)][GetRandomValue(0, MAPTILEHEIGHT)];

      AI_ExpandTile(AE_GMInfo, RandomTile, AE_AIMarket, TileKnowledgePointer, AE_AIPointer);

      return;
    }

  if (DEBUGMODE) {  std::cout << "AI_Expansion - Mid" << "\n";}

  //Remove any "Occupied" tiles from potential expansion
  auto it = TileKnowledgePointer->begin();
  while (it != TileKnowledgePointer->end())
    {
    if (it->second->Owner != nullptr)
      {
      it = TileKnowledgePointer->erase(it);
      continue;
      }

    it++; 
    }


  if (DEBUGMODE) {  std::cout << "AI_Expansion - Mid2" << "\n";}

  //Based on current focus pick a random tile of terrain-type to expand
  auto Find = TileKnowledgePointer->find(((TileType) AIFOCUSTERRAIN[AE_Focus]));
  bool Found =  (Find == TileKnowledgePointer->end());

  if (DEBUGMODE) {  std::cout << "AI_Expansion - Mid3" << "\n";}

  auto Range = TileKnowledgePointer->equal_range((TileType) AIFOCUSTERRAIN[AE_Focus]);
  if (Range.first == TileKnowledgePointer->end()) {return;} //There are no available tiles of said type

  if (std::distance(Range.first, Range.second) == 0) {return;} //Ditto

  if (DEBUGMODE) {  std::cout << "AI_Expansion - Mid4d" << "\n";}

  std::advance(Range.first, GetRandomValue(0, std::distance(Range.first, Range.second) - 1));
  GameTileGeneric* ChosenTile = Range.first->second;
  AI_ExpandTile(AE_GMInfo, ChosenTile, AE_AIMarket, TileKnowledgePointer, AE_AIPointer);

  TileKnowledgePointer->erase(Range.first);

  if (DEBUGMODE) {  std::cout << "AI_Expansion - End" << "\n";}
}


void AI_Build(GameInformation *BU_GMInfo, Market *BU_AIMarket, AIStruct* BU_AIPointer, AIFocus& BU_Focus)
{
  if (DEBUGMODE) {  std::cout << "AI_Build - Start" << "\n";}

  //1: Check if there is a tile with the correct type
  //2: Check if there is enough money
  //3: Pick a random tile of said type
  //4: Build building based on tile_amount_of_buildings
  //5: If tile_amount_of_buildings is greater than 4 then remove from list

  std::multimap<TileType, GameTileGeneric*>* BuildingTileKnowledgePointer = &BU_AIPointer->AIBuildingTileKnowledge;

  auto Range = BuildingTileKnowledgePointer->equal_range((TileType) AIFOCUSTERRAIN[BU_Focus]);
  if (Range.first == BuildingTileKnowledgePointer->end()) {return;} //There are no available tiles of said type [1]

  int CurrentBuildingSelectedIndex = AIFOCUSBUILDINGS[BU_Focus][GetRandomValue(0, AIFOCUSBUILDINGS[BU_Focus].size() - 1)];
  const Building* SelectedBuilding = CBBUILDINGS[CurrentBuildingSelectedIndex];

  if (BU_AIMarket->Money < SelectedBuilding->MoneyCost) {return;} //The building costs too much [2]

  if (std::distance(Range.first, Range.second) == 0) {return;} //There are no avaliable tiles of said type (making doubly sure) [1]

  std::advance(Range.first, GetRandomValue(0, std::distance(Range.first, Range.second) - 1));
  GameTileGeneric* ChosenTile = Range.first->second; //[3]

  ChosenTile->Buildings[4 - ChosenTile->EmptyBuildSlots] = SelectedBuilding->Type;
  BU_AIMarket->Money -= SelectedBuilding->MoneyCost; //[4]

  if (SelectedBuilding->Type == WinConBuilding) //If AI just built final building then they won
    {
      std::cout << "AI WON, MARKET: " << BU_AIMarket->IndexID << "\n";
      BU_GMInfo->_UIContext.UIElementDisplayTrigger[3] = true;
      BU_GMInfo->_InputInformation.CurrentWinner = BU_AIMarket->IndexID;
      BU_GMInfo->_InputInformation.CurrentPopUp = 1;
      BU_GMInfo->IsPaused = true;

      //BU_GMInfo->EndGame = true;
    }

  ChosenTile->EmptyBuildSlots--;
  if (ChosenTile->EmptyBuildSlots <= 0) {BuildingTileKnowledgePointer->erase(Range.first);} //[5]

  if (DEBUGMODE) {  std::cout << "AI_Build - End" << "\n";}
}


AIFocus AI_DecideAIFocus(GameInformation *GMInfo, Market *AIMarket) //"Brain" of the AI
{
  if (DEBUGMODE) {  std::cout << "AIDecideAIFocus - Start" << "\n";}

  if (AIMarket->Money >= WINCONMONEYCOST) {return Focus_Win;}

  std::vector<float> Distribution = AIPERSONALITIES[AIMarket->IndexID];
  for (int i = 1; i < AIMarket->GoodsBalance.size(); i++)
    {
      Distribution[i] -= AIMarket->GoodsBalance[i]; //If deficit, encourage expansion, if abundance, encourage contraction
    }

  std::random_device RDevice;
  std::mt19937 gen(RDevice());
  std::discrete_distribution<> DDistribution({Distribution[0], Distribution[1], Distribution[2], Distribution[3], Distribution[4]});

  if (DEBUGMODE) {  std::cout << "AIDecideAIFocus - End" << "\n";}

  AIFocus DecidedFocus = (AIFocus) (1 + DDistribution(gen));
  std::cout << DecidedFocus << " : DF" << "\n";

  return (DecidedFocus);
}


void ConductAILogic2(GameInformation *GMInfo, Market *AIMarket)
{
  if (DEBUGMODE) {  std::cout << "ConductAILogic2 - Start" << "\n";}

  AIStruct* AIPointer = &GMInfo->AIContainers[AIMarket->IndexID];

  //Based on amount of goods, probability table decide on focus
  AIFocus Focus = AI_DecideAIFocus(GMInfo, AIMarket);

  //Expands AI territory
  AI_Expansion(GMInfo, AIPointer, Focus, AIMarket);

  //AI Builds buildings
  AI_Build(GMInfo, AIMarket, AIPointer, Focus);

  if (DEBUGMODE) {  std::cout << "ConductAILogic2 - End" << "\n";}
}











































