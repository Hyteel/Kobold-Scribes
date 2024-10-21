#include "Buildings.h"
#include "CONSTANTS.h"
#include "TileStructure.h"
#include <cmath>
#include "raylib.h"
#include "GameMaster.h"
#include <algorithm>


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



void GameTileGeneric::UpdatePopulation()
{
  for (int i = 0; i < MAXTILEBUILDINGSLOTS; ++i)
    {
      Population += CBBUILDINGS[Buildings[i]]->InfluenceGeneration;
      UnlockedBuildSlots = std::clamp((int) std::round(Population / POPULATIONNEWHOUSEBREAKPOINT), STARTINGTILEBUILDSLOTS, MAXTILEBUILDINGSLOTS);
    }
}


void InfluenceTile (const int& IT_MarketIndex, GameInformation* IT_GMInfo, const int& PosX, const int& PosY, const int& InfluenceAmount)
{
  GameTileGeneric* TileToInfluence = &IT_GMInfo->Tiles[PosX][PosY];
  if (TileToInfluence->IsOwned) {return;} //Already owned by someone

  TileToInfluence->MarketInfluences[IT_MarketIndex] += InfluenceAmount;
}


void GameTileGeneric::SpreadInfluence(GameInformation* SI_GMInfo)
{
  int MarketIndex = Owner->IndexID;
  float InfluenceGenerated = Population * POPULATIONINFLUENCEGENERATION;

  if (PositionSmall.x > 0.0f)
    {
      int LeftPosition = ((int) PositionSmall.x) - 1;
      InfluenceTile(MarketIndex, SI_GMInfo, LeftPosition, (int) PositionSmall.y, InfluenceGenerated);
    }

  if (PositionSmall.x < (MAPTILEWIDTH - 1))
    {
      int RightPosition = ((int) PositionSmall.x) + 1;
      InfluenceTile(MarketIndex, SI_GMInfo, RightPosition, (int) PositionSmall.y, InfluenceGenerated);
    }

  if (PositionSmall.y > 0.0f)
    {
      int UpPosition = ((int) PositionSmall.y) - 1;
      InfluenceTile(MarketIndex, SI_GMInfo, (int) PositionSmall.x, UpPosition, InfluenceGenerated);
    }

  if (PositionSmall.y < (MAPTILEHEIGHT - 1))
    {
      int DownPosition = ((int) PositionSmall.y) + 1;
      InfluenceTile(MarketIndex, SI_GMInfo, (int) PositionSmall.x, DownPosition, InfluenceGenerated);
    }
}
