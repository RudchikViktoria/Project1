#include <stdio.h>
#include <locale.h>  
#include <stdlib.h>
#include <math.h>

double* full_elements(double* ptr_array, int n);
int calc_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int size);
double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        double x = 0 + i;
        ptr_array[i] = 5 * pow(x,3) + 2 * pow(x,2) -15 * x - 65 * pow(x,3) + 2 * pow(x,2)- 15 * x - 6;
    }
    return ptr_array;
}
int calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i += 2) {
        ptr_array[i] *= 2;
    }
    return ptr_array;
}
int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", ptr_array[i]);
    }
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    double* ptr_array;
    int size;
    printf("Введите размер массива : ");
    scanf("%d", &size);
    ptr_array = (double*)malloc(size * sizeof(double));

    if (ptr_array == NULL) {
        puts("error");
        return -1;
    }
    printf("\nИсходный массив\n");
    full_elements(ptr_array, size);
    put_elements(ptr_array, size);
    printf("\nОбработанный массив\n");
    calc_elements(ptr_array, size);
    put_elements(ptr_array, size);
    free(ptr_array);
}
