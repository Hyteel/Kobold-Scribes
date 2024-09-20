#include "Buildings.h"
#include "CONSTANTS.h"
#include "GameMaster.h"
#include "iostream"
#include "raylib.h"
#include <cmath>

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
          CBBUILDINGS[MarketTiles[i]->Buildings[i2]]->BuildingTick(this); 
        }
    }
}




void GameInformation::ConductGameLogic()
{
  for (int i = 0; i < MARKETCOUNT; i++)
    {
      Markets[i].ConductMarketLogic();
    }
}





















