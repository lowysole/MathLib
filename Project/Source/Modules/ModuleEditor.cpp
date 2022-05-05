#include "ModuleEditor.h"

#include "Globals.h"
#include "Application.h"
#include "Modules/ModuleWindow.h"
#include "Modules/ModuleRender.h"

#include "GL/glew.h"
#include "SDL.h"
#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include "Utils/Leaks.h"

bool ModuleEditor::Init() {
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
	io.ConfigWindowsMoveFromTitleBarOnly = true;

	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
		io.ConfigViewportsNoAutoMerge = false;
		io.ConfigViewportsNoTaskBarIcon = true;
	}

	if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable) {
		io.ConfigDockingTransparentPayload = true;
	}

	return true;
}

bool ModuleEditor::Start() {
	ImGui_ImplSDL2_InitForOpenGL(App->window->window, App->render->context);
	ImGui_ImplOpenGL3_Init(GLSL_VERSION);

	ImGui::StyleColorsDark();

	return true;
}

UpdateStatus ModuleEditor::PreUpdate() {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	return UpdateStatus::CONTINUE;
}

UpdateStatus ModuleEditor::Update() {
	ImGui::ShowDemoWindow();

	// Main Menu bar
	ImGui::BeginMainMenuBar();
	if (ImGui::BeginMenu("File")) {
		if (ImGui::MenuItem("Quit")) {
			modalToOpen = Modal::QUIT;
		}
		ImGui::EndMenu();
	}
	ImGui::EndMainMenuBar();

	// Modals
	switch (modalToOpen) {
	case Modal::QUIT:
		ImGui::OpenPopup("Quit");
		break;
	}
	modalToOpen = Modal::NONE;

	// Quit Modal
	ImGui::SetNextWindowSize(ImVec2(260, 100), ImGuiCond_FirstUseEver);
	if (ImGui::BeginPopupModal("Quit", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar)) {
		ImGui::Text("Do you really want to quit?");
		ImGui::NewLine();
		ImGui::NewLine();
		ImGui::SameLine(ImGui::GetWindowWidth() - 120);
		if (ImGui::Button("Quit", ImVec2(50, 20))) {
			return UpdateStatus::STOP;
		}
		ImGui::SameLine(ImGui::GetWindowWidth() - 60);
		if (ImGui::Button("Cancel")) {
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}

	return UpdateStatus::CONTINUE;
}

UpdateStatus ModuleEditor::PostUpdate() {
	// Render main window
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	// Handle and render other windows
	ImGui::UpdatePlatformWindows();
	ImGui::RenderPlatformWindowsDefault();
	SDL_GL_MakeCurrent(App->window->window, App->render->context);

	return UpdateStatus::CONTINUE;
}

bool ModuleEditor::CleanUp() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	return true;
}
