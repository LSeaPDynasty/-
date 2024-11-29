/*
ʵ�����ݣ���ϣ�����򡢿������򡢹鲢��������ѡ���������򷽷����бȽϡ�
����ѡ��ϣ�����򡢿������򡢹鲢�������������򷽷������������һ�����ݣ�����������������ȣ������ǽ��бȽϷ�����
ʵ��˵����
ϣ�������㷨���£�
void ShellSort(int r[ ], int n)
{	
for (d=n/2; d>=1; d=d/2)   //������Ϊd����ֱ�Ӳ�������
{
	for (i=d+1; i<=n; i++)   
	{   
       r[0]=r[i];    //�ݴ汻�����¼
  for (j=i-d; j>0 && r[0]<r[j]; j=j-d)
  r[j+d]=r[j];         //��¼����d��λ��
       r[j+d]=r[0];
}
}
    }
    ���������㷨���£�
    void QuickSort(int r[ ], int first, int end)
{	
  if (first<end) {      //�ݹ����
           pivot=Partition(r, first, end);  //һ�λ���
           QuickSort(r, first, pivot-1);  //�ݹ�ض���������н��п�������
           QuickSort(r, pivot+1, end);   //�ݹ�ض��Ҳ������н��п�������
  }
}
int Partition(int r[ ], int first, int end)
{	
i=first; j=end;         //��ʼ��
while (i<j)	
{  
  while (i<j && r[i]<= r[j]) j--��  //�Ҳ�ɨ��
  if (i<j) { 
        r[i]����r[j];            //����С��¼������ǰ��
        i++; 
  }
  while (i<j && r[i]<= r[j]) i++��  //���ɨ��
if (i<j) {
      r[j]����r[i];            //���ϴ��¼����������
      j--; 
}
}
retutn i;    //iΪ��ֵ��¼������λ��
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

    cout << "��������:\n ";
    //printArray(arr, size);

    auto start = chrono::high_resolution_clock::now();
    ShellSort(arr, size);
    auto end = chrono::high_resolution_clock::now();
    cout << "       ϣ�������: ";
    //printArray(arr, size);
    cout << "ϣ�������ʱ: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ΢��" << endl;

    for (int i = 0; i < size; i++)
        arr[i] = i;

    start = chrono::high_resolution_clock::now();
    QuickSort(arr, 0, size - 1);
    end = chrono::high_resolution_clock::now();
    cout << "       ���������: ";
    //printArray(arr, size);
    cout << "���������ʱ: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ΢��" << endl;

    for (int i = 0; i < size; i++)
        arr[i] = size - i - 1;

    cout << "��������:\n ";
    //printArray(arr, size);

    start = chrono::high_resolution_clock::now();
    ShellSort(arr, size);
    end = chrono::high_resolution_clock::now();
    cout << "       ϣ�������: ";
    //printArray(arr, size);
    cout << "ϣ�������ʱ: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ΢��" << endl;

    for (int i = 0; i < size; i++)
        arr[i] = size - i - 1;

    start = chrono::high_resolution_clock::now();
    QuickSort(arr, 0, size - 1);
    end = chrono::high_resolution_clock::now();
    cout << "       ���������: ";
    //printArray(arr, size);
    cout << "���������ʱ: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ΢��" << endl;

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 10000;

    cout << "��������:\n ";
    //printArray(arr, size);

    start = chrono::high_resolution_clock::now();
    ShellSort(arr, size);
    end = chrono::high_resolution_clock::now();
    cout << "       ϣ�������: ";
    //printArray(arr, size);
    cout << "ϣ�������ʱ: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ΢��" << endl;

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 10000;

    start = chrono::high_resolution_clock::now();
    QuickSort(arr, 0, size - 1);
    end = chrono::high_resolution_clock::now();
    cout << "       ���������: ";
    //printArray(arr, size);
    cout << "���������ʱ: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " ΢��" << endl;

    return 0;
}