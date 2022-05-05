#pragma once

#include "Module.h"

#include "Panels/Panel.h"
#include "Panels/PanelAbout.h"

#include "imgui.h"
#include <vector>

enum class Modal {
	NONE,
	QUIT
};

class ModuleEditor : public Module {
public:
	bool Init() override;
	bool Start() override;
	UpdateStatus PreUpdate() override;
	UpdateStatus Update() override;
	UpdateStatus PostUpdate() override;
	bool CleanUp() override;

public:
	// Panels
	std::vector<Panel*> panels;
	PanelAbout panelAbout;

	// ImGui parameters
	const ImVec4 titleColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

private:
	void SetImGuiTheme();

private:
	Modal modalToOpen = Modal::NONE;
};
