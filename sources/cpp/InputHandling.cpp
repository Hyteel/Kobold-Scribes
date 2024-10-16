#include "Buildings.h"
#include "CONSTANTS.h"
#include "GameMaster.h"
#include "TileStructure.h"
#include "UISystem.h"
#include "math.h"
#include "algorithm"
#include "iostream"
#include "raylib.h"
#include "raymath.h"



void UiInterferenceInput (GameInformation *Info, Camera2D *Camera)
{
  //UI Interference Input
  Vector2 MousePosition = GetScreenToWorld2D(GetMousePosition(), (*Camera));


  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    int MouseTileX = std::floor(MousePosition.x / TILESIZEF);
    int MouseTileY = std::floor(MousePosition.y / TILESIZEF);


    if ((MouseTileX > MAPTILEWIDTH) || (MouseTileX < 0)) {return; }
    if ((MouseTileY > MAPTILEHEIGHT) || (MouseTileY < 0)) {return; }
    if (&Info->Tiles[MouseTileX][MouseTileY] == nullptr) {return;}

    Info->_InputInformation.CurrentTile = &Info->Tiles[MouseTileX][MouseTileY];
    Info->_UIContext.UIElementDisplayTrigger[0] = true;
  }
}


void HandleInputs(GameInformation *Info, Camera2D *Camera, const UIInput &_UIInput)
{
  if (DEBUGMODE) {  std::cout << "HandleInputs - Start" << "\n";} 

  //Input
  Camera->zoom = std::clamp(Camera->zoom + (GetMouseWheelMove()*0.1f), 1.f, 10.f);
  Camera->target = (Vector2) {Camera->target.x + -1.f*Camera->zoom*(IsKeyDown(KEY_A) - IsKeyDown(KEY_D)), Camera->target.y + -1.f*Camera->zoom*(IsKeyDown(KEY_W) - IsKeyDown(KEY_S))};

  if (IsKeyPressed(KEY_Q)) { Info->_UIContext.UIElementDisplayTrigger[0] = false; Info->_UIContext.UIElementDisplayTrigger[1] = false;}
  //if (IsKeyPressed(KEY_E)) { Info->Markets[0].MarketTiles.push_back(Info->_InputInformation.CurrentTile);}

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

    case Tile_Slot5:
      {
        if (Info->_InputInformation.CurrentTile->Owner != nullptr) {break;}
        if (Info->Markets[0].Influence < INFLUENCEEXPANSIONCOST) {break;}
        if (&Info->Markets[0] == Info->_InputInformation.CurrentTile->Owner) {break;} //already owned by player

        //Is the tile neighbouring another tile?

        if (Info->Markets[0].MarketTiles.size() != 0)
          {
            bool HasFoundNeighbour = false;

            for (int i = 0; i < Info->Markets[0].MarketTiles.size(); i++)
              {
                if (Vector2Distance(Info->_InputInformation.CurrentTile->Position, Info->Markets[0].MarketTiles[i]->Position) / TILESIZEF <= 1.f) {HasFoundNeighbour = true; break;}
              }

            if (HasFoundNeighbour == false) {break;}
          }

        Info->Markets[0].Influence -= INFLUENCEEXPANSIONCOST;
        Info->_InputInformation.CurrentTile->Owner = &Info->Markets[0];
        Info->Markets[0].MarketTiles.push_back(Info->_InputInformation.CurrentTile);

        break;
      }

    case Building_Slot1:
    case Building_Slot2:
    case Building_Slot3:
    case Building_Slot4:
    case Building_Slot5:
    case Building_Slot6:
    case Building_Slot7:
      {
      auto Iterator = std::find(Info->Markets[0].MarketTiles.begin(), Info->Markets[0].MarketTiles.end(), Info->_InputInformation.CurrentTile);
      if (Iterator != Info->Markets[0].MarketTiles.end()) //Does the players market contain the currently selected tile?
        {
          int Index = Iterator - Info->Markets[0].MarketTiles.begin();
          BuildingType BType = static_cast<BuildingType>(_UIInput - 6);

          if (Info->Markets[0].Money < CBBUILDINGS[BType]->MoneyCost) {break;}

          if (!ALLOWED_BUILDINGS_PER_TILETYPE[BType + (8 * static_cast<int>(Info->_InputInformation.CurrentTile->Type))]) {break;}

          Info->Markets[0].Money -= CBBUILDINGS[BType]->MoneyCost;
          Info->Markets[0].MarketTiles[Index]->Buildings[Info->_InputInformation.CurrentSelectedBuildingSlot] = BType;
        }
      else
        {
          Info->_InputInformation.CurrentTile->Value = 1001; //Debug
        }
      break;
      }


    case Building_Slot8:
      {
        if (Info->Markets[0].Money < WINCONMONEYCOST) {break;}
        std::cout << "YOU WON";
        Info->EndGame = true;
        break;
      }

    default:
      {break;}
    }

  if (DEBUGMODE) {  std::cout << "HandleInputs - End" << "\n";}
}
