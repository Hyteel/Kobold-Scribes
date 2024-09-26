#include "Buildings.h"
#include "CONSTANTS.h"
#include "GameMaster.h"
#include "Goods.h"
#include "iostream"
#include "raylib.h"
#include <cmath>
#include "AI.h"

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
                }
            }

  for (int i = 0; i < MARKETCOUNT; i++)
    {
      Markets[i].IndexID = i;
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
  for (int i = 0; i < MarketTiles.size(); i++)
    {
      for (int i2 = 0; i2 < BUILDINGSLOTS; i2++)
        {
          // std::cout << "Logic.cpp # ConductMarketLogic(): " << MaarketTiles[i]->Buildings[i2] << " | i: " << i << " | i2: " << i2 << "\n";
          CBBUILDINGS[MarketTiles[i]->Buildings[i2]]->BuildingTick(this); 
        }
    }
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
    std::cout << "ConductWeekTick-Start" << "\n";
    for (int i = 0; i < MARKETCOUNT; i++)
      {
        Markets[i].InfluenceChange = 0;
        Markets[i].MoneyChange = PASSIVEMONEYINCOME * 7;
        for (int ia = 0; ia < GOODSCOUNT; ia++) {Markets[i].GoodsChange[ia] = 0;}


        Markets[i].ConductMarketLogic();


        if (i != 0) {ConductAILogic(this, &Markets[i]);}
      }
    std::cout << "ConductWeekTick-End" << "\n";
  }




















