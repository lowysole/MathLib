#include "Module.h"

#include "../Globals.h"

Module::~Module()
{
}

bool Module::Init()
{
	return true;
}

UpdateStatus Module::Update()
{
	return UpdateStatus::CONTINUE;
}

bool Module::CleanUp()
{
	return true;
}
