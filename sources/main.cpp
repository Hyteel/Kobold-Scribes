/*******************************************************************************************
--KOBOLD SCRIBES--


Spacemacs stuff

Compile command: cc main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
Paste: C-y
Cut: C-w
Copy: M-w
Save all buffers: C-u C-x s


Todo:
Vizualize tiles
Select and highlight tiles
Change tile state after selection

********************************************************************************************/

#include <string>
#define RAYGUI_IMPLEMENTATION
#include "GameMaster.h"
#include "raygui.h"
#include "raylib.h"
#include <algorithm>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
  // Raylib Initialization 
  //--------------------------------------------------------------------------------------
  const int screenWidth = TILESIZE * MAPTILEWIDTH;
  const int screenHeight = TILESIZE * MAPTILEHEIGHT;
  InitWindow(screenWidth, screenHeight,
             "raylib [core] example - basic window1");

  Camera2D MainCamera = {0};
  MainCamera.target = (Vector2){0.f, 0.f};
  MainCamera.offset = (Vector2){0.f, 0.f};
  MainCamera.rotation = 0.0f;
  MainCamera.zoom = 1.0f;

  //GuiUnlock();

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------
  // Game Initialization
  GameInformation GameInformationMain;
  GameInformationMain.InitializeGameInfornamtion();
  //uGameInformationMain.DisplayTileInformation();

  bool UIInput = false;
  bool HasSelected = false;

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    UIInput = false;
    

    //HandleInputs(&GameInformationMain, MainCamera);
    MainCamera.zoom = std::clamp(MainCamera.zoom + (GetMouseWheelMove()*0.1f), 1.f, 10.f);
    MainCamera.target = (Vector2) {MainCamera.target.x + -1.f*MainCamera.zoom*(IsKeyDown(KEY_A) - IsKeyDown(KEY_D)), MainCamera.target.y + -1.f*MainCamera.zoom*(IsKeyDown(KEY_W) - IsKeyDown(KEY_S))};

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode2D(MainCamera);

    DrawGame(GameInformationMain);

    EndMode2D();

    if (IsKeyPressed(KEY_Q)) { HasSelected = false;}

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {HasSelected = true;}

    if ((GameInformationMain.CurrentTile != nullptr) && (HasSelected))
      {
      std::string DisplayMessage =
          "Hi! This is a message! " +
          std::to_string(GameInformationMain.CurrentTile->ID);

      GuiPanel( (Rectangle){(screenWidth/2.f) - 200, (screenHeight/2.f) - 100, 200, 100},
                DisplayMessage.c_str());

      bool Increased = GuiButton((Rectangle){(screenWidth/2.f) - 150, (screenHeight/2.f) - 50, 50, 50}, "INCREASE");
      bool Decreased = GuiButton((Rectangle){(screenWidth / 2.f) - 100,
                            (screenHeight / 2.f) - 50, 50, 50},
                "DECREASE");

      GameInformationMain.CurrentTile->Value += Increased - Decreased;

      GuiLabel((Rectangle){(screenWidth / 2.f) - 20 ,
                                             (screenHeight / 2.f)- 50, 50, 50},
        std::to_string(GameInformationMain.CurrentTile->Value).c_str());

      UIInput = CheckCollisionPointRec(
          GetMousePosition(),
          (Rectangle){(Rectangle){(screenWidth / 2.f) - 200,
                                  (screenHeight / 2.f) - 100, 200, 100}});
      }


      if (!UIInput) {
        HandleInputs(&GameInformationMain, MainCamera);
      }

    EndDrawing();
    //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
