// demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

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
    delete []p;
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

int main()
{
    std::cout << "Hello World!\n";
    int a[5] = { 0, 2, 5, 4, 6 };
    int b[5] = { 0, 2, 5, 4, 6 };
    interfaceHeapSort(a, 4);
    interfaceQuicksort(b, 1, 4);

    for (int i = 1; i < 5; i++)
    {
        std::cout << a[i] << std::endl;
    }

    for (int i = 1; i < 5; i++)
    {
        std::cout << b[i] << std::endl;
    }

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
