#include "camera.h"

bool Init_camera(SDL_Event event)
{
    float cameraAngle = 0.0;

    switch (event.key.keysym.sym)
    {
    case SDLK_LEFT:
        cameraAngle -= 0.5;
        break;
    case SDLK_RIGHT:
        cameraAngle += 0.5;
        break;
    }

    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);
    return true;
}
