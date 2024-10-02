#pragma once
#include "raylib.h"
#include <string>
#include <vector>
#include "vector"

enum UIInput {
  Null,
  NonButton,
  Tile_Slot1,
  Tile_Slot2,
  Tile_Slot3,
  Tile_Slot4,
  Tile_Slot5,
  Building_Slot1,
  Building_Slot2,
  Building_Slot3,
  Building_Slot4,
  Building_Slot5,
  Building_Slot6,
  Building_Slot7,
  Building_Slot8
};


struct GameInformation; //Forward Declaration

UIInput HandleUI(const GameInformation &GMInfo);

std::string TruncateFloatForDisplay(float FloatToTruncate);

struct UIElement {
  Rectangle Bounds;
  std::string DisplayText;
  std::vector<Rectangle> Buttons = {};
  std::vector<std::string> ButtonText = {};
  std::vector<UIInput> ButtonResponse = {};
  std::vector<Rectangle> TextFields = {};
  std::vector<std::string> Text = {};
};


struct UIContext {
  std::vector<UIElement> UIElements;
  std::vector<bool> UIElementDisplayTrigger;

  void InitializeUIContext(const GameInformation &GMInfo);
  void UpdateUIContext(const GameInformation &GMInfo);
};



