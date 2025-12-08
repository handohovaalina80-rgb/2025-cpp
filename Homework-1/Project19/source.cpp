#include<stdio.h>

int main(int argc, char** argv)
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    if ((a % b == 0) || (b % a == 0)) {
        printf("1");
    } else {
        printf("666");
    }
    
    return 0;
}
