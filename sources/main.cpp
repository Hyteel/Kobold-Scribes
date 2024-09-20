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

#include "UISystem.h"
#define RAYGUI_IMPLEMENTATION

#include "GameMaster.h"
#include "raygui.h"
#include "raylib.h"
#include "iostream"


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
  // Raylib Initialization 
  //--------------------------------------------------------------------------------------
  InitWindow(SCREENWIDTH, SCREENHEIGHT,
             "raylib [core] example - basic window1");

  Camera2D MainCamera = {0};
  MainCamera.target = (Vector2){0.f, 0.f};
  MainCamera.offset = (Vector2){0.f, 0.f};
  MainCamera.rotation = 0.0f;
  MainCamera.zoom = 1.0f;


  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------
  // Game Initialization
  GameInformation GameInformationMain;
  GameInformationMain.InitializeGameInfornamtion();
  GameInformationMain._UIContext.InitializeUIContext(GameInformationMain);

  UIInput UIInputOutput;

  int TickCounter = 0;

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------

    GameInformationMain._UIContext.UpdateUIContext(GameInformationMain);

    // Draw
    //----------------------------------------------------------------------------------

    //std::cout << GameInformationMain.CurrentTile << " | " << (GameInformationMain.CurrentTile == nullptr) << "\n";

    BeginDrawing();
    ClearBackground(RAYWHITE);

    //---World Space Draw---

    BeginMode2D(MainCamera);

    DrawGame(GameInformationMain);

    EndMode2D();

    //---Screen Space Draw---

    //Input has to be handled here due to raygui
    UIInputOutput = HandleUI(GameInformationMain);
    HandleInputs(&GameInformationMain, &MainCamera, UIInputOutput);

    EndDrawing();
    //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
