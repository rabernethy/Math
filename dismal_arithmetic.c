#include <stdio.h>

int dSum(int n1, int n2);
int reverse(int n);

int main() {

    int n1 = 9994;
    int n2 = 110024;

    printf("%d + %d = %d\n", n1, n2, dSum(n1,n2));
}


int dSum(int n1, int n2) {
    int i = 0, sum = 0;

//take the larger digit
    while(n1||n2) {
        sum = ((n1%10>n2%10) ? n1%10 : n2%10) + sum*10;
        n1/=10;
        n2/=10;
    }
    return reverse(sum);
}

int reverse(int n) {
    //lexigraphically reverses an integer.
    int rem, rev = 0;
    while (n != 0) {
        rem = n % 10;
        rev = rev * 10 + rem;
        n/=10; 
    }
    return rev;
}

