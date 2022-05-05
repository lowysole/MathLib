#pragma once

#include "Modules/Module.h"

enum class UpdateStatus;

class ModuleWindows : public Module {
public:
	bool Init() override;
	UpdateStatus Update() override;
	bool CleanUp() override;

};
