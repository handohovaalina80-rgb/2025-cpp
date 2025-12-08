#include<stdio.h>

int main(int argc, char** argv)
{
    long long N, K;
    scanf("%lld %lld", &N, &K);
    
    // Первый способ деления
    long long apples_per_student = K / N;
    long long remaining_apples = K % N;
    
    // Второй способ деления
    long long offended_students;
    if (K % N == 0) {
        offended_students = 0;
    } else {
        offended_students = N - (K % N);
    }
    
    printf("%lld %lld %lld", apples_per_student, remaining_apples, offended_students);
    
    return 0;
}
