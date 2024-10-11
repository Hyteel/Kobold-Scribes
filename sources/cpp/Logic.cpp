#include "Buildings.h"
#include "CONSTANTS.h"
#include "GameMaster.h"
#include "Goods.h"
#include "LOCALISATION.h"
#include "iostream"
#include "raylib.h"
#include <cmath>
#include <cstdlib>
#include "AI.h"

std::vector<std::string> LOC_BUILDINGDESCRIPTION;

void GameInformation::InitializeGameInfornamtion()
{
  for (int iw = 0; iw < MAPTILEWIDTH; iw++)
            {
              for (int ih = 0; ih < MAPTILEHEIGHT; ih++)
                {
                  GameTileGeneric* CurrentTile = &Tiles[iw][ih];
                  CurrentTile->ID = ih + iw*MAPTILEHEIGHT;
                  CurrentTile->Type = TileType(GetRandomValue(1, 4));
                  CurrentTile->Position = Vector2{static_cast<float>(iw)*TILESIZEF, static_cast<float>(ih)*TILESIZEF};
                  CurrentTile->PositionSmall = Vector2{(float) iw,(float) ih};
                }
            }

  for (int i = 0; i < MARKETCOUNT; i++)
    {
      Markets[i].IndexID = i;
    }

  LOC_BUILDINGDESCRIPTION.push_back("DEBUG");

  for (int i = 1; i < 8; i++)
    {
      LOC_BUILDINGDESCRIPTION.push_back(GenerateBuildingDescription(i));
    }
}


void GameInformation::DisplayTileInformation()
{
  for (int iw = 0; iw < MAPTILEWIDTH; iw++)
    {
      for (int ih = 0; ih < MAPTILEHEIGHT; ih++)
        {
          std::cout << "Tile: " << iw << " | " << ih << " || ID: " << Tiles[iw][ih].ID << "\n"; 
        }
    }
}


void Market::ConductMarketLogic()
{
  if (DEBUGMODE) {  std::cout << "ConductMarketLogic - Start" << "\n";}

  for (int i = 0; i < MarketTiles.size(); i++)
    {
      for (int i2 = 0; i2 < BUILDINGSLOTS; i2++)
        {
          CBBUILDINGS[MarketTiles[i]->Buildings[i2]]->BuildingTick(this); 
        }
    }

  if (DEBUGMODE) {  std::cout << "ConductMarketLogic - End" << "\n";}
}

void Market::ConductMarketLogic2()
{
  if (DEBUGMODE) {  std::cout << "ConductMarketLogic2 - Start" << "\n";}

  for (int i = 0; i < MarketTiles.size(); i++)
    {
      for (int i2 = 0; i2 < BUILDINGSLOTS; i2++)
        {
          if (DEBUGMODE) {  std::cout << "CM2 Building : " << i << " | " << i2 << " | " << CBBUILDINGS[MarketTiles[i]->ID] << "\n";}

          CBBUILDINGS[MarketTiles[i]->Buildings[i2]]->BuildingTick2(this);
        }
    }

  if (DEBUGMODE) {  std::cout << "ConductMarketLogic2 - End" << "\n";}
}



void GameInformation::ConductDayTick()
    {
      for (int i = 0; i < MARKETCOUNT; i++)
        {
          Markets[i].Money += PASSIVEMONEYINCOME;
        }
    }


void GameInformation::ConductWeekTick()
  {
    if (DEBUGMODE) {  std::cout << "ConductWeekTick - Start" << "\n";}

    for (int i = 0; i < MARKETCOUNT; i++)
      {
        Markets[i].InfluenceChange = 0;
        Markets[i].MoneyChange = PASSIVEMONEYINCOME * 7;
        for (int ia = 0; ia < GOODSCOUNT; ia++) {Markets[i].GoodsChange[ia] = 0;}


        Markets[i].ConductMarketLogic();


        if (i != 0) {ConductAILogic(this, &Markets[i]);}
      }

    if (DEBUGMODE) {  std::cout << "ConductWeekTick - End" << "\n";}
  }


void GameInformation::ConductWeekTick2()
{
  if (DEBUGMODE) {  std::cout << "ConductWeekTick2 - Start" << "\n";}

  //Goods - Economy
  for (int i = 0; i < MARKETCOUNT; i++)
    {
      Markets[i].InfluenceChange = 0;
      Markets[i].MoneyChange = PASSIVEMONEYINCOME*7;

      for (int ig = 1; ig < GOODSCOUNT; ig++)
        {
          Markets[i].GoodsEfficiency[ig] = ((Markets[i].GoodsBalance[ig] + Markets[i].GoodsBalanceTraded[ig]) * GOODSEFFICIENCY[ig]) / 100.f;
        }

      Markets[i].GoodsBalance = ZEROBALANCE;
      Markets[i].GoodsBalanceTraded = ZEROBALANCE;

      Markets[i].ConductMarketLogic2();
    }


  if (DEBUGMODE) {  std::cout << "ConductWeekTick2 - Trade" << "\n";}

  //Trade
  std::array<std::vector<std::pair<Market*, float>>, GOODSCOUNT> GoodsConsumptionVector;
  std::array<std::vector<std::pair<Market*, float>>, GOODSCOUNT> GoodsProductionVector;

  for (int i = 0; i < MARKETCOUNT; i++)
    {
      for (int ig = 0; ig < GOODSCOUNT; ig++)
        {
          if (Markets[i].GoodsBalance[ig] < 0) {GoodsConsumptionVector[ig].push_back({&Markets[i], Markets[i].GoodsBalance[ig]}); }
          else if (Markets[i].GoodsBalance[ig] > 0) {GoodsProductionVector[ig].push_back({&Markets[i], Markets[i].GoodsBalance[ig]}); }
        }
    }


  if (DEBUGMODE) {  std::cout << "ConductWeekTick2 - Trade Populating" << "\n";}


  for (int i = 0; i < GOODSCOUNT; i++)
    {
      for (int ipc = 0; ipc < GoodsConsumptionVector[i].size(); ipc++)
        {
          if (GoodsConsumptionVector[i].empty()) {continue;} //No one going negative in said good

          std::pair<Market*, float>* CurrentConsumptionPair = &GoodsConsumptionVector[i][ipc];
          for (int ipp = 0; ipp < GoodsProductionVector[i].size(); ipp++)
            {
              if (GoodsProductionVector[i].empty()) {continue;} //No one going positive in said good


              std::pair<Market*, float>* CurrentProductionPair = &GoodsProductionVector[i][ipp];

              if (CurrentProductionPair->second == 0) {continue;}
              if (CurrentConsumptionPair->second == 0) {continue;}

              if (std::abs(CurrentProductionPair->second) >= std::abs(CurrentConsumptionPair->second))
                {
                  CurrentConsumptionPair->first->GoodsBalanceTraded[i] += CurrentConsumptionPair->second;
                  CurrentProductionPair->first->GoodsBalanceTraded[i] += CurrentConsumptionPair->second * -1.f;
                  CurrentProductionPair->second += CurrentConsumptionPair->second;


                  CurrentProductionPair->first->Influence += TRADEDGOODSINFLUENCE[i] * CurrentConsumptionPair->second * -1.f;
                  CurrentProductionPair->first->InfluenceChange += TRADEDGOODSINFLUENCE[i] * CurrentConsumptionPair->second * -1.f;
                  CurrentProductionPair->first->Money += TRADEDGOODSINFLUENCE[i] * CurrentConsumptionPair->second * -1.f;
                  CurrentProductionPair->first->MoneyChange += TRADEDGOODSINFLUENCE[i] * CurrentConsumptionPair->second * -1.f;

                  CurrentConsumptionPair->second = 0.f;

                  break;
                }
              else
                {
                  CurrentConsumptionPair->first->GoodsBalanceTraded[i] = CurrentConsumptionPair->second + CurrentProductionPair->second;
                  CurrentProductionPair->first->GoodsBalanceTraded[i] = 0.f;

                  CurrentProductionPair->first->Influence += TRADEDGOODSINFLUENCE[i] * CurrentConsumptionPair->second * 1.f;
                  CurrentProductionPair->first->InfluenceChange += TRADEDGOODSINFLUENCE[i] * CurrentConsumptionPair->second * 1.f;
                  CurrentProductionPair->first->Money += TRADEDGOODSINFLUENCE[i] * CurrentConsumptionPair->second * 1.f;
                  CurrentProductionPair->first->MoneyChange += TRADEDGOODSINFLUENCE[i] * CurrentConsumptionPair->second * 1.f;

                  CurrentProductionPair->second = 0;
                }
            }
        }
   }

  if (DEBUGMODE) {  std::cout << "ConductWeekTick2 - AILogic" << "\n";}

  for (int i = 1; i < 8; i++)
    {
      ConductAILogic2(this, &Markets[i]);
    }


  if (DEBUGMODE) {  std::cout << "ConductWeekTick2 - End" << "\n";}
}

















