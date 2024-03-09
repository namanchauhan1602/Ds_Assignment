#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
} Term;

Term* create_term(int coefficient, int exponent) {
    Term* term = (Term*)malloc(sizeof(Term));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

void add_term(Term** poly, int coefficient, int exponent) {
    Term* new_term = create_term(coefficient, exponent);
    
    if (*poly == NULL) {
        *poly = new_term;
        return;
    }
    
    Term* current = *poly;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_term;
}

void display_polynomial(Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    
    while (poly != NULL) {
        if (poly->exponent == 0) {
            printf("%d", poly->coefficient);
        } else if (poly->exponent == 1) {
            printf("%dx", poly->coefficient);
        } else {
            printf("%dx^%d", poly->coefficient, poly->exponent);
        }
        
        if (poly->next != NULL) {
            printf(" + ");
        }
        
        poly = poly->next;
    }
    printf("\n");
}

Term* add_polynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            add_term(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            add_term(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum_coefficient = poly1->coefficient + poly2->coefficient;
            add_term(&result, sum_coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    
    while (poly1 != NULL) {
        add_term(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    
    while (poly2 != NULL) {
        add_term(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    
    return result;
}

int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;

    // polynomial 1: 3x^2 + 4x - 5
    add_term(&poly1, 3, 2);
    add_term(&poly1, 4, 1);
    add_term(&poly1, -5, 0);

    // polynomial 2: 2x^3 + x^2 - 2x
    add_term(&poly2, 2, 3);
    add_term(&poly2, 1, 2);
    add_term(&poly2, -2, 1);

    Term* result = add_polynomials(poly1, poly2);
    printf("Result:- \n");
    display_polynomial(result);

    return 0;
}
