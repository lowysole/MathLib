#pragma once
class ResourceClass {
public:
	ResourceClass(const char* _name);

	virtual void DrawOnPanel();

	const char* GetName() const;

private:

	const char* name;
};
