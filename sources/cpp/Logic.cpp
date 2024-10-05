#include "Buildings.h"
#include "CONSTANTS.h"
#include "GameMaster.h"
#include "Goods.h"
#include "LOCALISATION.h"
#include "iostream"
#include "raylib.h"
#include <cmath>
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

    if (DEBUGMODE) {  std::cout << "HandleInputs - End" << "\n";}
  }




















