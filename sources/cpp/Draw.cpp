#include "CONSTANTS.h"
#include "GameMaster.h"
#include "raylib.h"


void DrawGame(GameInformation &Info)
{
  for (int iw = 0; iw < MAPTILEWIDTH; iw++)
    {
    for (int ih = 0; ih < MAPTILEHEIGHT; ih++)
      {
        Info.Tiles[iw][ih].DrawTile(0);
      }
    }

  if (Info._InputInformation.CurrentTile != nullptr)
    {
      Info._InputInformation.CurrentTile->DrawTile(1);
    }

  for (int i = 0; i < MARKETCOUNT; i++)
    {
      for (int it = 0; it < Info.Markets[i].MarketTiles.size(); it++)
        {
          Vector2* Position = &Info.Markets[i].MarketTiles[it]->Position; 
          DrawLine(Position->x, Position->y, Position->x + TILESIZE, Position->y, MARKETCOLORS[i]);
          DrawLine(Position->x + TILESIZE, Position->y, Position->x + TILESIZE, Position->y + TILESIZE, MARKETCOLORS[i]);

          DrawLine(Position->x + TILESIZE, Position->y + TILESIZE, Position->x, Position->y + TILESIZE, MARKETCOLORS[i]);

          DrawLine(Position->x, Position->y + TILESIZE, Position->x, Position->y, MARKETCOLORS[i]);
        }
    }
}
