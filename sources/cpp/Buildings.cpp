#include "Buildings.h"
#include "iostream"

void Building::BuildingTick(Market *MarketToModify) const
{
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
}
