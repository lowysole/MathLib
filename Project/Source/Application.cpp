#include "Application.h"

#include "Globals.h"
#include "Modules/ModuleWindows.h"
#include "Modules/ModuleEditor.h"
#include "Modules/ModuleRender.h"

Application::Application() {
	// NOTE: Add all modules from App here. Important Order of creation.
	modules.push_back(windows = new ModuleWindows());
	modules.push_back(editor = new ModuleEditor());
	modules.push_back(render = new ModuleRender());
}

Application::~Application() {
	for (Module* module : modules) {
		delete module;
	}
}

bool Application::Init() {
	bool status = true;
	for (std::vector<Module*>::iterator it = modules.begin(); it != modules.end(); ++it) {
		status = (*it)->Init();
	}
	return status;
}

UpdateStatus Application::Update() {
	UpdateStatus status = UpdateStatus::CONTINUE;

	for (std::vector<Module*>::iterator it = modules.begin(); it != modules.end(); ++it) {
		status = (*it)->Update();
	}

	return status;
}

bool Application::CleanUp() {
	bool status = true;
	for (std::vector<Module*>::reverse_iterator it = modules.rbegin(); it != modules.rend(); ++it) {
		status = (*it)->CleanUp();
	}
	return status;
}
