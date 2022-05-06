#include "ResourceClassFloat2.h"

#include "imgui.h"

#include "Utils/Leaks.h"

ResourceClassFloat2::ResourceClassFloat2()
	: ResourceClass("Float2") {
}

void ResourceClassFloat2::DrawOnPanel() {
	ImGui::Text("I'm a float2");
}
