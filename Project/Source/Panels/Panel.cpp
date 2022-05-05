#include "Panel.h"

Panel::Panel(const char* _name, bool _enabled)
	: name {_name}
	, enabled {_enabled} {
}

void Panel::Update() {}

bool& Panel::UpdateEnabled() {
	return enabled;
}

const char* Panel::GetName() const {
	return name;
}

bool Panel::GetEnabled() const {
	return enabled;
}
