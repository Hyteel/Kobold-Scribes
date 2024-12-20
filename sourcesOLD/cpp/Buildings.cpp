#include "Buildings.h"
#include "iostream"
#include "CONSTANTS.h"
#include "algorithm"

void Building::BuildingTick(Market *MarketToModify) const
{
  if (DEBUGMODE) {  std::cout << "BuildingTick - Start" << "\n";}

  if (MarketToModify == nullptr) {return;}
  if (Type == NoBuildingType) {return;}

  int UniqueInputs = InputTypes.size();
  int UniqueOutputs = OutputTypes.size();


  //std::cout << UniqueInputs << " | " << UniqueOutputs << "\n";


  for (int i = 0; i < UniqueInputs; i++) //Can it afford inputs?
    {
      if (MarketToModify->Goods[InputTypes[i]] - InputAmount[i] < 0) {return;}
    }

  for (int i = 0; i < UniqueInputs; i++)
    {
      //std::cout << "Input: " << InputAmount[i] << "\n";
      MarketToModify->Goods[InputTypes[i]] -= InputAmount[i];
      MarketToModify->GoodsChange[InputTypes[i]] -= InputAmount[i];
    }

  for (int i = 0; i < UniqueOutputs; i++)
    {
      //std::cout << "Output: " << OutputAmount[i] << "\n";
      MarketToModify->Goods[OutputTypes[i]] += OutputAmount[i];
      MarketToModify->GoodsChange[OutputTypes[i]] += OutputAmount[i];
    }

  MarketToModify->Influence += InfluenceGeneration;
  MarketToModify->Money += MoneyGeneration;
  MarketToModify->MoneyChange += MoneyGeneration;
  MarketToModify->InfluenceChange += InfluenceGeneration;

  if (DEBUGMODE) {  std::cout << "BuildingTick - End" << "\n";}
}


void Building::BuildingTick2(Market *MarketToModify) const
{
  if (DEBUGMODE) {  std::cout << "BuildingTick - Start" << "\n";}

  if (MarketToModify == nullptr) {return;}
  if (Type == NoBuildingType) {return;}

  int UniqueInputs = InputTypes.size();
  int UniqueOutputs = OutputTypes.size();

  float Efficiency = 1.f;

  for (int i = 0; i < UniqueInputs; i++) //Calculate efficiency
    {
      Efficiency += MarketToModify->GoodsEfficiency[InputTypes[i]];
    }

  Efficiency = std::clamp(Efficiency, 0.0f, 1.0f);

  for (int i = 0; i < UniqueInputs; i++)
    {
      MarketToModify->GoodsBalance[InputTypes[i]] -= InputAmount[i];
    }

  for (int i = 0; i < UniqueOutputs; i++)
    {
      MarketToModify->GoodsBalance[OutputTypes[i]] += OutputAmount[i] * Efficiency;
    }

  MarketToModify->Influence += InfluenceGeneration * Efficiency;
  MarketToModify->Money += MoneyGeneration * Efficiency;
  MarketToModify->MoneyChange += MoneyGeneration * Efficiency;
  MarketToModify->InfluenceChange += InfluenceGeneration * Efficiency;

  if (DEBUGMODE) {  std::cout << "BuildingTick - End" << "\n";}
}


