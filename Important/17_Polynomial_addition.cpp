#include <iostream>
using namespace std;

struct Term {
    int coefficient;
    int exponent;
    Term* next;
};

Term* createTerm(int coef, int exp) {
    Term* newTerm = new Term;
    newTerm->coefficient = coef;
    newTerm->exponent = exp;
    newTerm->next = nullptr;
    return newTerm;
}

void insertTerm(Term*& poly, int coef, int exp) {
    Term* newNode = createTerm(coef, exp);
    newNode->next = poly;
    poly = newNode;
}

void displayPolynomial(Term* poly) {
    while (poly != nullptr) {
        cout << poly->coefficient << "x^" << poly->exponent;
        poly = poly->next;
        if (poly != nullptr) {
            cout << " + ";
        }
    }
    cout << endl;
}

Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = nullptr;

    while (poly1 != nullptr || poly2 != nullptr) {
        int coef1 = (poly1 != nullptr) ? poly1->coefficient : 0;
        int exp1 = (poly1 != nullptr) ? poly1->exponent : 0;
        int coef2 = (poly2 != nullptr) ? poly2->coefficient : 0;
        int exp2 = (poly2 != nullptr) ? poly2->exponent : 0;

        int sumCoef = coef1 + coef2;
        int sumExp = exp1;

        insertTerm(result, sumCoef, sumExp);

        if (poly1 != nullptr) poly1 = poly1->next;
        if (poly2 != nullptr) poly2 = poly2->next;
    }

    return result;
}

void deletePolynomial(Term*& poly) {
    while (poly != nullptr) {
        Term* temp = poly;
        poly = poly->next;
        delete temp;
    }
}

int main() {
    Term* poly1 = nullptr;
    Term* poly2 = nullptr;

    int choice;
    do {
        cout << "\n1. Insert into Polynomial 1\n";
        cout << "2. Insert into Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Add Polynomials\n";
        cout << "6. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    int coef, exp;
                    cout << "Enter coefficient and exponent for Polynomial 1: ";
                    cin >> coef >> exp;
                    insertTerm(poly1, coef, exp);
                    break;
                }
            case 2:
                {
                    int coef, exp;
                    cout << "Enter coefficient and exponent for Polynomial 2: ";
                    cin >> coef >> exp;
                    insertTerm(poly2, coef, exp);
                    break;
                }
            case 3:
                cout << "Polynomial 1: ";
                displayPolynomial(poly1);
                break;
            case 4:
                cout << "Polynomial 2: ";
                displayPolynomial(poly2);
                break;
            case 5:
                {
                    Term* result = addPolynomials(poly1, poly2);
                    cout << "Sum of Polynomials: ";
                    displayPolynomial(result);
                    deletePolynomial(result);
                    break;
                }
            case 6:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 6);

    // Clean up memory
    deletePolynomial(poly1);
    deletePolynomial(poly2);

    return 0;
}
