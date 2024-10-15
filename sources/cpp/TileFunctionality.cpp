#include "CONSTANTS.h"
#include "TileStructure.h"
#include <cmath>
#include "raylib.h"


void GameTileGeneric::DrawTile(int Special, std::array<Texture2D, 15>& GameTextures)
{
  Color ColorToDraw = TILECOLORS[Type];
  if (Special == 1)
    {ColorToDraw = TILECOLORS[5];

      DrawRectangle(static_cast<int>(std::floor(Position.x)),
                    static_cast<int>(std::floor(Position.y)), TILESIZE,
                    TILESIZE, ColorToDraw);
    }
  else
    {
      int Index = (Type - 1) * 2;
      if (Owner != nullptr) {Index++;}

      DrawTexture(GameTextures[Index], static_cast<int>(std::floor(Position.x)),
                  static_cast<int>(std::floor(Position.y)), WHITE);
    }

    }





