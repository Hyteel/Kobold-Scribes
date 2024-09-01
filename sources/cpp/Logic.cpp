#include "GameMaster.h"
#include "iostream"

void GameInformation::InitializeGameInfornamtion()
{
  for (int iw = 0; iw < MAPTILEWIDTH; iw++)
            {
              for (int ih = 0; ih < MAPTILEHEIGHT; ih++)
                {
                  Tiles[iw][ih].ID = ih + iw*MAPTILEHEIGHT;
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
