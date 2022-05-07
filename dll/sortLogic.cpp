#include "pch.h"
#include "sortLogic.h"
#include <malloc.h>

#define DEC

void adjust(int* arr, int len, int index)
{
    int left = 2 * index; // index的左子节点  
    int right = 2 * index + 1;// index的右子节点   

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
    // 构建大根堆（从最后一个非叶子节点向上）
    for (int i = size / 2; i >= 1; i--)
    {
        adjust(arr, size, i);
    }

    // 调整大根堆  ====》根和叶子换位置
    for (int i = size; i >= 1; i--)
    {
        //swap(arr[1], arr[i]);           // 将当前最大的放置到数组末尾
        int tmp = arr[1];
        arr[1] = arr[i];
        arr[i] = tmp;
        adjust(arr, i - 1, 1);              // 将未完成排序的部分继续进行堆排序
    }
}

void quicksort(int a[], int left, int right)
{
    int i, j, t, temp;
    if (left > right)
        return;

    temp = a[left]; //temp中存的就是基准数 
    i = left;
    j = right;
    while (i != j)
    {
        //顺序很重要，要先从右边开始找 
        while (a[j] >= temp && i < j)
            j--;
        //再找右边的 
        while (a[i] <= temp && i < j)
            i++;
        //交换两个数在数组中的位置 
        if (i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //最终将基准数归位 
    a[left] = a[i];
    a[i] = temp;

    quicksort(a, left, i - 1);//继续处理左边的，这里是一个递归的过程 
    quicksort(a, i + 1, right);//继续处理右边的 ，这里是一个递归的过程 
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
