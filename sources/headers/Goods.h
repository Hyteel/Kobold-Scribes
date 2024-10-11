#pragma once
#include "vector"
#include <array>

struct GameTileGeneric; //Forward declaration

enum GoodsType {
  NoGoodsType = 0,
  Wood = 1,
  Ore = 2,
  Grain = 3,
  CannedBread = 4,
};


constexpr int GOODSCOUNT = 5;
constexpr std::array<float, GOODSCOUNT> ZEROBALANCE = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f};

constexpr std::array<float, GOODSCOUNT> GOODSEFFICIENCY = {
    // How drastic a deficit is per goods missing
    0.0f, 2.f, 4.f, 1.f,
    20.f
    };

constexpr std::array<float, GOODSCOUNT> TRADEDGOODSMONEY = { //How much money is generated when a good is traded away
  0.0f, 0.5f, 1.f, 0.5f, 2.5f
};

constexpr std::array<float, GOODSCOUNT> TRADEDGOODSINFLUENCE = { //How much money is generated when a good is traded away
  0.0f, 1.f, 2.f, 1.f, 5.f
};

struct Market {
  int IndexID = 0.f;
  float Money = 50.f;
  float Influence = 50.f;

  float MoneyChange = 0.f;
  float InfluenceChange = 0.f;

  float Goods[GOODSCOUNT] = {0.f,0.f,0.f,0.f,0.f}; //Old
  float GoodsChange[GOODSCOUNT] = {0.f, 0.f, 0.f, 0.f, 0.f}; //Old

  std::array<float, GOODSCOUNT> GoodsBalance = ZEROBALANCE;
  std::array<float, GOODSCOUNT> GoodsBalanceTraded = ZEROBALANCE;
  std::array<float, GOODSCOUNT> GoodsEfficiency = ZEROBALANCE;

  std::vector<GameTileGeneric*> MarketTiles;

  void ConductMarketLogic();
  void ConductMarketLogic2();
  void CalculateGoodsEfficiency();
};
