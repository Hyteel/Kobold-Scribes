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


#include "raylib.h"

#include "GameMaster.h"


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

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------
  // Game Initialization
  GameInformation GameInformationMain;
  GameInformationMain.InitializeGameInfornamtion();
  GameInformationMain.DisplayTileInformation();

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    HandleInputs(&GameInformationMain);

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    DrawGame(GameInformationMain);
    ClearBackground(RAYWHITE);

    //DrawText("Congrats! You created your first window!", 190, 200, 20,
    //         LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
