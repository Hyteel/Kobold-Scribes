#pragma once

#include "CONSTANTS.h"
#include "raylib.h"
#include "Buildings.h"

enum TileType {
  Debug = 0,
  Forest = 1,
  Field = 2,
  Mountain = 3,
  City = 4,
  Selected = 5,
};


struct GameTileGeneric {
  int ID = 0;
  TileType Type = Debug;

  int Value = 0;

  Vector2 Position = {};

  BuildingType Buildings[BUILDINGSLOTS] = {NoBuildingType, NoBuildingType, NoBuildingType, NoBuildingType};

  void DrawTile(int Special);
};
