#include <iostream>
#include <vector>
using namespace std;

enum Color { Red, White, Blue };
void printStones(const vector<Color>& stones) {
    for (Color stone : stones) {
        switch (stone) {
            case Red:
                cout << "Red ";
                break;
            case White:
                cout << "White ";
                break;
            case Blue:
                cout << "Blue ";
                break;
        }
    }
    cout << endl;
}

void sortStones(vector<Color>& stones) {
    int low = 0;
    int mid = 0; 
    int high = stones.size() - 1;

    while (mid <= high) {
        switch (stones[mid]) {
            case Red:
                swap(stones[low], stones[mid]);
                low++;
                mid++;
                break;
            case White:
                mid++;
                break;
            case Blue:
                swap(stones[mid], stones[high]);
                high--;
                break;
        }
    }
}

int main() {
    vector<Color> stones = {Red, White, Blue, Red, Blue, White, Red, Blue, White};

    cout << "原始砾石: ";
    printStones(stones);

    sortStones(stones);

    cout << "重新排列后的砾石: ";
    printStones(stones);

    return 0;
}
