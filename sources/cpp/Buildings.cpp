#include "Buildings.h"

void Building::BuildingTick(Market *MarketToModify) const
{
  if (Type == NoBuildingType) {return;}

  int UniqueInputs = InputTypes.size();
  int UniqueOutputs = OutputTypes.size();

  for (int i = 0; i < UniqueInputs; i++)
    {
      MarketToModify->Goods[i] -= InputAmount[i];
    }

  for (int i = 0; i < UniqueOutputs; i++)
    {
      MarketToModify->Goods[i] -= OutputAmount[i];
    }
}
