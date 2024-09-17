#pragma once

#include "TileStructure.h"
#include "CONSTANTS.h"
#include "UISystem.h"


struct GameInformation {
  GameTileGeneric Tiles[MAPTILEWIDTH][MAPTILEHEIGHT];
  UIContext _UIContext;

  void InitializeGameInfornamtion();
  void DisplayTileInformation();

  GameTileGeneric* CurrentTile = nullptr;
  GameTileGeneric* OldTile = nullptr;
};

void DrawGame(GameInformation &Info);
void HandleInputs(GameInformation *Info, Camera2D *Camera, const UIInput &_UIInput);

