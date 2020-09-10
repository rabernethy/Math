#include <stdio.h>

int dSum(int n1, int n2);
int reverse(int n);
int max(int n1, int n2);
int min(int n1, int n2);

int main() {

    int n1 = 9994;
    int n2 = 110024;

    printf("%d + %d = %d\n", n1, n2, dSum(n1,n2));
}

// returns the sum of two numbers following dismal arithmetic.
int dSum(int n1, int n2) {
    int i = 0, sum = 0;
    while(n1||n2) {
        sum = max(n1 % 10, n2 % 10) + sum * 10;
        n1 /= 10;
        n2 /= 10;
    }
    return reverse(sum);
}

int reverse(int n) {
    //lexigraphically reverses an integer.
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