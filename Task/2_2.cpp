#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>


void min_heapify(int *a, int n, int i) {
    int smallest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 

    
    if (l < n && a[l] < a[smallest]) {
        smallest = l;
    }

    
    if (r < n && a[r] < a[smallest]) {
        smallest = r;
    }

    
    if (smallest != i) {
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
        min_heapify(a, n, smallest);
    }
}


void build_min_heap(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify(a, n, i);
    }
}


void max_heapify(int *a, int n, int i) {
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

   
    if (l < n && a[l] > a[largest]) {
        largest = l;
    }

    
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }

    
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, n, largest);
    }
}


void build_max_heap(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(a, n, i);
    }
}


int find_k_min_heap(int *a, int n, int k) {
    build_min_heap(a, n);

    
    for (int i = 0; i < k - 1; i++) {
        a[0] = a[n - 1 - i]; 
        min_heapify(a, n - 1 - i, 0); 
    }

    return a[0]; 
}


int find_k_mixed(int *a, int n, int k) {
    if (k <= n / 2) {
        build_min_heap(a, n);

        
        for (int i = 0; i < k - 1; i++) {
            a[0] = a[n - 1 - i];
            min_heapify(a, n - 1 - i, 0); 
        }

        return a[0]; 
    } else {
        build_max_heap(a, n);

        
        for (int i = 0; i < n - k; i++) {
            a[0] = a[n - 1 - i]; 
            max_heapify(a, n - 1 - i, 0); 
        }

        return a[0]; 
    }
}

int main() {
    srand(time(NULL));
    int n = 10000;
    int *a = (int *)malloc(sizeof(int) * n);

    // 大规模数据测试
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100000; 
    }

    int k = 5000; 
    int k_=10000;

    // 只用最小堆
    auto start = std::chrono::high_resolution_clock::now();
    int kthSmallestMinHeap = find_k_min_heap(a, n, k_);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    printf("只用最小堆：第 %d 小的元素是 %d，耗时：%.6f 毫秒\n", k_, kthSmallestMinHeap, elapsed.count());

    // 混合策略
    start = std::chrono::high_resolution_clock::now();
    int kthSmallestMixed = find_k_mixed(a, n, k);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    printf("混合策略：第 %d 小的元素是 %d，耗时：%.6f 毫秒\n", k, kthSmallestMixed, elapsed.count());

    free(a);
    return 0;
}