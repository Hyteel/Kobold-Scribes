#pragma once
#include "raylib.h"
constexpr bool DEBUGMODE = true;

constexpr int TILESIZE = 32;
constexpr float TILESIZEF = 32.f;

constexpr int TESTTEST = 5;
constexpr int MAPTILEWIDTH = 20;
constexpr int MAPTILEHEIGHT = 20;

constexpr int SCREENWIDTH = 1280; //TILESIZE*MAPTILEWIDTH;
constexpr int SCREENHEIGHT = 720; //TILESIZE*MAPTILEHEIGHT;

constexpr int FPS = 60;
constexpr int TICKRATE = 40;
constexpr int MARKETCOUNT = 8;


constexpr float INFLUENCEEXPANSIONCOST = 25.f;
constexpr float PASSIVEMONEYINCOME = 1.f;
constexpr float WINCONMONEYCOST = 3000.f;

constexpr int BUILDINGSLOTS = 4;

constexpr Color TILECOLORS[6] =
{
  CLITERAL(Color) {255, 109, 194, 255}, //PINK
  CLITERAL(Color) {0, 228, 48, 255}, //GREEN
  CLITERAL(Color) {253, 249, 0, 255}, //YELLOW
  CLITERAL(Color) {130, 130, 130, 255}, //GRAY
  CLITERAL(Color) {127, 106, 79, 255}, //BROWN
  CLITERAL(Color) {225, 225, 225, 255}, //WHITE
};

constexpr Color MARKETCOLORS[MARKETCOUNT] = 
  {
    CLITERAL(Color) {255 - 30, 109 - 30, 194 - 30, 255}, //PINK
    CLITERAL(Color) {0, 228 - 30, 48 - 30, 255}, //GREEN
    CLITERAL(Color) {253 - 30, 249 - 30, 0, 255}, //YELLOW
    CLITERAL(Color) {130 - 30, 130 - 30, 130 - 30, 255}, //GRAY
    CLITERAL(Color) {127 - 30, 106 - 30, 79 - 30, 255}, //BROWN
    CLITERAL(Color) {225 - 30, 225 - 30, 225 - 30, 255}, //WHITE
    PURPLE,
    RED
  };
