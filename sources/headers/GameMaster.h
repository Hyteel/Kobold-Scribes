#pragma once

#include "Goods.h"
#include "TileStructure.h"
#include "CONSTANTS.h"
#include "UISystem.h"


struct InputInformation {
  GameTileGeneric* CurrentTile = nullptr;
  int CurrentSelectedBuildingSlot = 0;
};


struct GameInformation {
  GameTileGeneric Tiles[MAPTILEWIDTH][MAPTILEHEIGHT];
  UIContext _UIContext;
  InputInformation _InputInformation;

  Market Markets[MARKETCOUNT];

  void InitializeGameInfornamtion();
  void DisplayTileInformation();
  void ConductGameLogic();
};

void DrawGame(GameInformation &Info);
void HandleInputs(GameInformation *Info, Camera2D *Camera, const UIInput &_UIInput);

