#include<stdio.h>

int main(int argc, char** argv)
{
    FILE *input = fopen("INPUT.TXT", "r");
    FILE *output = fopen("OUTPUT.TXT", "w");
    
    int V, T;
    fscanf(input, "%d %d", &V, &T);
    
    // Вычисляем пройденное расстояние
    int distance = V * T;
    
    // Вычисляем позицию на круге (1..109)
    // Сначала находим остаток от деления на 109
    int position = distance % 109;
    
    // Если остаток отрицательный, делаем его положительным
    if (position < 0) {
        position = 109 + position;
    }
    
    // Переводим в диапазон 1..109 (а не 0..108)
    position = position % 109;
    if (position == 0) {
        position = 109;
    }
    
    fprintf(output, "%d", position);
    
    fclose(input);
    fclose(output);
    return 0;
}
