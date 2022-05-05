#pragma once

#include <vector>

enum class UpdateStatus;

class Module;
class ModuleEditor;
class ModuleWindows;
class ModuleRender;

class Application {
public:
	Application();
	~Application();

	bool Init();
	UpdateStatus Update();
	bool CleanUp();

public:
	ModuleWindows* windows = nullptr;
	ModuleEditor* editor = nullptr;
	ModuleRender* render = nullptr;

private:
	std::vector<Module*> modules;
};

extern Application* App;
