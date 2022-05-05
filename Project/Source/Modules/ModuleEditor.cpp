#include "ModuleEditor.h"

#include "Globals.h"

#include "GL/glew.h"
#include "imgui.h"

#include "Utils/Leaks.h"

bool ModuleEditor::Init() {
	//ImGui::CreateContext();
	//ImGuiIO& io = ImGui::GetIO();

	return true;
}

UpdateStatus ModuleEditor::Update() {
	return UpdateStatus::CONTINUE;
}

bool ModuleEditor::CleanUp() {
	return true;
}
