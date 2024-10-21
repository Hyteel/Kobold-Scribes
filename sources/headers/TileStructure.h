#pragma once

#include "CONSTANTS.h"
#include "raylib.h"
#include "Buildings.h"

enum TileType {
  Debug = 0, //X-CHECKOUT-X
  Forest = 1,
  Field = 2,
  Mountain = 3,
  City = 4,
  Selected = 5, //Deprecated? X-CHECKOUT-X
};

constexpr bool ALLOWED_BUILDINGS_PER_TILETYPE[] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1,
};

struct GameInformation; //Forward declaration

struct GameTileGeneric {
  int ID = 0;
  TileType Type = Debug;
  Market *Owner = nullptr; //X-CHECKOUT-X Move all ownership checks to IsOwned
  bool IsOwned = false;
  bool IsCapital = false;

  int Value = 0;
  int EmptyBuildSlots = MAXTILEBUILDINGSLOTS;
  int UnlockedBuildSlots = STARTINGTILEBUILDSLOTS;
 
  std::array<float, MARKETCOUNT> MarketInfluences = {0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f};

  float Population = 0.f;

  Vector2 Position = {}; //X-CHECKOUT-X
  Vector2 PositionSmall = {};

  BuildingType Buildings[MAXTILEBUILDINGSLOTS] = {NoBuildingType, NoBuildingType, NoBuildingType, NoBuildingType, NoBuildingType, NoBuildingType, NoBuildingType, NoBuildingType};

  void UpdatePopulation();
  void SpreadInfluence(GameInformation* SI_GMInfo);
  void DrawTile(int Special, std::array<Texture2D, 15>& GameTextures);
};
