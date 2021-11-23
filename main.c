#include "Mover.h"
#include "rnd.h"
#include "sgi.h"
#include "v2d.h"
#include <stdlib.h>
#include <time.h>

Mover *mvs[20];

int main(int argc, char *argv[]) {
  int i;
  rnd_Seed(time(NULL), 33);
  for (i = 0; i < 20; i++) {
    mvs[i] = NewMover(800, 600);
  }
  sgi_Init(800, 600, "Mover Test");
  Vec2D pt = {400, 300};
  int x, y;
  while (!sgi_Done()) {
    sgi_Clear(RGB_Black);
    sgi_GetMouseState(&x, &y);
    pt = (Vec2D){(float)x, (float)y};
    for (i = 0; i < 20; i++) {
      mvs[i]->Update(mvs[i], &pt);
      mvs[i]->ChkEdge(mvs[i], 800, 600);
      sgi_Disk((int)mvs[i]->location.x, (int)mvs[i]->location.y, 8, RGB_Green);
    }
    sgi_Update();
    sgi_Delay(16);
  }
  for (i = 0; i < 20; i++) {
    mvs[i]->Destroy(mvs[i]);
  }
  sgi_Fini();
  return 0;
}
