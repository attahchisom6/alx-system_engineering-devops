bool Init_camera(SDL_Event event, SDL_Renderer *renderer)
{
	static float cameraAngle = 0.0;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	switch (event.key.keysym.sym)
	{
		case SDLK_LEFT:
			cameraAngle -= 0.5;
			break;
		case SDLK_RIGHT:
			cameraAngle += 0.5;
			break;
	}

	return true;
}



