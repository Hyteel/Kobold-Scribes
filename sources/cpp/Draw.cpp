#include "GameMaster.h"


void DrawGame(GameInformation &Info)
{
  for (int iw = 0; iw < MAPTILEWIDTH; iw++)
    {
    for (int ih = 0; ih < MAPTILEHEIGHT; ih++)
      {
        Info.Tiles[iw][ih].DrawTile(0);
      }
    }

  if (Info._InputInformation.CurrentTile != nullptr)
    {
      Info._InputInformation.CurrentTile->DrawTile(1);
    }
}
