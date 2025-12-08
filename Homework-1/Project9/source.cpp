#include<stdio.h>

int main(int argc, char** argv)
{
    int a;
    scanf("%d", &a);
    int time_saved = (a - 1) * 5;   
    printf("%d", time_saved);
    return 0;
}
