#include <iostream>
#include <vector>

using namespace std;


struct Triple {
    int row, col, value;
};


class SparseMatrix {
public:
    SparseMatrix(int m, int n) : rows(m), cols(n) {}

    void setElement(int i, int j, int val) {
        if (val != 0) {
            elements.push_back({i, j, val});
            terms++;
        }
    }

    void transpose() {
        int nu = cols; 
        int mu = rows; 
        int tu = terms; 

        vector<Triple> transposedElements(tu);

        
        vector<int> num(nu, 0);
        for (const auto& elem : elements) {
            num[elem.col]++;
        }

        
        vector<int> cpot(nu, 0);
        cpot[0] = 0;
        for (int col = 1; col < nu; col++) {
            cpot[col] = cpot[col - 1] + num[col - 1];
        }

       
        for (const auto& elem : elements) {
            int pb = cpot[elem.col];
            transposedElements[pb] = {elem.col, elem.row, elem.value};
            cpot[elem.col]++;
        }

        
        elements = transposedElements;
        swap(rows, cols);
    }

    void print() const {
        for (const auto& elem : elements) {
            cout << "(" << elem.row << ", " << elem.col << ", " << elem.value << ")" << endl;
        }
    }

private:
    int rows, cols, terms = 0;
    vector<Triple> elements;
};

int main() {
    int m, n, t;
    cout << "请输入矩阵的行数、列数和非零元素个数: ";
    cin >> m >> n >> t;

    SparseMatrix matrix(m, n);

    cout << "请输入非零元素的行号、列号和值: " << endl;
    for (int i = 0; i < t; i++) {
        int row, col, value;
        cin >> row >> col >> value;
        matrix.setElement(row, col, value);
    }

    cout << "原始矩阵的三元组表示: " << endl;
    matrix.print();

    matrix.transpose();

    cout << "转置后的矩阵的三元组表示: " << endl;
    matrix.print();

    return 0;
}