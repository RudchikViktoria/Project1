#include <stdio.h>
#include <locale.h>

void home_task2_3() 
{
    int l = 213;
    int n = 3;
    float L = 213;
    float N = 3;

    printf("Дано:\n%12d\n%12d\n\t________\nОтвет:\n\t+0%2.2f", n, l, N / L);

}


void home_task3_dz()
{
    double a;
    double radius_vpis; 
    double radius_opis; 

    
    printf("\n\n\nВведите сторону квадрата: ");
    scanf("%lf", &a);


    radius_vpis = a / 2;
    radius_opis = a / sqrt(2);

   
    printf("Радиус вписанной окружности: %.2lf\n", radius_vpis);
    printf("Радиус описанной окружности: %.2lf\n", radius_opis);

}



#define      D       1.852
#define      C       7.468
#define      B       7.412
void home_task3_2()
{
    int km;
    float result;
    float result1;
    float result2;
    puts("Введите значение в км:");
    scanf("\n\n%d", &km);
    result = D * km;
    result1 = C * km;
    result2 = B * km;
    printf("\n\n%d км - это %.1f морских миль\n%d км - это %.1f старорусских миль\n%d км - это %.1f географических миль", km, result, km, result1, km, result2);
}



int main() 
{
    setlocale(LC_ALL, "RUS");
    home_task2_3();
    home_task3_dz();
    home_task3_2();
}
