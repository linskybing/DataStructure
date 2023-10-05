#include <iostream>
#include <iomanip>

using namespace std;

class mTerm {
    friend class sparseMatrix;
    private:
        int row;
        int col;
        int value;
};

class sparseMatrix {
    public:
        sparseMatrix();

        sparseMatrix(int r, int c, int t = 10): row(r), col(c), capacity(t), terms(0){
            termList = new mTerm[capacity];                      
        }

        void addMatrixElement(int r, int c, int value){
            if (capacity == terms) {
                capacity *= 2;
                mTerm* temp = new mTerm[capacity];
                copy(termList, termList + capacity, temp);
                delete []termList;
                termList = temp;
            }
            termList[terms].row = r;
            termList[terms].col = c;
            termList[terms++].value = value;            
        }

        void loadData(){
            for (int i = 0; i < row; i++){
                for (int j = 0; j < col; j++){
                    int value;
                    cin >> value;
                    if (value){
                        addMatrixElement(i, j, value);
                    }
                }
            }
        }

        void printMatrix(){
            int pos = 0;
            cout << "-----------matrix begin-----------\n";
            for (int i = 0; i < row; i++){
                for (int j = 0; j < col; j++){
                    if (termList[pos].row == i && termList[pos].col == j) {
                        cout << setw(4) << termList[pos++].value;
                    }
                    else {
                        cout << setw(4) << 0;
                    }
                }
                cout << '\n';
            }
            cout << "-----------matrix endline-----------\n";
        }

        sparseMatrix addMatrix(sparseMatrix b){
            sparseMatrix c(row, col);
            
            int aPos = 0, bPos = 0;

            while (aPos < terms && bPos < b.terms){
                if (termList[aPos].row == b.termList[bPos].row && termList[aPos].col == b.termList[bPos].col){
                    int value = termList[aPos].value + b.termList[bPos].value;
                    if (value){
                        c.addMatrixElement(termList[aPos].row, termList[aPos].col, value);
                    }
                    aPos++; bPos++;
                }
                else if ((termList[aPos].row < b.termList[bPos].row) || (termList[aPos].row == b.termList[bPos].row && termList[aPos].col < b.termList[bPos].col)){
                    c.addMatrixElement(termList[aPos].row, termList[aPos].col, termList[aPos].value);
                    aPos++;
                }
                else {
                    c.addMatrixElement(b.termList[bPos].row, b.termList[bPos].col, b.termList[bPos].value);
                    bPos++;
                }
            }

            for (;aPos < terms; aPos++)c.addMatrixElement(termList[aPos].row, termList[aPos].col, termList[aPos].value);
            for (;bPos < b.terms; bPos++)c.addMatrixElement(b.termList[bPos].row, b.termList[bPos].col, b.termList[bPos].value);
            return c;
        }

    private:
        mTerm* termList;
        int row;
        int col;
        int terms;
        int capacity;
};

int main() {
    int n, arow, acol, brow, bcol;
    cin >> n >> arow >> acol >> brow >> bcol;

    sparseMatrix a(arow, acol);
    a.loadData();
    a.printMatrix();
    sparseMatrix b(brow, bcol);
    b.loadData();
    b.printMatrix();

    sparseMatrix c = a.addMatrix(b);
    c.printMatrix();
}