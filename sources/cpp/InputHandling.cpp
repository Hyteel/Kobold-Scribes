#include "GameMaster.h"
#include "UISystem.h"
#include "math.h"
#include "algorithm"
#include "iostream"



void UiInterferenceInput (GameInformation *Info, Camera2D *Camera)
{
  //UI Interference Input
  Vector2 MousePosition = GetScreenToWorld2D(GetMousePosition(), (*Camera));


  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    int MouseTileX = std::floor(MousePosition.x / TILESIZEF);
    int MouseTileY = std::floor(MousePosition.y / TILESIZEF);

    Info->_InputInformation.CurrentTile = &Info->Tiles[MouseTileX][MouseTileY];
    Info->_UIContext.UIElementDisplayTrigger[0] = true;
    // Info->_UIContext.UIElementDisplayTrigger[1] = true;
  }
}


void HandleInputs(GameInformation *Info, Camera2D *Camera, const UIInput &_UIInput)
{
  //Input
  Camera->zoom = std::clamp(Camera->zoom + (GetMouseWheelMove()*0.1f), 1.f, 10.f);
  Camera->target = (Vector2) {Camera->target.x + -1.f*Camera->zoom*(IsKeyDown(KEY_A) - IsKeyDown(KEY_D)), Camera->target.y + -1.f*Camera->zoom*(IsKeyDown(KEY_W) - IsKeyDown(KEY_S))};

  if (IsKeyPressed(KEY_Q)) { Info->_UIContext.UIElementDisplayTrigger[0] = false; Info->_UIContext.UIElementDisplayTrigger[1] = false;}
  if (IsKeyPressed(KEY_E)) { Info->Markets[0].MarketTiles.push_back(Info->_InputInformation.CurrentTile);}

  //UI Input
  switch (_UIInput)
    {
    case Null:
      {UiInterferenceInput(Info,  Camera);
      break;}

    case Tile_Slot1:
    case Tile_Slot2:
    case Tile_Slot3:
    case Tile_Slot4:
      {
      Info->_InputInformation.CurrentTile->Value += (_UIInput % 2) - 1;
      Info->_InputInformation.CurrentSelectedBuildingSlot = (_UIInput - 2);
      Info->_UIContext.UIElementDisplayTrigger[1] = true;
      break;
      }


    case Building_Slot1:
    case Building_Slot2:
    case Building_Slot3:
    case Building_Slot4:
      {
      auto Iterator = std::find(Info->Markets[0].MarketTiles.begin(), Info->Markets[0].MarketTiles.end(), Info->_InputInformation.CurrentTile);
      if (Iterator != Info->Markets[0].MarketTiles.end()) //Does the players market contain the currently selected tile?
        {
          int Index = Iterator - Info->Markets[0].MarketTiles.begin();
          BuildingType BType = static_cast<BuildingType>(_UIInput - 5);
          Info->Markets[0].MarketTiles[Index]->Buildings[Info->_InputInformation.CurrentSelectedBuildingSlot] = BType;
        }
      else
        {
          Info->_InputInformation.CurrentTile->Value = 1001; //Debug
        }
      break;
      }


    default:
      {break;}
    }
}
