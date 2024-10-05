#include "AI.h"
#include "Buildings.h"
#include "CONSTANTS.h"
#include "TileStructure.h"
#include "raylib.h"
#include "iostream"


void ConductAILogic(GameInformation *GMInfo, Market *AIMarket)
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
