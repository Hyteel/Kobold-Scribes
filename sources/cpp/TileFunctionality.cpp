#include "CONSTANTS.h"
#include "TileStructure.h"
#include <cmath>
#include "raylib.h"


void GameTileGeneric::DrawTile(int Special)
{
  Color ColorToDraw = TILECOLORS[Type];
  if (Special == 1)
    {ColorToDraw = TILECOLORS[5]; }

      DrawRectangle(static_cast<int>(std::floor(Position.x)),
                    static_cast<int>(std::floor(Position.y)), TILESIZE,
                    TILESIZE, ColorToDraw);
    }





