#pragma once
#include "TileStructure.h"
#include "CONSTANTS.h"


struct GameInformation {
  GameTileGeneric Tiles[MAPTILEWIDTH][MAPTILEHEIGHT];

  void InitializeGameInfornamtion();
  void DisplayTileInformation();
};

