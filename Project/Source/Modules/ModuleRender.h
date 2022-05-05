#pragma once

#include "Modules/Module.h"

class ModuleRender : public Module {
public:
	bool Init() override;
	UpdateStatus Update() override;
	UpdateStatus PostUpdate() override;
	bool CleanUp() override;

public:
	void* context = nullptr; // SDL context
};
