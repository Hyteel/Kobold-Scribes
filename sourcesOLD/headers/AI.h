#pragma once
#include "TileStructure.h"
#include <map>

struct GameInformation;
struct Market;

enum AIFocus {
  Focus_Win = 0,
  Focus_Residence = 1,
  Focus_Wood = 2,
  Focus_Ore = 3,
  Focus_Grain = 4,
  Focus_CannedBread = 5,
};

const std::array<std::vector<float>, 8> AIPERSONALITIES = {
  std::vector<float>{5, 1, 1, 1, 1}, //Standard personality
  std::vector<float>{5, 1, 1, 1, 1},
  std::vector<float>{5, 10, 1, 1, 1}, //Wood focused
  std::vector<float>{5, 1, 10, 1, 1}, //Ore focused
  std::vector<float>{5, 1, 1, 10, 1}, //Grain focused
  std::vector<float>{5, 1, 1, 1, 10}, //Bread focused
  std::vector<float>{1, 5, 5, 5, 1}, //Resource focused
  std::vector<float>{2, 2, 2, 2, 2} //Evenly focused
};

constexpr std::array<int, 6> AIFOCUSTERRAIN = {4, 4, 1, 3, 2, 4}; //What terrain index does each focus have?

const std::array<std::vector<int>, 6> AIFOCUSBUILDINGS = //Which building indices does each focus have?
  {
    std::vector<int>{8},
    std::vector<int>{5, 6, 7},
    std::vector<int>{1},
    std::vector<int>{2},
    std::vector<int>{3},
    std::vector<int>{4}
  };



void ConductAILogic(GameInformation *GMInfo, Market *AIMarket);
void ConductAILogic2(GameInformation *GMInfo, Market *AIMarket);


struct AIStruct {
  std::multimap<TileType, GameTileGeneric*> AITileKnowledge;
  std::multimap<TileType, GameTileGeneric*> AIBuildingTileKnowledge;
  };
