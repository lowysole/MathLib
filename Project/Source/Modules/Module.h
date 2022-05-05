#pragma once

enum class UpdateStatus;

class Module
{
public:
	virtual ~Module();

	virtual bool Init();
	virtual UpdateStatus Update();
	virtual bool CleanUp();

};

