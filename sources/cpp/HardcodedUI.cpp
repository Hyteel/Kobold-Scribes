#include "UISystem.h"
#include "CONSTANTS.h"
#include "GameMaster.h"
#include "iostream"

void UIContext::InitializeUIContext(const GameInformation &GMInfo) {
  //Tile UI
  UIElement TileUI;

  TileUI.Bounds = (Rectangle){(SCREENWIDTH/2.f) - 200, (SCREENHEIGHT/2.f) - 100, 200, 100};


  TileUI.DisplayText = "TILE-UI";

  TileUI.Buttons = {
    (Rectangle){(SCREENWIDTH/2.f) - 200, (SCREENHEIGHT/2.f) - 50, 50, 50},
    (Rectangle){(SCREENWIDTH / 2.f) - 150, (SCREENHEIGHT / 2.f) - 50, 50, 50},
    (Rectangle){(SCREENWIDTH / 2.f) - 100, (SCREENHEIGHT / 2.f) - 50, 50, 50},
    (Rectangle){(SCREENWIDTH / 2.f) - 50, (SCREENHEIGHT / 2.f) - 50, 50, 50}
  };

  TileUI.ButtonText = {
    "SLOT1",
    "SLOT2",
    "SLOT3",
    "SLOT4"
  };

  TileUI.ButtonResponse = {
    Tile_Slot1,
    Tile_Slot2,
    Tile_Slot3,
    Tile_Slot4
  };

  TileUI.TextFields = {
    (Rectangle){(SCREENWIDTH / 2.f) - 180, (SCREENHEIGHT / 2.f) - 90, 50, 50}
  };

  std::cout << (GMInfo._InputInformation.CurrentTile != nullptr) << "\n";
  if (GMInfo._InputInformation.CurrentTile != nullptr)
    {
      TileUI.Text = {
        std::to_string(GMInfo._InputInformation.CurrentTile->Value).c_str()
      };
    }
  else
    {
      TileUI.Text = {
        ((std::string) "NULLPTR").c_str()
      };
    }


  UIElements.push_back(TileUI);

  //Building UI
  UIElement BuildingUI;

  BuildingUI.Bounds = (Rectangle){0.f, (SCREENHEIGHT/4.f), (SCREENWIDTH/3.f), (SCREENHEIGHT/4.f)*2.f};


  BuildingUI.DisplayText = "BUILDING-UI";

  BuildingUI.Buttons = {
    (Rectangle){0.f, (SCREENHEIGHT/4.f) + 50.f, 50.f, 50.f},
    (Rectangle){0.f + 50.f, (SCREENHEIGHT/4.f) + 50.f, 50.f, 50.f},
    (Rectangle){0.f + 100.f, (SCREENHEIGHT/4.f) + 50.f, 50.f, 50.f},
    (Rectangle){0.f + 150.f, (SCREENHEIGHT/4.f) + 50.f, 50.f, 50.f}
  };

  BuildingUI.ButtonText = {
    "LUMBERYARD",
    "MINE",
    "FARM",
    "CANNERY"
  };

  BuildingUI.ButtonResponse = {
    Building_Slot1,
    Building_Slot2,
    Building_Slot3,
    Building_Slot4,
  };

  BuildingUI.TextFields = {};
  BuildingUI.Text = {};


  UIElements.push_back(BuildingUI);

  //-------------------------------------------
  for (int i = 0; i < UIElements.size(); i++)
    {
      UIElementDisplayTrigger.push_back(false);
    }
}


void UIContext::UpdateUIContext(const GameInformation &GMInfo)
{
  if (GMInfo._InputInformation.CurrentTile != nullptr)
    {
      UIElements[0].Text = {
        std::to_string(GMInfo._InputInformation.CurrentTile->Value).c_str()
      };
    }
  else
    {
      UIElements[0].Text = {
        ((std::string) "NULLPTR").c_str()
      };
    }
}

