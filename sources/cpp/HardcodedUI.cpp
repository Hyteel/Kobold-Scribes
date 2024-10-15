#include "UISystem.h"
#include "CONSTANTS.h"
#include "GameMaster.h"
#include "iostream"
#include "LOCALISATION.h"
#include "raylib.h"
#include <cmath>
#include <sstream>
#include <string>

#define TFFD TruncateFloatForDisplay

std::string TruncateFloatForDisplay(float FloatToTruncate)
{
  std::string ReturnString = std::to_string(FloatToTruncate);
  ReturnString = ReturnString.substr(0, ReturnString.find('.') + 2);
  return ReturnString;
}


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
    (Rectangle){0.f, 5.f, (SCREENWIDTH/10.f), (SCREENHEIGHT/10.f) + 20.f},
    (Rectangle){(SCREENWIDTH/10.f), 5.f, (SCREENWIDTH/10.f), (SCREENHEIGHT/10.f) + 20.f},
    (Rectangle){(SCREENWIDTH/10.f)*2.f + 50, 5.f, (SCREENWIDTH/10.f), (SCREENHEIGHT/10.f) + 20.f},
    (Rectangle){(SCREENWIDTH/10.f)*3.f + 50, 5.f, (SCREENWIDTH/10.f), (SCREENHEIGHT/10.f) + 20.f},
    (Rectangle){(SCREENWIDTH/10.f)*4.f + 50, 5.f, (SCREENWIDTH/10.f), (SCREENHEIGHT/10.f) + 20.f},
    (Rectangle){(SCREENWIDTH/10.f)*5.f + 50, 5.f, (SCREENWIDTH/10.f), (SCREENHEIGHT/10.f) + 20.f},
  };

  HUD.Text = {
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0"
  };


  UIElements.push_back(HUD);

  //PopUp
  UIElement PopUpUI;

  PopUpUI.Bounds = (Rectangle){(SCREENWIDTH/2.f) - 200, (SCREENHEIGHT/2.f) - 100, 250, 100};


  PopUpUI.DisplayText = "TILE-UI";

  PopUpUI.Buttons = {
    (Rectangle){(SCREENWIDTH / 2.f), (SCREENHEIGHT / 2.f) - 50, 50, 50}
  };

  PopUpUI.ButtonText = {
    "Close",
  };

  PopUpUI.ButtonResponse = {
    PopUp_Exit,
  };

  PopUpUI.TextFields = {
    (Rectangle){(SCREENWIDTH / 2.f) - 180, (SCREENHEIGHT / 2.f) - 90, 175, 100},
  };


   PopUpUI.Text = {
     "0"
   };


  UIElements.push_back(PopUpUI);
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
      if (!GMInfo.HasPlacedFirstTile)
        {
          UIElements[0].ButtonText[4] = "Place City";
        }
      else
        {
          UIElements[0].ButtonText[4] = "Expand";
        }

      for (int i = 0; i < UIElements[0].ButtonText.size() - 1; i++)
        {
          UIElements[0].ButtonText[i] = LOC_BUILDINGS[GMInfo._InputInformation.CurrentTile->Buildings[i]];
        }

      //UIElements[0].Text[0] = std::to_string(GMInfo._InputInformation.CurrentTile->Value).c_str();
      UIElements[0].Text[0] = LOC_TERRAIN[GMInfo._InputInformation.CurrentTile->Type];

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


  //BuildingUI
  //Mouseover tooltip - Buildings


  /*(Rectangle){20.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 75.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 130.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 185.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 240.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 295.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 350.f, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f},
    (Rectangle){0.f + 240.f, (SCREENHEIGHT/4.f) + 30.f, 50.f, 50.f}*/

  for (int i = 0; i < 7; i++)
    {
      Rectangle CurrentRec = {20.f + 55*i, (SCREENHEIGHT/4.f) + 90.f, 50.f, 50.f};
      if (CheckCollisionPointRec(GetMousePosition(), CurrentRec)) {UIElements[1].Text[0] = LOC_BUILDINGDESCRIPTION[i + 1]; }
    }

  if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){0.f + 240.f, (SCREENHEIGHT/4.f) + 30.f, 50.f, 50.f}))
    {
      UIElements[1].Text[0] = LOC_BUILDINGDESCRIPTION[8];
    }


  //HUD
  for (int i = 1; i < GOODSCOUNT; i++)
    {
      std::string HudText = LOC_GOODS[i] + TFFD(GMInfo.Markets[0].GoodsBalance[i]);
      UIElements[2].Text[i - 1] = HudText;
      UIElements[2].Text[i - 1 + 7] = "Traded: " + TFFD(GMInfo.Markets[0].GoodsBalanceTraded[i]);
    }

  std::string HudMoney = "Money: " + TFFD(GMInfo.Markets[0].Money);
  UIElements[2].Text[4] = HudMoney;

  std::string HudInfluence = "Influence: " + TFFD(GMInfo.Markets[0].Influence);
  UIElements[2].Text[5] = HudInfluence;

  std::string HudDate = "Date: Week " + std::to_string(GMInfo.WeekCounter) + " |  Day " + std::to_string(GMInfo.DayCounter);
  UIElements[2].Text[6] = HudDate;

  UIElements[2].Text[11] = TFFD(GMInfo.Markets[0].MoneyChange);
  UIElements[2].Text[12] = TFFD(GMInfo.Markets[0].InfluenceChange);


  //PopUp
  if (GMInfo._InputInformation.CurrentPopUp == 0)
    {
      UIElements[3].Text[0] = "Select a city starting location \n Space to Pause/Unpause";
    }
  else if (GMInfo._InputInformation.CurrentPopUp == 1)
    {
      if (GMInfo._InputInformation.CurrentWinner == 0)
        {
          UIElements[3].Text[0] = "You Won!";
        }
      else
        {
          UIElements[3].Text[0] = "You lost, market that won: " + TFFD(GMInfo._InputInformation.CurrentWinner);
        }
    }



}

