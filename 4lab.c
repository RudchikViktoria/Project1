#include <stdio.h>
#include <locale.h>


void task4_1()
{
	setlocale(LC_CTYPE, "RUS");

	char c = '!';
	int i = 2;
	float f = 3.14f;
	double d = 5e-12;
	int b, z;

	printf("Символ %с \nЦелое число %i \nЧисло с плавающей точкой %f, \nДабл %lf", c, i, f, d);

	puts("\nВведите значения");

	scanf("%c", &c);
	scanf("%i", &i);
	scanf("%f", &f);
	scanf("%d", &d);
	b=f
	z=f-b
	printf("\nСимвол %c\nЦелое число %d\nЦелая часть вещественного числа %d\nДробная часть вещественного числа %0.5f\n ", c,i,b,z );

	

	

	

}
int main()
{
	task4_1();
}