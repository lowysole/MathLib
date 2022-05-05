#pragma once

#include "Module.h"

enum class UpdateStatus;

class ModuleEditor : public Module {
	bool Init() override;
	UpdateStatus Update() override;
	bool CleanUp() override;
};
