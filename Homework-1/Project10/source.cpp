#include<stdio.h>

int main(int argc, char** argv)
{
    FILE *input = fopen("INPUT.TXT", "r");
    FILE *output = fopen("OUTPUT.TXT", "w");
    
    long long a, b, c;
    fscanf(input, "%lld %lld %lld", &a, &b, &c);
    
    long long sum = a + b + c;
    fprintf(output, "%lld", sum);
    
    fclose(input);
    fclose(output);
    return 0;
}
