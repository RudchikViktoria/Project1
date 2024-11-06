#include <stdio.h>
#include<locale.h>
#include <stdlib.h>
#define N 1000 

double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);
int find_min_index(double* ptr_array, int n);

int main() {
    setlocale(LC_ALL, "RUS");
    double array[N];
    int size;

    printf("¬ведите размер массива > ");
    scanf("%d", &size);

    full_elements(array, size);
    put_elements(array, size);
    calc_elements(array, size);

    int begin, end;
    printf("\n¬ведите начальный индекс дл€ суммы: ");
    scanf("%d", &begin);
    printf("¬ведите конечный индекс дл€ суммы: ");
    scanf("%d", &end);
    if (begin < 0 || end >= size || begin > end) {
        printf("ќшибка");
    }
    else {
        double sum = sum_elements(array, begin, end);
        printf("—умма элементов от индекса %d до %d: %.2lf", begin, end, sum);
    }

    double elementfind;
    printf("\n¬ведите элемент дл€ поиска: ");
    scanf("%lf", &elementfind);
    int foundindex = find_element(array, size, elementfind);
    if (foundindex != -1) {
        printf("Ёлемент %.2lf найден на индексе %d", elementfind, foundindex);
    }
    else {
        printf("Ёлемент %.2lf не найден", elementfind);
    }

    int min_index = find_min_index(array, size);
    printf("\n»ндекс минимального элемента: %d\n", min_index);

}


// 8 lab 2 zadanie
double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        float x = 0 + i ; 
        ptr_array[i] = 5 * x * x * x + 2 * x * x - 15 * x - 6;
    }
}

int put_elements(double* ptr_array, int n) {
    printf("Ёлементы массива: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", ptr_array[i]);
    }
    printf("\n");
}

//”двоить значение каждого элемента
double* calc_elements(double* ptr_array, int n) {
    printf("ќбработанные элементы массива: ");
    for (int i = 0; i < n; i++) {
        ptr_array[i] *= 2; 
        printf("%.2f", ptr_array[i]);
    }
}

double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

int find_element(double* ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] == element) {
            return i;
        }
    }
    return -1;
}
//3 zadanie определение индекса минимального элемента
int find_min_index(double* ptr_array, int n) {
    int min_index = 0; //индекс
    double minznach = ptr_array[0]; //значение
    for (int i = 1; i < n; i++) {
        if (ptr_array[i] < minznach) {
            minznach = ptr_array[i];
            min_index = i; 
        }
    }
    return min_index; 
}


