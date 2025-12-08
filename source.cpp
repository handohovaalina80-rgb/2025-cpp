#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

// Структура для хранения достопримечательностей
typedef struct {
    char name[100];      // название достопримечательности
    int year;            // год создания
} Attraction;

// Структура для хранения списка достопримечательностей города
typedef struct {
    Attraction* attractions;  // динамический массив достопримечательностей
    int count;                // количество достопримечательностей
    int capacity;             // вместимость массива
} AttractionList;

// Структура для города
typedef struct {
    char name[50];       // название города
    char country[50];    // страна
    AttractionList list; // список достопримечательностей
} City;

// Функции для работы с AttractionList (аналог Gradebook)
void init_attraction_list(AttractionList* al) {
    al->count = 0;
    al->capacity = 5;
    al->attractions = (Attraction*)malloc(al->capacity * sizeof(Attraction));
}

void add_attraction(AttractionList* al, const char* name, int year) {
    // Если массив заполнен, увеличиваем его размер
    if (al->count >= al->capacity) {
        al->capacity *= 2;
        al->attractions = (Attraction*)realloc(al->attractions, 
                                              al->capacity * sizeof(Attraction));
    }
    
    strcpy(al->attractions[al->count].name, name);
    al->attractions[al->count].year = year;
    al->count++;
}

void free_attraction_list(AttractionList* al) {
    free(al->attractions);
    al->attractions = NULL;
    al->count = 0;
    al->capacity = 0;
}

// Функции для работы с городами
City* create_cities(int n) {
    City* cities = (City*)malloc(n * sizeof(City));
    for (int i = 0; i < n; i++) {
        init_attraction_list(&cities[i].list);
    }
    return cities;
}

// Найти город с наибольшим количеством достопримечательностей
City* find_city_with_most_attractions(City* cities, int n) {
    if (n <= 0) return NULL;
    
    City* best = &cities[0];
    for (int i = 1; i < n; i++) {
        if (cities[i].list.count > best->list.count) {
            best = &cities[i];
        }
    }
    return best;
}

void print_city(const City* city) {
    printf("Город: %s, Страна: %s\n", city->name, city->country);
    printf("Количество достопримечательностей: %d\n", city->list.count);
    
    if (city->list.count > 0) {
        printf("Достопримечательности:\n");
        for (int i = 0; i < city->list.count; i++) {
            printf("  %d. %s (год создания: %d)\n", 
                   i + 1, 
                   city->list.attractions[i].name, 
                   city->list.attractions[i].year);
        }
    }
    printf("\n");
}

void free_cities(City* cities, int n) {
    for (int i = 0; i < n; i++) {
        free_attraction_list(&cities[i].list);
    }
    free(cities);
}

void clear_input_buffer() {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void clear_last_linebreak(char* str) {
    if (str != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }
}

int main(int argc, char** argv) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int n = 0;
    printf("Введите количество городов: ");
    scanf("%d", &n);
    clear_input_buffer();
    
    City* cities = create_cities(n);
    
    // Ввод данных о городах
    for (int i = 0; i < n; i++) {
        printf("\nГород %d:\n", i + 1);
        
        printf("Название города: ");
        fgets(cities[i].name, sizeof(cities[i].name), stdin);
        clear_last_linebreak(cities[i].name);
        
        printf("Страна: ");
        fgets(cities[i].country, sizeof(cities[i].country), stdin);
        clear_last_linebreak(cities[i].country);
        
        int attraction_count = 0;
        printf("Количество достопримечательностей: ");
        scanf("%d", &attraction_count);
        clear_input_buffer();
        
        printf("Введите %d достопримечательностей:\n", attraction_count);
        for (int j = 0; j < attraction_count; j++) {
            char name[100];
            int year;
            
            printf("  Достопримечательность %d:\n", j + 1);
            printf("    Название: ");
            fgets(name, sizeof(name), stdin);
            clear_last_linebreak(name);
            
            printf("    Год создания: ");
            scanf("%d", &year);
            clear_input_buffer();
            
            add_attraction(&cities[i].list, name, year);
        }
    }
    
    // Вывод всех городов
    printf("\n=== Все города ===\n");
    for (int i = 0; i < n; i++) {
        printf("\nГород %d:\n", i + 1);
        print_city(&cities[i]);
    }
    
    // Поиск города с наибольшим количеством достопримечательностей
    City* best = find_city_with_most_attractions(cities, n);
    if (best) {
        printf("\n=== Город с наибольшим количеством достопримечательностей ===\n");
        print_city(best);
    }
    
    free_cities(cities, n);
    return 0;
}