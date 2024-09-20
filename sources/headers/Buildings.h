#pragma once
#include "Goods.h"
#include "vector"

enum BuildingType {
  NoBuildingType = 0,
  Lumberyard = 1,
  Mine = 2,
  Farm = 3,
  Cannery = 4
};


struct Building {
  BuildingType Type;
  std::vector<GoodsType> InputTypes;
  std::vector<GoodsType> OutputTypes;
  std::vector<float> InputAmount;
  std::vector<float> OutputAmount;

  void BuildingTick(Market *MarketToModify) const;
};


// Building definitions
const Building CBLumberyard{ // ConstantBuildingLumberyard
    Lumberyard,
    std::vector<GoodsType>{},
    std::vector<GoodsType>{Wood},
    std::vector<float>{},
    std::vector<float>{5.f}};

const Building CBMine{ // ConstantBuildingMine
  Mine,
  std::vector<GoodsType>{},
  std::vector<GoodsType>{Ore},
  std::vector<float>{},
  std::vector<float>{2.f}};

const Building CBFarm{ // ConstantBuildingFarm
  Farm,
  std::vector<GoodsType>{},
  std::vector<GoodsType>{Grain},
  std::vector<float>{},
  std::vector<float>{10.f}};

const Building CBCannery{ // ConstantBuildingCannery
  Cannery,
  std::vector<GoodsType>{Ore, Wood, Grain},
  std::vector<GoodsType>{CannedBread},
  std::vector<float>{5.f, 5.f, 5.f},
  std::vector<float>{1.f}};

constexpr const Building* CBBUILDINGS[] = {&CBLumberyard, &CBMine, &CBFarm, &CBCannery};




