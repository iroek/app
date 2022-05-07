#pragma once

#include "ILoadDLL.h"

#include <Windows.h>
#include <tchar.h>

typedef void (*pHeapSort)(int arr[], int size);
typedef void (*pQuickSort)(int arr[], int left, int right);

class LoadDLLImpl : public ILoadDLL {
private:
	LoadDLLImpl();
	
	HINSTANCE dllHandle;
	pHeapSort _heapSort;
	pQuickSort _quickSort;
public:
	static LoadDLLImpl* p;
	//static LoadDLLImpl* getInstance();
	void heapSort(int arr[], int size) override;
	void quickSort(int arr[], int right, int left) override;
	~LoadDLLImpl() override;
};

//