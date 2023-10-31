#ifndef POLYNOMIAL_h
#define POLYNOMIAL_h

#include "term.h"

class Polynomial {
    public:
        // Construct P(x) = 0
        Polynomial ();

        // Add the new term to current polynomial
        void NewTerm(const float theCoeff, const int theExp);

        // Find the cofficient whether exists
        int FindExp(const int exp) const;

        // Return the sum of *this and poly
        Polynomial Add(Polynomial poly);

        // Return multiplication of *this and poly
        Polynomial Mult(Polynomial poly);

        // Return the evaluation reuslt
        float Eval(float x) const;
    
        // Print the list of polynomial
        void PrintPoly();

        // Destructor
        ~Polynomial(void);

    private:
        // Array representation
        Term* termArray;
        int capacity;
        int terms;
        int degree;
};

#endif