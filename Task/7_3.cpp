#include <iostream>
using namespace std;

const int m = 10; 


struct Record {
    int key;

};


Record H[m];


int hashFunction(int key) {
    return key % m;
}


void insertRecord(Record R) {
    int index = hashFunction(R.key);
    int i = 0;
    
    while (H[(index + i) % m].key != 0) {
        i++;
        if (i == m) { 
            cout << "散列表已满，无法插入新记录" << endl;
            return;
        }
    }
    
    H[(index + i) % m] = R;
    cout << "记录 " << R.key << " 插入成功" << endl;
}

int main() {

    for (int i = 0; i < m; i++) {
        H[i].key = 0; 
    }

    Record R1 = {25};
    Record R2 = {35};
    Record R3 = {45};

    insertRecord(R1);
    insertRecord(R2);
    insertRecord(R3);

    return 0;
}