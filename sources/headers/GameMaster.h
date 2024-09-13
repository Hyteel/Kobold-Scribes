#pragma once

#include "TileStructure.h"
#include "CONSTANTS.h"


struct GameInformation {
  GameTileGeneric Tiles[MAPTILEWIDTH][MAPTILEHEIGHT];

  void InitializeGameInfornamtion();
  void DisplayTileInformation();

  GameTileGeneric* CurrentTile = nullptr;
  GameTileGeneric* OldTile = nullptr;
};

void DrawGame(GameInformation &Info);
void HandleInputs(GameInformation *Info, const Camera2D &Camera);

