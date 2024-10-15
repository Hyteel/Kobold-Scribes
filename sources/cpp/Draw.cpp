#include "CONSTANTS.h"
#include "GameMaster.h"
#include "raylib.h"


void DrawGame(GameInformation &Info, std::array<Texture2D, 15>& GameTextures)
{
  for (int iw = 0; iw < MAPTILEWIDTH; iw++)
    {
    for (int ih = 0; ih < MAPTILEHEIGHT; ih++)
      {
        Info.Tiles[iw][ih].DrawTile(0, GameTextures);
      }
    }

  if (Info._InputInformation.CurrentTile != nullptr)
    {
      Info._InputInformation.CurrentTile->DrawTile(1, GameTextures);
    }

  for (int i = 0; i < MARKETCOUNT; i++)
    {
      for (int it = 0; it < Info.Markets[i].MarketTiles.size(); it++)
        {
          Vector2* Position = &Info.Markets[i].MarketTiles[it]->Position; 
          DrawLineEx((Vector2) {Position->x, Position->y}, (Vector2) {Position->x + TILESIZE,  Position->y}, 3.f, MARKETCOLORS[i]);
          DrawLineEx((Vector2) {Position->x + TILESIZE, Position->y}, (Vector2) {Position->x + TILESIZE, Position->y + TILESIZE}, 3.f, MARKETCOLORS[i]);

          DrawLineEx((Vector2) {Position->x + TILESIZE, Position->y + TILESIZE}, (Vector2) {Position->x, Position->y + TILESIZE}, 3.f, MARKETCOLORS[i]);

          DrawLineEx((Vector2) {Position->x, Position->y + TILESIZE}, (Vector2) {Position->x, Position->y}, 3.f, MARKETCOLORS[i]);
        }
    }
}
