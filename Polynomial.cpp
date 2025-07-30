#include "Polynomial.h"
#include <iostream>

// Copy helper
void Polynomial::copyTerms(const Term* source, int count) {
    terms = new Term[count];
    for (int i = 0; i < count; ++i)
        terms[i] = source[i];
    numTerms = count;
}

// Default constructor
Polynomial::Polynomial() : terms(nullptr), numTerms(0) {}

// Constructor with terms
Polynomial::Polynomial(Term* t, int count) {
    copyTerms(t, count);
    simplify();
}

// Copy constructor
Polynomial::Polynomial(const Polynomial& poly) {
    copyTerms(poly.terms, poly.numTerms);
}

// Destructor
Polynomial::~Polynomial() {
    delete[] terms;
}

// Getters and Setters
Term* Polynomial::getTerms() const { return terms; }
int Polynomial::getNumTerms() const { return numTerms; }

void Polynomial::setTerms(Term* t, int count) {
    delete[] terms;
    copyTerms(t, count);
    simplify();
}

// Assignment
Polynomial& Polynomial::operator=(const Polynomial& right) {
    if (this != &right) {
        delete[] terms;
        copyTerms(right.terms, right.numTerms);
    }
    return *this;
}

// Simplify
void Polynomial::simplify() {
    for (int i = 0; i < numTerms; ++i) {
        for (int j = i + 1; j < numTerms; ++j) {
            if (terms[i].compatible(terms[j])) {
                double newCoef = terms[i].getCoefficient() + terms[j].getCoefficient();
                terms[i].setCoefficient(newCoef);

                // Shift left
                for (int k = j; k < numTerms - 1; ++k)
                    terms[k] = terms[k + 1];

                numTerms--;
                j--; // recheck same index
            }
        }
    }
}

// Operator +
Polynomial Polynomial::operator+(const Polynomial& right) const {
    int total = numTerms + right.numTerms;
    Term* newTerms = new Term[total];

    for (int i = 0; i < numTerms; ++i)
        newTerms[i] = terms[i];
    for (int i = 0; i < right.numTerms; ++i)
        newTerms[numTerms + i] = right.terms[i];

    Polynomial result(newTerms, total);
    delete[] newTerms;
    return result;
}

// Operator -
Polynomial Polynomial::operator-(const Polynomial& right) const {
    int total = numTerms + right.numTerms;
    Term* newTerms = new Term[total];

    for (int i = 0; i < numTerms; ++i)
        newTerms[i] = terms[i];

    for (int i = 0; i < right.numTerms; ++i) {
        Term neg = right.terms[i];
        neg.setCoefficient(-neg.getCoefficient());
        newTerms[numTerms + i] = neg;
    }

    Polynomial result(newTerms, total);
    delete[] newTerms;
    return result;
}

// Operator *
Polynomial Polynomial::operator*(const Polynomial& right) const {
    int total = numTerms * right.numTerms;
    Term* newTerms = new Term[total];
    int index = 0;

    for (int i = 0; i < numTerms; ++i) {
        for (int j = 0; j < right.numTerms; ++j) {
            double newCoef = terms[i].getCoefficient() * right.terms[j].getCoefficient();
            int newExp = terms[i].getExponent() + right.terms[j].getExponent();
            char var = terms[i].getVariable(); // assume same variable
            newTerms[index++] = Term(newCoef, newExp, var);
        }
    }

    Polynomial result(newTerms, index);
    delete[] newTerms;
    return result;
}

// Output stream
ostream& operator<<(ostream& stream, const Polynomial& poly) {
    for (int i = 0; i < poly.numTerms; ++i) {
        stream << poly.terms[i];
        if (i < poly.numTerms - 1)
            stream << " + ";
    }
    return stream;
}
