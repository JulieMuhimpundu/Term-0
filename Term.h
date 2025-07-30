#ifndef TERM_H
#define TERM_H

#include <ostream>
using std::ostream;

class Term {
private:
    double coefficient;
    int exponent;
    char variable;

public:
    // Constructors
    Term();
    Term(double coef, int exp, char var);
    Term(const Term& term);

    // Getters
    double getCoefficient() const;
    int getExponent() const;
    char getVariable() const;

    // Setters
    void setCoefficient(double coef);
    void setExponent(int exp);
    void setVariable(char var);

    // Assignment
    Term& operator=(const Term& right);

    // Comparison
    bool operator<=(const Term& right) const;
    bool operator>=(const Term& right) const;
    bool operator<(const Term& right) const;
    bool operator>(const Term& right) const;
    bool operator==(const Term& right) const;

    // Compatibility
    bool compatible(const Term& term) const;

    // Output
    friend ostream& operator<<(ostream& stream, const Term& term);
};

#endif
