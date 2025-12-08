#include<stdio.h>

int main(int argc, char** argv)
{
    int n;
    scanf("%d", &n);
    
    int tens = (n / 10) % 10;
    
    printf("%d", tens);
    
    return 0;
}
