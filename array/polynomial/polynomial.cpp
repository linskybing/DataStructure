
#include "polynomial.h"
#include <iostream>
#include <iomanip>

using namespace std;

Polynomial::Polynomial(): capacity(10), terms(0) {
    termArray = new Term[capacity];
    degree = 0;
}

int Polynomial::FindExp(const int exp) const{
    for (int i = 0; i < terms; i++){
        if (termArray[i].exp == exp) return i;
    }

    return -1;
}

void Polynomial::NewTerm(const float theCoeff, const int theExp){
    
    if (terms == capacity){
        capacity *= 2;
        Term* temp = new Term[capacity];
        copy(termArray, termArray + terms, temp);
        delete [] termArray;
        termArray = temp;
    }

    int index = FindExp(theExp);    
    if (index != -1){
        termArray[index].coef += theCoeff;
    }
    else {        
        termArray[terms].coef = theCoeff;
        termArray[terms++].exp = theExp;        
    }

    if(theExp > degree) degree = theExp;
}

void Polynomial::PrintPoly(){
    int count = terms;
    for (int i = degree; i >= 0; i--){

        int index = FindExp(i); 
        
        if (index == -1) continue;

        if (count == 0) break;
        
        if (i != 0){
            if (termArray[index].coef != 1) cout << termArray[index].coef;
            cout << "x^" << termArray[index].exp;
        } 
        else{
            cout << termArray[index].coef;
        }

        if (--count != 0) cout << " + ";    
    }
    cout << endl;
}

Polynomial Polynomial::Add(Polynomial poly){
    Polynomial c;

    int aPos = 0, bPos = 0;
    while (aPos < terms && bPos < poly.terms){

        if(termArray[aPos].exp == poly.termArray[bPos].exp){
            float t = termArray[aPos].coef + poly.termArray[bPos].coef;
            if (t) c.NewTerm(t, termArray[aPos].exp);            
            aPos++; bPos++;            
        }
        else if (termArray[aPos].exp > poly.termArray[bPos].exp){
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;            
        }
        else {
            c.NewTerm(poly.termArray[bPos].coef, poly.termArray[bPos].exp);
            bPos++;             
        }
    }

    for(;aPos < terms; aPos++){
        c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
    }
    for(;bPos < poly.terms; bPos++){
        c.NewTerm(poly.termArray[bPos].coef, poly.termArray[bPos].exp);
    }

    return c;
}

Polynomial Polynomial::Mult(Polynomial b){
    Polynomial c;

    for (int i = 0; i < terms; i++){
        for (int j = 0; j < b.terms; j++){
            float exp = termArray[i].exp +  b.termArray[j].exp;
            float coef = termArray[i].coef * b.termArray[j].coef;
            c.NewTerm(coef, exp);

        }
    }

    return c;
}

float Polynomial::Eval(float x) const{
    float result = 0;

    for (int i = 0; i < terms; i++){
        const int exp = termArray[i].exp;
        float power = x;
        for(int j = 0; j < exp - 1; j++){
            power *= x;
        }
        result += power * termArray[i].coef;
    }

    return result;
}

Polynomial::~Polynomial(){
    delete [] termArray;    
}