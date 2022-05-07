#pragma once
// 不需要ILoadDLL
// 直接单例工厂静态函数
class ILoadDLL {
private:
public:d
	virtual void heapSort(int arr[], int size) = 0;
	virtual void quickSort(int arr[], int right, int left) = 0;
	virtual ~ILoadDLL();
	static LoadDLLImpl* getInstance();
};
