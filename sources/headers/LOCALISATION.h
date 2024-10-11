#pragma once
#include <string>
#include "vector"

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

const std::string LOC_TERRAIN[5] = {
  "Debug",
  "Forest",
  "Field",
  "Mountain",
  "City"
};

//Building Descriptions
const std::string GenerateBuildingDescription(const int BuildingNumber);

extern std::vector<std::string> LOC_BUILDINGDESCRIPTION;



