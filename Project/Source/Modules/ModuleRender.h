#pragma once

#include "Modules/Module.h"

enum class UpdateStatus;

class ModuleRender : public Module {
public:
	bool Init() override;
	UpdateStatus Update() override;
	bool CleanUp() override;
};
