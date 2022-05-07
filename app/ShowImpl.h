#pragma once

#include "IShow.h"

class ShowImpl : public IShow {
public:
	void showMain() override;
	~ShowImpl();
private:
	ILoadDLL* dll = nullptr; // LoadDLLImpl --> ILoadDLL 面向接口
	
};