#include<stdio.h>

int main(int argc, char** argv)
{
    int n;
    scanf("%d", &n);
    
    int hundreds = n / 100;
    int tens = (n / 10) % 10;
    int units = n % 10;
    
    int sum = hundreds + tens + units;
    
    printf("%d", sum);
    
    return 0;
}
