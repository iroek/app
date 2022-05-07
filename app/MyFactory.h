#pragma once
// 工厂类的核心是面向接口
// 调函数，返回函数指针
typedef void (*heapSort)(int arr[], int size);

class MyFactory {
private:
	MyFactory() {

	}
public:
	static heapSort getHeapSort();
	static void freeDLL();
};