#include "ShowImpl.h"
#include "iostream"

void ShowImpl::showMain()
{
	int n;
	std::cout << "ÊäÈë¸öÊý:\n";
	std::cin >> n;
	int* arr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		std::cout << i << "/" << n << ':';
		std::cin >> *(arr + i);
	}

	int* tmp = new int[n + 1];
	memcpy(tmp, arr, sizeof(int) * (n + 1));

	dll = LoadDLLImpl::getInstance();

	dll->heapSort(arr, n);
	std::cout << "heapSort" << std::endl;
	for (int i = 1; i <= n; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	dll->quickSort(tmp, 1, n);
	std::cout << "quickSort" << std::endl;
	for (int i = 1; i <= n; i++)
	{
		std::cout << tmp[i] << std::endl;
	}

	delete []arr;
	delete []tmp;
}

ShowImpl::~ShowImpl()
{
	if (dll != nullptr) {
		delete dll;
		dll = nullptr;
	}
	
}