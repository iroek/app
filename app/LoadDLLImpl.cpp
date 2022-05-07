#include "LoadDLLImpl.h"
#include <iostream>
LoadDLLImpl* LoadDLLImpl::p = nullptr;

LoadDLLImpl::LoadDLLImpl()
{
	dllHandle = LoadLibrary(_T("dll.dll"));
	if (dllHandle == nullptr)
		throw 0;
	_heapSort  = (pHeapSort)GetProcAddress(dllHandle, "interfaceHeapSort");
	_quickSort = (pQuickSort)GetProcAddress(dllHandle, "interfaceQuicksort");
	if (_heapSort == nullptr)
		throw 1;
	if (_quickSort == nullptr)
		throw 2;
}

LoadDLLImpl::~LoadDLLImpl()
{
	if (p != NULL)
	{
		std::cout << "~dll\n";
		FreeLibrary(dllHandle);
		/*delete p;
		p = NULL;*/
	}
}

LoadDLLImpl* LoadDLLImpl::getInstance()
{
	if (p == nullptr) {
		p = new LoadDLLImpl();
	}
	return p;
}

void LoadDLLImpl::heapSort(int arr[], int size)
{
	_heapSort(arr, size);
}

void LoadDLLImpl::quickSort(int arr[], int right, int left)
{
	_quickSort(arr, right, left);
}
