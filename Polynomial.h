#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Term.h"
#include <ostream>
using std::ostream;

class Polynomial {
private:
    Term* terms;
    int numTerms;

    void copyTerms(const Term* source, int count);
    void simplify();

public:
    Polynomial();
    Polynomial(Term* terms, int count);
    Polynomial(const Polynomial& poly);
    ~Polynomial();

    Term* getTerms() const;
    int getNumTerms() const;
    void setTerms(Term* terms, int count);

    Polynomial& operator=(const Polynomial& right);
    Polynomial operator+(const Polynomial& right) const;
    Polynomial operator-(const Polynomial& right) const;
    Polynomial operator*(const Polynomial& right) const;

    friend ostream& operator<<(ostream& stream, const Polynomial& poly);
};

#endif
