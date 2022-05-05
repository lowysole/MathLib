#include "ModuleRender.h"

#include "Globals.h"

bool ModuleRender::Init() {
	return true;
}

UpdateStatus ModuleRender::Update() {
	return UpdateStatus::CONTINUE;
}

bool ModuleRender::CleanUp() {
	return true;
}
