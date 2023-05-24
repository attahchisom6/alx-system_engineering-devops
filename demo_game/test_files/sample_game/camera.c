#include "camera.h"

bool Init_camera(SDL_Event event)
{
    float cameraAngle = 0.0;
    SDL_Renderer *renderer;
    bool flag = create_window_renderer(renderer)

    switch (event.key.keysym.sym)
    {
    case SDLK_LEFT:
        cameraAngle -= 0.5;
        break;
    case SDLK_RIGHT:
        cameraAngle += 0.5;
        break;
    }

    if (flag == true)
    {
	    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	    SDL_RenderClear(renderer);
    }
    return true;
}
