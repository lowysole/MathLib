#include "ModuleWindows.h"

#include "Globals.h"

bool ModuleWindows::Init() {
	return true;
}

UpdateStatus ModuleWindows::Update() {
	return UpdateStatus::CONTINUE;
}

bool ModuleWindows::CleanUp() {
	return true;
}
