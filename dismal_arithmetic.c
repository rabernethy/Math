#include <stdio.h>

int dAdd(int n1, int n2);
int dMult(int n1, int n2);

int reverse(int n);
int max(int n1, int n2);
int min(int n1, int n2);
int nUnitPlaces(int n);
int power(int base, int exponent);

int main() {

    int n1 = 169;
    int n2 = 248;

    printf("%d + %d = %d\n", n1, n2, dAdd(n1,n2));
    printf("%d x %d = %d\n", n1, n2, dMult(n2, n1));
}

// returns the sum of two numbers following dismal arithmetic.
int dAdd(int n1, int n2) {
    int sum = 0;
    while(n1||n2) {
        sum = max(n1 % 10, n2 % 10) + sum * 10;
        n1 /= 10;
        n2 /= 10;
    }
    return reverse(sum);
}

// returns the product of two numbers following dismal arithmetic.
int dMult(int n1, int n2) {
    int prod, additionQueue[nUnitPlaces(n1)], i, j;
    int n1_up = nUnitPlaces(n1), n2_up = nUnitPlaces(n2);

    //dismally multiply each unit in n1 with each unit in n2 and save the result.
    for (i = 0; i < n1_up; i++) {
        prod = 0;
        int num2 = n2;

        for (j = 0; j < n2_up; j++) {
            prod = (prod * 10) + min(n1 % 10, num2 % 10);
            num2 /= 10;
        }
        additionQueue[i] = reverse(prod) * power(10, i);
        n1 /= 10;
    }
    
    // add all of the products together.
    prod = 0;
    for (i = 0; i < n1_up; i++)
        prod = dAdd(prod, additionQueue[i]);
    return prod;
}

// returns a lexigraphically reversed integer.
int reverse(int n) {
    int rem, rev = 0;
    while (n != 0) {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10; 
    }
    return rev;
}

// returns the bigger integer.
int max(int n1, int n2) {
    return (n1 > n2) ? n1 : n2;
}

// returns the smaller integer.
int min(int n1, int n2) {
    return (n1 < n2) ? n1 : n2;
}

// returns the number of unit places in an integer.
int nUnitPlaces(int n) {
    if(n == 0) 
        return 1;
    int counter = 0;
    while (n != 0) {
        counter++;
        n /= 10;
    }
    return counter;
}

int power(int base, int exponent) {
    if (exponent == 0)
        return 1;
    for (int i = 1; i < exponent; i++)
        base *= base;
    return base;
    
} 