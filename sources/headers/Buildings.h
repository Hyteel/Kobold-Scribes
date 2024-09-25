#pragma once
#include "Goods.h"
#include "vector"

enum BuildingType {
  NoBuildingType = 0,
  Lumberyard = 1,
  Mine = 2,
  Farm = 3,
  Cannery = 4,
  BasicResidence = 5,
  MediumResidence = 6,
  LuxuryResidence = 7,
  WinConBuilding = 8,
};


struct Building {
  BuildingType Type;
  std::vector<GoodsType> InputTypes;
  std::vector<GoodsType> OutputTypes;
  std::vector<float> InputAmount;
  std::vector<float> OutputAmount;

  float InfluenceGeneration;
  float MoneyGeneration;

  float MoneyCost;

  void BuildingTick(Market *MarketToModify) const;
};


// Building definitions
const Building CBEmpty
  { // ConstantBuildingEmpty
  NoBuildingType,
  std::vector<GoodsType>{},
  std::vector<GoodsType>{},
  std::vector<float>{},
  std::vector<float>{},
  0.f,
  0.f,
  0.f
  };

const Building CBLumberyard
  { // ConstantBuildingLumberyard
  Lumberyard,
  std::vector<GoodsType>{},
  std::vector<GoodsType>{Wood},
  std::vector<float>{},
  std::vector<float>{5.f},
  1.f,
  0.5f,
  10.f,
  };

const Building CBMine
  { // ConstantBuildingMine
  Mine,
  std::vector<GoodsType>{},
  std::vector<GoodsType>{Ore},
  std::vector<float>{},
  std::vector<float>{2.f},
  1.f,
  0.5f,
  20.f
  };

const Building CBFarm
  { // ConstantBuildingFarm
  Farm,
  std::vector<GoodsType>{},
  std::vector<GoodsType>{Grain},
  std::vector<float>{},
  std::vector<float>{10.f},
  0.5f,
  0.5f,
  10.f
  };

const Building CBCannery
  { // ConstantBuildingCannery
  Cannery,
  std::vector<GoodsType>{Ore, Wood, Grain},
  std::vector<GoodsType>{CannedBread},
  std::vector<float>{5.f, 5.f, 5.f},
  std::vector<float>{1.f},
  5.f,
  1.f,
  35.f
  };

const Building CBBasicResidence
  {
  BasicResidence,
  std::vector<GoodsType>{},
  std::vector<GoodsType>{},
  std::vector<float>{},
  std::vector<float>{},
  0.f,
  2.f,
  5.f
  };

const Building CBMediumResidence
  {
  MediumResidence,
  std::vector<GoodsType>{Wood, Grain},
  std::vector<GoodsType>{},
  std::vector<float>{2.f, 2.f},
  std::vector<float>{},
  1.f,
  5.f,
  15.f
  };

const Building CBLuxuryResidence
  {
  LuxuryResidence,
  std::vector<GoodsType>{CannedBread, Wood},
  std::vector<GoodsType>{},
  std::vector<float>{5.f, 2.f},
  std::vector<float>{},
  3.f,
  15.f,
  40.f
  };

const Building CBWinCon
  {
    WinConBuilding,
    std::vector<GoodsType>{},
    std::vector<GoodsType>{},
    std::vector<float>{},
    std::vector<float>{},
    0.f,
    0.f,
    500.f
  };


constexpr const Building* CBBUILDINGS[] = {&CBEmpty, &CBLumberyard, &CBMine, &CBFarm, &CBCannery, &CBBasicResidence, &CBMediumResidence, &CBLuxuryResidence, &CBWinCon};




