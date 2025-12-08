#include<stdio.h>

int main(int argc, char** argv)
{
    int N;
    scanf("%d", &N);
    
    int centimeters = N / 10;
    if (N % 10 != 0) {
        centimeters++;
    }
    
    printf("%d", centimeters);
    
    return 0;
}
