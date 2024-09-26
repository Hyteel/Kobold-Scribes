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

  bool EndGame = false;

  //Iteration 1 of date system
  int DayCounter = 0;
  int WeekCounter = 0;
  //

  Market Markets[MARKETCOUNT];

  void InitializeGameInfornamtion();
  void DisplayTileInformation();
  void ConductDayTick();
  void ConductWeekTick();
};

void DrawGame(GameInformation &Info);
void HandleInputs(GameInformation *Info, Camera2D *Camera, const UIInput &_UIInput);

