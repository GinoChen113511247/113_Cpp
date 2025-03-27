#include <iostream>
using namespace std;

// Structure to represent a term in the polynomial
struct Term
{
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
    Term *next; // Pointer to the next term in the polynomial
};

// Function to insert a term into a polynomial
void insertTerm(Term *&head, int coeff, int exp)
{
    if (coeff == 0)
        return;

    Term **pp = &head;              // 類似call-by-reference的概念
    while (*pp && (*pp)->exp > exp) // *pp解引用就是Term*型態的指標(在這是head)
        pp = &((*pp)->next);        // 找到該插入的地方(多項式是降冪的)

    if (*pp && (*pp)->exp == exp)
    {
        (*pp)->coeff += coeff;
        if ((*pp)->coeff == 0)
        {
            Term *temp = *pp;
            *pp = (*pp)->next;
            delete temp;
        } // 係數為0的話就刪掉
    }
    else
    {
        Term *newTerm = new Term{coeff, exp, *pp};
        *pp = newTerm;
    } // 一般情況
}

// Function to add two polynomials
Term *addPolynomials(const Term *poly1, const Term *poly2)
{
    Term *result = nullptr;
    const Term *p1 = poly1;
    const Term *p2 = poly2;

    while (p1 || p2) // 先補缺的項再相加
    {
        if (p1 && (!p2 || p1->exp > p2->exp))
        {
            insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p2 && (!p1 || p2->exp > p1->exp))
        {
            insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else
        {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0)
                insertTerm(result, sumCoeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return result;
}

// Function to display a polynomial
void displayPolynomial(const Term *head)
{
    const Term *current = head;
    bool isFirst = true;

    if (!current)
    {
        cout << "0" << endl;
        return;
    }

    while (current)
    {
        int c = current->coeff;

        if (isFirst)
        {
            if (c < 0)
                cout << "-";
        }
        else
        {
            if (c > 0)
                cout << " + ";
            else
                cout << " - ";
        }

        int absCoeff = (c < 0) ? -c : c;
        cout << absCoeff;

        if (current->exp != 0)
            cout << "x^" << current->exp;

        current = current->next;
        isFirst = false;
    }
    cout << endl;
}

// Function to release memory allocated for the polynomial
void releaseMem(Term *&head)
{
    while (head)
    {
        Term *temp = head;
        head = head->next;
        delete temp;
    }
}

// DO NOT MODIFY THE MAIN() CODE
int main()
{
    Term *poly1 = nullptr;
    Term *poly2 = nullptr;

    // Input for Polynomial 1
    int coeff, exp;
    while (true)
    {
        cin >> coeff >> exp;
        if (exp == -1)
            break;
        insertTerm(poly1, coeff, exp);
    }

    // Input for Polynomial 2
    while (true)
    {
        cin >> coeff >> exp;
        if (exp == -1)
            break;
        insertTerm(poly2, coeff, exp);
    }

    // Add polynomials and display the result
    Term *result = addPolynomials(poly1, poly2);
    cout << "Resulting Polynomial after Addition: ";
    displayPolynomial(result);

    // Release allocated memory for the linked list nodes
    releaseMem(poly1);
    releaseMem(poly2);
    releaseMem(result);
    return 0;
}
