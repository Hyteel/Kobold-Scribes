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

#include "CONSTANTS.h"
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

  std::string Path = GetApplicationDirectory();
  std::cout << Path << "\n";

  std::array<Texture2D, 15> GameTextures  = {
    LoadTexture((Path + "../assets/Images/Uncolonized_Forest.png").c_str()),
    LoadTexture((Path + "../assets/Images/Colonized_Forest.png").c_str()),
    LoadTexture((Path + "../assets/Images/Uncolonized_Plains.png").c_str()),
    LoadTexture((Path + "../assets/Images/Colonized_Plains.png").c_str()),
    LoadTexture((Path + "../assets/Images/Uncolonized_Mountain.png").c_str()),
    LoadTexture((Path + "../assets/Images/Colonized_Mountain.png").c_str()),
    LoadTexture((Path + "../assets/Images/Uncolonized_City.png").c_str()),
    LoadTexture((Path + "../assets/Images/Colonized_City.png").c_str()),
    LoadTexture((Path + "../assets/Images/Lumbermill.png").c_str()),
    LoadTexture((Path + "../assets/Images/Mine.png").c_str()),
    LoadTexture((Path + "../assets/Images/Manufactory.png").c_str()),
    LoadTexture((Path + "../assets/Images/Basic_Residences.png").c_str()),
    LoadTexture((Path + "../assets/Images/Medium_Residences.png").c_str()),
    LoadTexture((Path + "../assets/Images/Luxury_Residences.png").c_str()),
    LoadTexture((Path + "../assets/Images/Luxury_Residences.png").c_str()),
  };


  SetTargetFPS(FPS); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------
  // Game Initialization
  GameInformation GameInformationMain;
  GameInformationMain.InitializeGameInfornamtion();
  GameInformationMain._UIContext.InitializeUIContext(GameInformationMain);

  GameInformationMain._UIContext.UIElementDisplayTrigger[2] = true;

  UIInput UIInputOutput;

  int TickCounter = 0;

  std::cout << "Initialization done" << "\n";

  GameInformationMain._UIContext.UIElementDisplayTrigger[3] = true;

  // Main game loop
  while ((!WindowShouldClose()) && (!GameInformationMain.EndGame)) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------

    //Every Frame
    GameInformationMain._UIContext.UpdateUIContext(GameInformationMain); //Only needs to update on UI input, low prio performance gain, keep for now

    if (!GameInformationMain.IsPaused)
    {
      TickCounter++;

      //Every Day (Tick)
      if (TickCounter == TICKRATE)
        {
          GameInformationMain.DayCounter++;
          TickCounter = 0;

          std::cout << "DayTick" << "\n";

          GameInformationMain.ConductDayTick();
        }


      //Every Week
      if (GameInformationMain.DayCounter == 7)
        {
          GameInformationMain.DayCounter = 0;
          GameInformationMain.WeekCounter++;

          std::cout << "WeekTick" << "\n";

          GameInformationMain.ConductWeekTick2();
        }

    }
    // Draw
    //----------------------------------------------------------------------------------

    //std::cout << GameInformationMain.CurrentTile << " | " << (GameInformationMain.CurrentTile == nullptr) << "\n";

    BeginDrawing();
    ClearBackground(RAYWHITE);

    //---World Space Draw---

    BeginMode2D(MainCamera);

    DrawGame(GameInformationMain, GameTextures);

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
