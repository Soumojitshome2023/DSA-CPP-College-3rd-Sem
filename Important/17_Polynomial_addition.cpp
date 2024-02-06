#include <iostream>
using namespace std;

// ============================= Term =============================
struct Term
{
    int coefficient;
    int exponent;
    Term *next;
};

// ============================= Create Term =============================
Term *createTerm(int coef, int exp)
{
    Term *newTerm = new Term;
    newTerm->coefficient = coef;
    newTerm->exponent = exp;
    newTerm->next = nullptr;
    return newTerm;
}

// ========================= Insert New Term At End =========================
Term *insertTerm(Term *Headpoly, int coef, int exp)
{
    Term *poly = Headpoly;
    Term *newNode = createTerm(coef, exp);
    if (poly == NULL)
    {
        return newNode;
    }
    while (poly->next != NULL)
    {
        poly = poly->next;
    }
    poly->next = newNode;
    return Headpoly;
}

// ========================= Swap Terms =========================
void swapTerms(Term *term1, Term *term2)
{
    int tempCoeff = term1->coefficient;
    int tempExp = term1->exponent;

    term1->coefficient = term2->coefficient;
    term1->exponent = term2->exponent;

    term2->coefficient = tempCoeff;
    term2->exponent = tempExp;
}

// ========================= Sort Polynomial =========================
void sortPolynomialDescending(Term *&poly)
{
    if (poly == nullptr || poly->next == nullptr)
    {
        return;
    }

    bool swapped;
    Term *ptr1;
    Term *lptr = nullptr;

    do
    {
        swapped = false;
        ptr1 = poly;
        while (ptr1->next != lptr)
        {
            if (ptr1->exponent < ptr1->next->exponent)
            {
                swapTerms(ptr1, ptr1->next);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;

    } while (swapped);
}

// ============================= Display Polynomial =============================
void displayPolynomial(Term *poly)
{
    sortPolynomialDescending(poly);
    while (poly != NULL)
    {
        cout << poly->coefficient << "x^" << poly->exponent;
        poly = poly->next;
        if (poly != nullptr)
        {
            cout << " + ";
        }
    }
    cout << endl;
}

// ============================= Delete =============================
void DeleteAtIndex(Term *headPoly, int index)
{
    Term *temp = headPoly;
    int currentIndex = 0;
    if (index < 0)
    {
        printf("Invalid index\n");
        return;
    }
    if (index == 0)
    {
        headPoly = headPoly->next;
        free(temp);
        return;
    }
    while (temp != NULL && currentIndex < index - 1)
    {
        temp = temp->next;
        currentIndex++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid index\n");
        return;
    }

    Term *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// ============================= Add Polynomials =============================

Term *addPolynomials(Term *poly1, Term *poly2)
{
    Term *result = nullptr;
    Term *AddPoly = nullptr;

    while (poly1 != NULL)
    {
        AddPoly = insertTerm(AddPoly, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        AddPoly = insertTerm(AddPoly, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    // cout << "Line 1";

    Term *temp = AddPoly;
    while (temp != NULL)
    {
        // cout << "Line 2";
        int Coff1 = temp->coefficient;
        int Exp1 = temp->exponent;
        int Coff2;
        int Exp2;
        Term *temp2 = AddPoly;
        int index = 0;

        // cout << "Line 3";
        while (temp2 != NULL && !(Exp1 == temp2->exponent && temp != temp2))
        {
            temp2 = temp2->next;
            index++;
            // cout << "Line 4";
        }
        if (temp2 != NULL && Exp1 == temp2->exponent && temp != temp2)
        {
            int coff = Coff1 + temp2->coefficient;
            result = insertTerm(result, coff, Exp1);
            // cout << "Line 5";
            DeleteAtIndex(AddPoly, index);
            // cout << "Line 6";
        }
        else
        {
            result = insertTerm(result, Coff1, Exp1);
            // cout << "Line 7";
        }
        temp = temp->next;
        // cout << "Line 8";
    }

    return result;
}

// ============================= Main =============================
int main()
{
    Term *poly1 = nullptr;
    Term *poly2 = nullptr;

    int choice;
    do
    {
        cout << "\n1. Insert into Polynomial 1\n";
        cout << "2. Insert into Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Add Polynomials\n";
        cout << "6. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int coef, exp;
            cout << "Enter coefficient and exponent for Polynomial 1: ";
            cin >> coef >> exp;
            poly1 = insertTerm(poly1, coef, exp);
            break;
        }
        case 2:
        {
            int coef, exp;
            cout << "Enter coefficient and exponent for Polynomial 2: ";
            cin >> coef >> exp;
            poly2 = insertTerm(poly2, coef, exp);
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
            Term *result = addPolynomials(poly1, poly2);
            cout << "Sum of Polynomials: ";
            displayPolynomial(result);
            exit(0);
            break;
        }
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}

// ==========================================================