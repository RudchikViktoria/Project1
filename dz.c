#include <stdio.h>
#include <locale.h>

void home_task2_3() 
{
    int l = 213;
    int n = 3;
    float L = 213;
    float N = 3;

    printf("����:\n%12d\n%12d\n\t________\n�����:\n\t+0%2.2f", n, l, N / L);

}


void home_task3_dz()
{
    double a;
    double radius_vpis; 
    double radius_opis; 

    
    printf("\n\n\n������� ������� ��������: ");
    scanf("%lf", &a);


    radius_vpis = a / 2;
    radius_opis = a / sqrt(2);

   
    printf("������ ��������� ����������: %.2lf\n", radius_vpis);
    printf("������ ��������� ����������: %.2lf\n", radius_opis);

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
    puts("������� �������� � ��:");
    scanf("\n\n%d", &km);
    result = D * km;
    result1 = C * km;
    result2 = B * km;
    printf("\n\n%d �� - ��� %.1f ������� ����\n%d �� - ��� %.1f ������������ ����\n%d �� - ��� %.1f �������������� ����", km, result, km, result1, km, result2);
}



int main() 
{
    setlocale(LC_ALL, "RUS");
    home_task2_3();
    home_task3_dz();
    home_task3_2();
}
