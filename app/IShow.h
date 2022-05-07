#pragma once
#include "LoadDLLImpl.h"
class IShow {
public:
	virtual void showMain() = 0;
	virtual ~IShow();
};