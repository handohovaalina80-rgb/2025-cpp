#include <stdio.h>
#include <math.h>

int main() {
    double x, result;
    
    printf("Введите значение x: ");
    scanf("%lf", &x);
    
    result = sin(x*x - 3*x + 2);
    
    printf("sin(x^2 - 3x + 2) в точке x = %.4lf равно: %.6lf\n", x, result);
    
    return 0;
}