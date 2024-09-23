#include "UISystem.h"
#include "GameMaster.h"
#include "raylib.h"
#include "raygui.h"
#include "iostream"

UIInput HandleUI(const GameInformation &GMInfo)    {
  UIInput ReturnInput = Null;
  const std::vector<UIElement>* UIElementsP = &GMInfo._UIContext.UIElements;

  //------Always Displayed------



  //---------Dependent----------
  //Draw and Input

  for (int i = 0; i < UIElementsP->size(); i++)
    {
      if (!GMInfo._UIContext.UIElementDisplayTrigger[i]) {continue;}

      GuiPanel((*UIElementsP)[i].Bounds, (*UIElementsP)[i].DisplayText.c_str());

      for (int ib = 0; ib < (*UIElementsP)[i].Buttons.size(); ib++)
        { 
          if (GuiButton((*UIElementsP)[i].Buttons[ib], (*UIElementsP)[i].ButtonText[ib].c_str()))
            {
              ReturnInput = (*UIElementsP)[i].ButtonResponse[ib];
            }
        }

      for (int it = 0; it < (*UIElementsP)[i].TextFields.size(); it++)
        {
          GuiLabel((*UIElementsP)[i].TextFields[it], (*UIElementsP)[i].Text[it].c_str());
        }
    }


  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
      Vector2 MousePos =  GetMousePosition();

      for (int i = 0; i < UIElementsP->size(); i++)
        {
          if (!GMInfo._UIContext.UIElementDisplayTrigger[i]) {continue;}

          if (CheckCollisionPointRec(MousePos, (*UIElementsP)[i].Bounds))
            {
              ReturnInput = NonButton;
              break;
            }
        }
      if (ReturnInput == Null)
        {
          return ReturnInput;
        }
    }


  return ReturnInput;
}
