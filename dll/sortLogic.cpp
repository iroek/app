#include "pch.h"
#include "sortLogic.h"
#include <malloc.h>

#define DEC

void adjust(int* arr, int len, int index)
{
    int left = 2 * index; // index�����ӽڵ�  
    int right = 2 * index + 1;// index�����ӽڵ�   

    int maxIdx = index;
    if (left <= len && arr[left] > arr[maxIdx])
        maxIdx = left;
    if (right <= len && arr[right] > arr[maxIdx])
        maxIdx = right;

    if (maxIdx != index)
    {
        //swap(arr[maxIdx], arr[index]);
        int tmp = arr[maxIdx];
        arr[maxIdx] = arr[index];
        arr[index] = tmp;
        adjust(arr, len, maxIdx);
    }

}

void heapSort(int arr[], int size)
{
    // ��������ѣ������һ����Ҷ�ӽڵ����ϣ�
    for (int i = size / 2; i >= 1; i--)
    {
        adjust(arr, size, i);
    }

    // ���������  ====������Ҷ�ӻ�λ��
    for (int i = size; i >= 1; i--)
    {
        //swap(arr[1], arr[i]);           // ����ǰ���ķ��õ�����ĩβ
        int tmp = arr[1];
        arr[1] = arr[i];
        arr[i] = tmp;
        adjust(arr, i - 1, 1);              // ��δ�������Ĳ��ּ������ж�����
    }
}

void quicksort(int a[], int left, int right)
{
    int i, j, t, temp;
    if (left > right)
        return;

    temp = a[left]; //temp�д�ľ��ǻ�׼�� 
    i = left;
    j = right;
    while (i != j)
    {
        //˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ�� 
        while (a[j] >= temp && i < j)
            j--;
        //�����ұߵ� 
        while (a[i] <= temp && i < j)
            i++;
        //�����������������е�λ�� 
        if (i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //���ս���׼����λ 
    a[left] = a[i];
    a[i] = temp;

    quicksort(a, left, i - 1);//����������ߵģ�������һ���ݹ�Ĺ��� 
    quicksort(a, i + 1, right);//���������ұߵ� ��������һ���ݹ�Ĺ��� 
}

void reverse(int arr[], int size)
{
    int* p = (int*)malloc(sizeof(int) * (size + 1));
    memcpy(p, arr, sizeof(int) * (size + 1));
    for (int i = 0; i < size; i++) {
        arr[i + 1] = *(p + size - i);
    }
}

void interfaceHeapSort(int arr[], int size)
{
    heapSort(arr, size);
#ifdef DEC
    reverse(arr, size);
#endif // DEC

}

void interfaceQuicksort(int arr[], int left, int right)
{
    quicksort(arr, left, right);
#ifdef DEC
    reverse(arr, right);
#endif // DEC
}
