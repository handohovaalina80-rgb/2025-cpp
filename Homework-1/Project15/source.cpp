#include<stdio.h>

int main(int argc, char** argv)
{
    int n;
    scanf("%d", &n);
    
    int last_digit = n % 10;
    
    printf("%d", last_digit);
    
    return 0;
}
