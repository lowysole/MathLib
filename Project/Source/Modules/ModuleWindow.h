#pragma once

#include "Modules/Module.h"

struct SDL_Window;
struct SDL_Surface;

class ModuleWindow : public Module {
public:
	bool Init() override;
	bool CleanUp() override;

public:
	SDL_Window* window = nullptr;
	SDL_Surface* surface = nullptr;
};
