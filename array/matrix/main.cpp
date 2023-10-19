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

        sparseMatrix(int r, int c, int t = 10): rows(r), cols(c), capacity(t), terms(0){
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
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < cols; j++){
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
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < cols; j++){
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

        void printSparseTable(){
            cout << "-----------matrix begin-----------\n";
            cout << setw(8) << "row" << setw(8) << "col" << setw(8) << "value\n";
            for (int i = 0; i < terms; i++){
                cout << setw(8) << termList[i].row << setw(8) << termList[i].col << setw(8) << termList[i].value << "\n";
            }
            cout << "-----------matrix endline-----------\n";
        }

        sparseMatrix addMatrix(sparseMatrix b){
            sparseMatrix c(rows, cols);
            
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

        sparseMatrix transposeMatrix(){
            sparseMatrix c(cols, rows, terms);
            if (terms > 0){
                int* rowSize = new int[cols];
                int* rowStart = new int[cols];
                fill(rowSize, rowSize + cols, 0);
                
                for (int i = 0; i < terms; i++) rowSize[termList[i].col]++;

                rowStart[0] = 0;
                for (int i = 1; i < cols; i++) {
                    rowStart[i] = rowStart[i-1] + rowSize[i-1];
                }

                for (int i = 0; i < terms; i++) {
                    int j = rowStart[termList[i].col];
                    c.termList[j].row = termList[i].col;
                    c.termList[j].col = termList[i].row;
                    c.termList[rowStart[termList[i].col]++].value = termList[i].value;
                    c.terms++;
                }
                delete [] rowSize;
                delete [] rowStart;
            }          
            return c;
        }

        sparseMatrix multiply(sparseMatrix b) {
            // Compute the transpose of b            
            sparseMatrix bT = b.transposeMatrix();                     
            sparseMatrix c(rows, b.cols);
            int now_row_a_start = 0, now_row_a_end = 0;
            // ith row in a matrix
            for (int i = 0; i < rows; i++) {                            
                for (; termList[now_row_a_end].row == i; now_row_a_end++);                
                int now_b_index = 0;                
                // jth row int bT matrix
                for (int j = 0; j < bT.rows; j++) {                    
                    int sum = 0;
                    int now_a_index = now_row_a_start;                                   
                    while (now_a_index < now_row_a_end && bT.termList[now_b_index].row == j){                        
                        if (termList[now_a_index].col == bT.termList[now_b_index].col) {
                            sum += termList[now_a_index].value * bT.termList[now_b_index].value;
                            now_a_index++; now_b_index++;
                        }
                        else if (termList[now_a_index].col < bT.termList[now_b_index].col) {
                            now_a_index++;
                        }
                        else {
                            now_b_index++;
                        }                        
                    }

                    // ending current row multiply then change now_b_index to the next row
                    // if now_a_index is smaller than now_b_index and now_b_index will not go to the next line
                    for (;bT.termList[now_b_index].row == j; now_b_index++);

                    c.addMatrixElement(i, j, sum);                    
                }
                
                now_row_a_start = now_row_a_end;
                
            }
            return c;
        }

    private:
        mTerm* termList;
        int rows;
        int cols;
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
    
    sparseMatrix c = a.multiply(b);
    c.printMatrix();
}