#include "Term.h"

// Constructors
Term::Term() : coefficient(0.0), exponent(0), variable('x') {}
Term::Term(double coef, int exp, char var) : coefficient(coef), exponent(exp), variable(var) {}
Term::Term(const Term& term) {
    coefficient = term.coefficient;
    exponent = term.exponent;
    variable = term.variable;
}

// Getters
double Term::getCoefficient() const { return coefficient; }
int Term::getExponent() const { return exponent; }
char Term::getVariable() const { return variable; }

// Setters
void Term::setCoefficient(double coef) { coefficient = coef; }
void Term::setExponent(int exp) { exponent = exp; }
void Term::setVariable(char var) { variable = var; }

// Assignment
Term& Term::operator=(const Term& right) {
    if (this != &right) {
        coefficient = right.coefficient;
        exponent = right.exponent;
        variable = right.variable;
    }
    return *this;
}

// Comparison
bool Term::operator<=(const Term& right) const { return exponent <= right.exponent; }
bool Term::operator>=(const Term& right) const { return exponent >= right.exponent; }
bool Term::operator<(const Term& right) const { return exponent < right.exponent; }
bool Term::operator>(const Term& right) const { return exponent > right.exponent; }
bool Term::operator==(const Term& right) const { return exponent == right.exponent; }

// Compatible
bool Term::compatible(const Term& term) const {
    return exponent == term.exponent && variable == term.variable;
}

// Output stream
ostream& operator<<(ostream& stream, const Term& term) {
    stream << term.coefficient << term.variable;
    if (term.exponent != 1) stream << "^" << term.exponent;
    return stream;
}
