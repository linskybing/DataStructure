#ifndef TERM_H
#define TERM_H

class Term {
    public:
        friend class Polynomial;
        float coef;
        int exp;
};

#endif
