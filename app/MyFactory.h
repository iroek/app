#pragma once
// ������ĺ���������ӿ�
// �����������غ���ָ��
typedef void (*heapSort)(int arr[], int size);

class MyFactory {
private:
	MyFactory() {

	}
public:
	static heapSort getHeapSort();
	static void freeDLL();
};