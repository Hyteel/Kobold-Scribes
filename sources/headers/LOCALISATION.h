#pragma once
#include <string>

const std::string LOC_BUILDINGS[9] = {
  "Empty",
  "Lumberyard",
  "Mine",
  "Farm",
  "Cannery",
  "Basic Residence",
  "Medium Residence",
  "Luxury Residence",
  "WinCon Building"
};

const std::string LOC_GOODS[5] = {
  "Empty",
  "Wood: ",
  "Ore: ",
  "Grain: ",
  "Canned Bread: "
};

//Building Descriptions
const std::string GenerateBuildingDescription(const int BuildingNumber);

const std::string LOC_BUILDINGDESCRIPTION[9] = {
  "Empty",
  GenerateBuildingDescription(1),
  GenerateBuildingDescription(2),
  GenerateBuildingDescription(3),
  GenerateBuildingDescription(4),
  GenerateBuildingDescription(5),
  GenerateBuildingDescription(6),
  GenerateBuildingDescription(7),
  GenerateBuildingDescription(8),
};
