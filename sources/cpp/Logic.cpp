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


void HandleInputs(GameInformation *Info, const Camera2D &Camera)
{
  Vector2 MousePosition = GetScreenToWorld2D(GetMousePosition(), Camera);

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    int MouseTileX = std::floor(MousePosition.x / TILESIZEF);
    int MouseTileY = std::floor(MousePosition.y / TILESIZEF);

    Info->CurrentTile = &Info->Tiles[MouseTileX][MouseTileY];
  }
}


















