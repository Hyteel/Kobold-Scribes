#pragma once

#include "CONSTANTS.h"
#include "raylib.h"
#include "Buildings.h"

enum TileType {
  Debug = 0, //*-CHECKOUT-*
  Forest = 1,
  Field = 2,
  Mountain = 3,
  City = 4,
  Selected = 5, //Deprecated? *-CHECKOUT-*
};

constexpr bool ALLOWED_BUILDINGS_PER_TILETYPE[] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1,
};


struct GameTileGeneric {
  int ID = 0;
  TileType Type = Debug;
  Market *Owner = nullptr;

  int Value = 0;
  int EmptyBuildSlots = 4;

  Vector2 Position = {};
  Vector2 PositionSmall = {};

  BuildingType Buildings[BUILDINGSLOTS] = {NoBuildingType, NoBuildingType, NoBuildingType, NoBuildingType};

  void DrawTile(int Special);
};
