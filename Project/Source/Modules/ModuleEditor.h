#pragma once

#include "Module.h"

enum class Modal {
	NONE,
	QUIT
};

class ModuleEditor : public Module {
	bool Init() override;
	bool Start() override;
	UpdateStatus PreUpdate() override;
	UpdateStatus Update() override;
	UpdateStatus PostUpdate() override;
	bool CleanUp() override;

private:
	Modal modalToOpen = Modal::NONE;
};
