#include<stdio.h>

int main(int argc, char** argv)
{
    int K, N;
    scanf("%d %d", &K, &N);
    
    int page = (N - 1) / K + 1;
    int line_on_page = (N - 1) % K + 1;
    
    printf("%d %d", page, line_on_page);
    
    return 0;
}
