#include <iostream>
#include "polynomial.h"

using namespace std;

int main() {

    Polynomial a,b;

    int an, bn;
    cin >> an >> bn;
    for (int i = 0; i < an; i++){
        int cof,exp;
        cin >> cof >> exp;
        a.NewTerm(cof,exp);
    }
    for (int i = 0; i < bn; i++){
        int cof,exp;
        cin >> cof >> exp;
        b.NewTerm(cof,exp);
    }

    a.PrintPoly();  
    b.PrintPoly();    

    Polynomial c = a.Mult(b);
    c.PrintPoly();
    cout << c.Eval(1.7) << endl;
    return 0;
}