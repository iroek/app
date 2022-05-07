#pragma once

extern "C" {
	__declspec(dllexport) void interfaceHeapSort(int arr[], int size);
	__declspec(dllexport) void interfaceQuicksort(int arr[], int left, int right);
}
