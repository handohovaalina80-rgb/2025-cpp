#include<stdio.h>

int main(int argc, char** argv)
{
    long long n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld", 1 + (n - 1) * (m - 1));
    return 0;
}
