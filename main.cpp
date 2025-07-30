#include <iostream>
#include "Term.h"
#include "Polynomial.h"

void testTerm() {
    Term t1(3.5, 2, 'x');
    Term t2(2.0, 2, 'x');
    std::cout << "Term 1: " << t1 << "\nTerm 2: " << t2 << "\n";
    std::cout << "Compatible: " << t1.compatible(t2) << "\n";
}

void testPolynomial() {
    Term t1[] = {
        Term(2.0, 2, 'x'),
        Term(3.0, 1, 'x'),
        Term(1.0, 2, 'x')
    };

    Polynomial p1(t1, 3);
    std::cout << "Simplified p1: " << p1 << "\n";

    Term t2[] = {
        Term(1.0, 3, 'x'),
        Term(4.0, 1, 'x')
    };

    Polynomial p2(t2, 2);
    std::cout << "p2: " << p2 << "\n";

    std::cout << "p1 + p2 = " << (p1 + p2) << "\n";
    std::cout << "p1 - p2 = " << (p1 - p2) << "\n";
    std::cout << "p1 * p2 = " << (p1 * p2) << "\n";
}

int main() {
    testTerm();
    testPolynomial();
    return 0;
}
