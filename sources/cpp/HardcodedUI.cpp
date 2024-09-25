#include "UISystem.h"
#include "CONSTANTS.h"
#include "GameMaster.h"
#include "iostream"
#include "LOCALISATION.h"
#include <string>

void UIContext::InitializeUIContext(const GameInformation &GMInfo) {
  //Tile UI
  UIElement TileUI;

  TileUI.Bounds = (Rectangle){(SCREENWIDTH/2.f) - 200, (SCREENHEIGHT/2.f) - 100, 250, 100};


  TileUI.DisplayText = "TILE-UI";

  TileUI.Buttons = {
    (Rectangle){(SCREENWIDTH/2.f) - 200, (SCREENHEIGHT/2.f) - 50, 50, 50},
    (Rectangle){(SCREENWIDTH / 2.f) - 150, (SCREENHEIGHT / 2.f) - 50, 50, 50},
    (Rectangle){(SCREENWIDTH / 2.f) - 100, (SCREENHEIGHT / 2.f) - 50, 50, 50},
    (Rectangle){(SCREENWIDTH / 2.f) - 50, (SCREENHEIGHT / 2.f) - 50, 50, 50},
    (Rectangle){(SCREENWIDTH / 2.f), (SCREENHEIGHT / 2.f) - 50, 50, 50}
  };

  TileUI.ButtonText = {
    "SLOT1",
    "SLOT2",
    "SLOT3",
    "SLOT4",
    "EXPAND"
  };

  TileUI.ButtonResponse = {
    Tile_Slot1,
    Tile_Slot2,
    Tile_Slot3,
    Tile_Slot4,
    Tile_Slot5
  };

  TileUI.TextFields = {
    (Rectangle){(SCREENWIDTH / 2.f) - 180, (SCREENHEIGHT / 2.f) - 90, 50, 50},
    (Rectangle){(SCREENWIDTH / 2.f) - 130, (SCREENHEIGHT / 2.f) - 90, 150, 50}
  };


   TileUI.Text = {
     "0",
     "NONE"
   };


  UIElements.push_back(TileUI);

  //Building UI
  UIElement BuildingUI;

  BuildingUI.Bounds = (Rectangle){0.f, (SCREENHEIGHT/4.f), (SCREENWIDTH/3.f), (SCREENHEIGHT/4.f)*2.f};


  BuildingUI.DisplayText = "BUILDING-UI";

  BuildingUI.Buttons = {
    (Rectangle){20.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 75.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 130.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 185.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 240.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 295.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 350.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 240.f, (SCREENHEIGHT/4.f) + 30.f, 50.f, 50.f}
  };

  BuildingUI.ButtonText = {
    "LUMBERYARD",
    "MINE",
    "FARM",
    "CANNERY",
    "BASIC RESIDENCE",
    "MEDIUM RESIDENCE",
    "LUXURY RESIDENCE",
    "WIN CON"
  };

  BuildingUI.ButtonResponse = {
    Building_Slot1,
    Building_Slot2,
    Building_Slot3,
    Building_Slot4,
    Building_Slot5,
    Building_Slot6,
    Building_Slot7,
    Building_Slot8
  };

  BuildingUI.TextFields = {
    (Rectangle){20.f, (SCREENHEIGHT/4.f) + 150.f, 350.f, 150.f},
    /*(Rectangle){0.f + 75.f, (SCREENHEIGHT/4.f) + 150.f, 50.f, 150.f},
    (Rectangle){0.f + 130.f, (SCREENHEIGHT/4.f) + 150.f, 50.f, 150.f},
    (Rectangle){0.f + 185.f, (SCREENHEIGHT/4.f) + 150.f, 50.f, 150.f},
    (Rectangle){0.f + 240.f, (SCREENHEIGHT/4.f) + 150.f, 50.f, 150.f},
    (Rectangle){0.f + 295.f, (SCREENHEIGHT/4.f) + 150.f, 50.f, 150.f},
    (Rectangle){0.f + 350.f, (SCREENHEIGHT/4.f) + 150.f, 50.f, 150.f}*/
  };

  std::cout << LOC_BUILDINGDESCRIPTION[1] << "\n";

  BuildingUI.Text = {
    LOC_BUILDINGDESCRIPTION[1],
    /*LOC_BUILDINGDESCRIPTION[2],
    LOC_BUILDINGDESCRIPTION[3],
    LOC_BUILDINGDESCRIPTION[4],
    LOC_BUILDINGDESCRIPTION[5],
    LOC_BUILDINGDESCRIPTION[6],
    LOC_BUILDINGDESCRIPTION[7],*/
  };


  UIElements.push_back(BuildingUI);

  //HUD
  UIElement HUD;

  HUD.Bounds = (Rectangle){0.f, 0.f, (SCREENWIDTH), (SCREENHEIGHT/10.f)};

  HUD.DisplayText = "HUD";

  HUD.Buttons = {};

  HUD.ButtonText = {};

  HUD.ButtonResponse = {};

  HUD.TextFields = {
    (Rectangle){0.f, 5.f, (SCREENWIDTH/10.f), (SCREENHEIGHT/10.f) - 20.f},
    (Rectangle){(SCREENWIDTH/10.f), 5.f, (SCREENWIDTH/10.f), (SCREENHEIGHT/10.f) - 20.f},
    (Rectangle){(SCREENWIDTH/10.f)*2.f + 50, 5.f, (SCREENWIDTH/10.f), (SCREENHEIGHT/10.f) - 20.f},
    (Rectangle){(SCREENWIDTH/10.f)*3.f + 50, 5.f, (SCREENWIDTH/10.f), (SCREENHEIGHT/10.f) - 20.f},
    (Rectangle){(SCREENWIDTH/10.f)*4.f + 50, 5.f, (SCREENWIDTH/10.f), (SCREENHEIGHT/10.f) - 20.f},
    (Rectangle){(SCREENWIDTH/10.f)*5.f + 50, 5.f, (SCREENWIDTH/10.f), (SCREENHEIGHT/10.f) - 20.f},
    (Rectangle){SCREENWIDTH - ((SCREENWIDTH/10.f) + 50), 5.f, (SCREENWIDTH/10.f), (SCREENHEIGHT/10.f) - 20.f},
  };

  HUD.Text = {
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0"
  };


  UIElements.push_back(HUD);
  //-------------------------------------------
  for (int i = 0; i < UIElements.size(); i++)
    {
      UIElementDisplayTrigger.push_back(false);
    }
}


void UIContext::UpdateUIContext(const GameInformation &GMInfo) //Only needs to update on UI input
{
  //TileUI
  if (GMInfo._InputInformation.CurrentTile != nullptr)
    {
      for (int i = 0; i < UIElements[0].ButtonText.size() - 1; i++)
        {
          UIElements[0].ButtonText[i] = LOC_BUILDINGS[GMInfo._InputInformation.CurrentTile->Buildings[i]];
        }

      UIElements[0].Text[0] = std::to_string(GMInfo._InputInformation.CurrentTile->Value).c_str();

      std::string MarketTileText = "Belongs to market: "; 

      if (GMInfo._InputInformation.CurrentTile->Owner != nullptr)
        {
          MarketTileText += std::to_string(GMInfo._InputInformation.CurrentTile->Owner->IndexID);
        }
      else
        {
          MarketTileText += "None";
        }

      UIElements[0].Text[1] = MarketTileText;
    }
  else
    {
      UIElements[0].Text[0] = ((std::string) "NULLPTR").c_str();
    }


  //HUD
  for (int i = 1; i < GOODSCOUNT; i++)
    {
      std::string HudText = LOC_GOODS[i] + std::to_string(GMInfo.Markets[0].Goods[i]);
      UIElements[2].Text[i - 1] = HudText;
    }

  std::string HudMoney = "Money: " + std::to_string(GMInfo.Markets[0].Money);
  UIElements[2].Text[4] = HudMoney;

  std::string HudInfluence = "Influence: " + std::to_string(GMInfo.Markets[0].Influence);
  UIElements[2].Text[5] = HudInfluence;

  std::string HudDate = "Date: Week " + std::to_string(GMInfo.WeekCounter) + " |  Day " + std::to_string(GMInfo.DayCounter);
  UIElements[2].Text[6] = HudDate;
}

