#include <iostream>
using namespace std;

struct Record {
    int key;
};


int partition(Record r[], int low, int high, int key) {
    int pivot = r[high].key; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (r[j].key <= pivot) {
            i++;
            swap(r[i], r[j]);
        }
    }
    swap(r[i + 1], r[high]);
    return i + 1;
}


int quickSearch(Record r[], int low, int high, int key) {
    if (low <= high) {
        int pi = partition(r, low, high, key);

        if (r[pi].key == key) {
            return pi;
        } else if (r[pi].key < key) {
            return quickSearch(r, pi + 1, high, key);
        } else {
            return quickSearch(r, low, pi - 1, key);
        }
    }
    return -1;
}

int main() {

    Record r[] = {{5}, {3}, {8}, {1}, {9}, {6}, {2}, {7}, {4}};
    cout<<"记录如下："<<endl;
    for(int i=0;i<9;i++){
        cout<<r[i].key<<" ";
    }
    cout<<endl;
    int n = sizeof(r) / sizeof(r[0]);
    int key = 6;

    int result = quickSearch(r, 0, n - 1, key);

    if (result != -1) {
        cout << "记录 " << key << " 在数组中的位置是: " << result << endl;
    } else {
        cout << "not find" << endl;
    }

    return 0;
}