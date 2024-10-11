#include "LOCALISATION.h"
#include "Buildings.h"
#include "iostream"

const std::string GenerateBuildingDescription(const int BuildingNumber)
{
  std::string DESCRIPTION = LOC_BUILDINGS[CBBUILDINGS[BuildingNumber]->Type] + "\n";

  //std::cout << DESCRIPTION << "\n";

  DESCRIPTION += "Input: ";
  for (int i = 0; i < CBBUILDINGS[BuildingNumber]->InputAmount.size(); i++)
    {
      DESCRIPTION += LOC_GOODS[CBBUILDINGS[BuildingNumber]->InputTypes[i]] + std::to_string(CBBUILDINGS[BuildingNumber]->InputAmount[i]) + " | ";
    }


  DESCRIPTION += (std::string) "\n" + "Output: ";
  for (int i = 0; i < CBBUILDINGS[BuildingNumber]->OutputAmount.size(); i++)
    {
      DESCRIPTION += LOC_GOODS[CBBUILDINGS[BuildingNumber]->OutputTypes[i]] + std::to_string(CBBUILDINGS[BuildingNumber]->OutputAmount[i]) + " | ";
    }

  DESCRIPTION += (std::string) "\n" + "Cost: " + std::to_string(CBBUILDINGS[BuildingNumber]->MoneyCost) + "\n";
  DESCRIPTION += "Money Generation: " + std::to_string(CBBUILDINGS[BuildingNumber]->MoneyGeneration) + "\n";
  DESCRIPTION += "Influence Generation: " + std::to_string(CBBUILDINGS[BuildingNumber]->InfluenceGeneration) + "\n";

  //std::cout << DESCRIPTION << "\n";
  return DESCRIPTION; 
}
