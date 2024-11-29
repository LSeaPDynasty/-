/*
实验内容：对希尔排序、快速排序、归并排序任意选择两种排序方法进行比较。
任意选择希尔排序、快速排序、归并排序中两种排序方法，对任意给定一组数据：单增、单减、乱码等，对它们进行比较分析。
实验说明：
希尔排序算法如下：
void ShellSort(int r[ ], int n)
{	
for (d=n/2; d>=1; d=d/2)   //以增量为d进行直接插入排序
{
	for (i=d+1; i<=n; i++)   
	{   
       r[0]=r[i];    //暂存被插入记录
  for (j=i-d; j>0 && r[0]<r[j]; j=j-d)
  r[j+d]=r[j];         //记录后移d个位置
       r[j+d]=r[0];
}
}
    }
    快速排序算法如下：
    void QuickSort(int r[ ], int first, int end)
{	
  if (first<end) {      //递归结束
           pivot=Partition(r, first, end);  //一次划分
           QuickSort(r, first, pivot-1);  //递归地对左侧子序列进行快速排序
           QuickSort(r, pivot+1, end);   //递归地对右侧子序列进行快速排序
  }
}
int Partition(int r[ ], int first, int end)
{	
i=first; j=end;         //初始化
while (i<j)	
{  
  while (i<j && r[i]<= r[j]) j--；  //右侧扫描
  if (i<j) { 
        r[i]←→r[j];            //将较小记录交换到前面
        i++; 
  }
  while (i<j && r[i]<= r[j]) i++；  //左侧扫描
if (i<j) {
      r[j]←→r[i];            //将较大记录交换到后面
      j--; 
}
}
retutn i;    //i为轴值记录的最终位置
}
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
using namespace std;


void ShellSort(int r[], int n) {
    for (int d = n / 2; d >= 1; d = d / 2) { 
        for (int i = d; i < n; i++) {
            int temp = r[i]; 
            int j;
            for (j = i; j >= d && r[j - d] > temp; j -= d)
                r[j] = r[j - d];
            r[j] = temp;
        }
    }
}


int Partition(int r[], int first, int end) {
    int i = first, j = end;
    while (i < j) {
        while (i < j && r[i] <= r[j]) j--;
        if (i < j) {
            swap(r[i], r[j]);
            i++;
        }
        while (i < j && r[i] <= r[j]) i++;
        if (i < j) {
            swap(r[i], r[j]);
            j--;
        }
    }
    return i;
}
void QuickSort(int r[], int first, int end) {
    if (first < end) { 
        int pivot = Partition(r, first, end); 
        QuickSort(r, first, pivot - 1);  
        QuickSort(r, pivot + 1, end);  
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    const int size = 1000;
    int arr[size];

    srand(time(0));

    for (int i = 0; i < size; i++)
        arr[i] = i;

    cout << "单增数组:\n ";
    //printArray(arr, size);

    auto start = chrono::high_resolution_clock::now();
    ShellSort(arr, size);
    auto end = chrono::high_resolution_clock::now();
    cout << "       希尔排序后: ";
    //printArray(arr, size);
    cout << "希尔排序耗时: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " 微秒" << endl;

    for (int i = 0; i < size; i++)
        arr[i] = i;

    start = chrono::high_resolution_clock::now();
    QuickSort(arr, 0, size - 1);
    end = chrono::high_resolution_clock::now();
    cout << "       快速排序后: ";
    //printArray(arr, size);
    cout << "快速排序耗时: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " 微秒" << endl;

    for (int i = 0; i < size; i++)
        arr[i] = size - i - 1;

    cout << "单减数组:\n ";
    //printArray(arr, size);

    start = chrono::high_resolution_clock::now();
    ShellSort(arr, size);
    end = chrono::high_resolution_clock::now();
    cout << "       希尔排序后: ";
    //printArray(arr, size);
    cout << "希尔排序耗时: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " 微秒" << endl;

    for (int i = 0; i < size; i++)
        arr[i] = size - i - 1;

    start = chrono::high_resolution_clock::now();
    QuickSort(arr, 0, size - 1);
    end = chrono::high_resolution_clock::now();
    cout << "       快速排序后: ";
    //printArray(arr, size);
    cout << "快速排序耗时: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " 微秒" << endl;

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 10000;

    cout << "乱码数组:\n ";
    //printArray(arr, size);

    start = chrono::high_resolution_clock::now();
    ShellSort(arr, size);
    end = chrono::high_resolution_clock::now();
    cout << "       希尔排序后: ";
    //printArray(arr, size);
    cout << "希尔排序耗时: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " 微秒" << endl;

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 10000;

    start = chrono::high_resolution_clock::now();
    QuickSort(arr, 0, size - 1);
    end = chrono::high_resolution_clock::now();
    cout << "       快速排序后: ";
    //printArray(arr, size);
    cout << "快速排序耗时: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " 微秒" << endl;

    return 0;
}