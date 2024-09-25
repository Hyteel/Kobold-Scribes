#pragma once

#include "vector"

struct GameTileGeneric; //Forward declaration

enum GoodsType {
  NoGoodsType = 0,
  Wood = 1,
  Ore = 2,
  Grain = 3,
  CannedBread = 4,
};

constexpr int GOODSCOUNT = 5;

struct Market {
  int IndexID = 0.f;
  float Money = 50.f;
  float Influence = 50.f;

  float Goods[GOODSCOUNT] = {0.f,0.f,0.f,0.f,0.f};

  std::vector<GameTileGeneric*> MarketTiles;

  void ConductMarketLogic();
};
