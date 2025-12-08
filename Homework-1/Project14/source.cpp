#include<stdio.h>

int main(int argc, char** argv)
{
    FILE *input = fopen("INPUT.TXT", "r");
    FILE *output = fopen("OUTPUT.TXT", "w");
    
    long long A;
    fscanf(input, "%lld", &A);
    long long n = A / 10;
    long long temp = n * (n + 1);
    long long result = temp * 100 + 25;
    
    fprintf(output, "%lld", result);
    
    fclose(input);
    fclose(output);
    return 0;
}
