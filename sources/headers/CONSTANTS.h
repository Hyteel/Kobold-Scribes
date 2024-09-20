#pragma once
#include "raylib.h"
constexpr int TILESIZE = 32;
constexpr float TILESIZEF = 32.f;

constexpr int TESTTEST = 5;
constexpr int MAPTILEWIDTH = 20;
constexpr int MAPTILEHEIGHT = 20;

constexpr int SCREENWIDTH = 1280; //TILESIZE*MAPTILEWIDTH;
  constexpr int SCREENHEIGHT = 720; //TILESIZE*MAPTILEHEIGHT;

constexpr int FPS = 60;
constexpr int TICKRATE = 60;
constexpr int MARKETCOUNT = 8;


constexpr int BUILDINGSLOTS = 4;


constexpr Color TILECOLORS[6] =
{
  PINK,
  GREEN,
  YELLOW,
  GRAY,
  BROWN,
  WHITE,
};   
