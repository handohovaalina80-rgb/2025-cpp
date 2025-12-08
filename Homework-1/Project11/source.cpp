#include<stdio.h>

int main(int argc, char** argv)
{
    long long N;
    scanf("%lld", &N);   
    long long result = ((N + 1) / 2) * ((N + 1) / 2);
    printf("%lld", result);    
    return 0;
}
