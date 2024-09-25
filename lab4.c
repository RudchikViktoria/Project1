#include <stdio.h>
#include <locale.h>

int task1()
{
	setlocale(LC_CTYPE, "RUS");
	char c = '!';
	int i = 2;
	float f = 3.14f;
	double d = 5e-12;

	printf("Значение char: %c\n", c);
	printf("Значение int: %d\n", i);
	printf("Значение float: %.2f\n", f);
	printf("Значение double: %.12e\n", d);

	printf("\nВведите значение char: ");
	scanf("%c", &c);
	printf("Введите значение int: ");
	scanf("%d", &i);
	printf("Введите значение float: ");
	scanf("%f", &f);
	printf("Введите значение double: ");
	scanf("%lf", &d);

	printf("\nНовые значения: \n");
	printf("char: %c\n", c);
	printf("int: %d\n", i);
	printf("float: %.2f\n", f);
	printf("double: %.12e\n", d);
	double b = f - (int)f;
	printf("\nЦелая часть вещественного числа %d Остаток %g", (int)f, b);
	printf("\nШестнадцатеричный код введенного символа %X Десятичный код введенного символа %d", i, i);
	printf("\nДесятичное число, соответствующее 1/i %g", 1 /(double) i);
}

int task2()
{
	setlocale(LC_CTYPE, "RUS");
	int a = 11;
	int b = 3;
	int x;
	float y;
	double z;
	x = a / b;
	y = a / b;
	z = a / b;
	puts("\n");
	printf("x : %d\n", x); // x получен в результате целочисленного деления
	printf("y : %.2f\n", y); // y получен в результате деления с плавающей точкой
	printf("z : %.2f\n", z); // z получен в результате деления с плавающей точкой

	printf("a/b типа float: %.2f\n", (float)a / b);
	printf("a/b типа double: %.2f\n", (double)a / b);
}
int task3()
{
	setlocale(LC_CTYPE, "RUS");

	int N, num1, num3, sum;

	printf("\nВведите трехзначное целое число: ");
	scanf("%d", &N);
	num1 = N / 100;
	num3 = N % 10;
	sum = num1 + num3 + (N / 10) % 10;
	printf("Первая цифра числа: %d\n", num1);
	printf("Последняя цифра числа: %d\n", num3);
	printf("Сумма всех цифр числа: %d\n", sum);

}


void main()
{
	task1();
	task2();
	task3();
}
