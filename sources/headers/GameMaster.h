#pragma once

#include "AI.h"
#include "Goods.h"
#include "TileStructure.h"
#include "CONSTANTS.h"
#include "UISystem.h"


struct InputInformation {
  GameTileGeneric* CurrentTile = nullptr;
  int CurrentSelectedBuildingSlot = 0;
  int CurrentPopUp = 0;
  int CurrentWinner = 0;
};


struct GameInformation {
  GameTileGeneric Tiles[MAPTILEWIDTH][MAPTILEHEIGHT];
  UIContext _UIContext;
  InputInformation _InputInformation;

  bool EndGame = false;
  bool IsPaused = true;
  bool HasPlacedFirstTile = false;

  //Iteration 1 of date system
  int DayCounter = 0;
  int WeekCounter = 0;
  //

  Market Markets[MARKETCOUNT];
  AIStruct AIContainers[MARKETCOUNT];

  void InitializeGameInfornamtion();
  void DisplayTileInformation();
  void ConductDayTick();
  void ConductWeekTick();

  void ConductWeekTick2();
};

void DrawGame(GameInformation &Info, std::array<Texture2D, 15>& GameTextures);
void HandleInputs(GameInformation *Info, Camera2D *Camera, const UIInput &_UIInput);

