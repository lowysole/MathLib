#include "ResourceClass.h"

ResourceClass::ResourceClass(const char* _name)
	: name {_name} {
}

void ResourceClass::DrawOnPanel() {}

const char* ResourceClass::GetName() const {
	return name;
}
