#include "Buildings.h"
#include "iostream"

void Building::BuildingTick(Market *MarketToModify) const
{
  //std::cout << Type << "\n";

  if (Type == NoBuildingType) {return;}

  int UniqueInputs = InputTypes.size();
  int UniqueOutputs = OutputTypes.size();


  std::cout << UniqueInputs << " | " << UniqueOutputs << "\n";

  for (int i = 0; i < UniqueInputs; i++)
    {
      std::cout << "Input: " << InputAmount[i] << "\n";
      MarketToModify->Goods[InputTypes[i]] -= InputAmount[i];
    }

  for (int i = 0; i < UniqueOutputs; i++)
    {
      std::cout << "Output: " << OutputAmount[i] << "\n";
      MarketToModify->Goods[OutputTypes[i]] += OutputAmount[i];
    }
}
