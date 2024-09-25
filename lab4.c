#include <stdio.h>
#include <locale.h>

int task1()
{
	setlocale(LC_CTYPE, "RUS");
	char c = '!';
	int i = 2;
	float f = 3.14f;
	double d = 5e-12;

	printf("�������� char: %c\n", c);
	printf("�������� int: %d\n", i);
	printf("�������� float: %.2f\n", f);
	printf("�������� double: %.12e\n", d);

	printf("\n������� �������� char: ");
	scanf("%c", &c);
	printf("������� �������� int: ");
	scanf("%d", &i);
	printf("������� �������� float: ");
	scanf("%f", &f);
	printf("������� �������� double: ");
	scanf("%lf", &d);

	printf("\n����� ��������: \n");
	printf("char: %c\n", c);
	printf("int: %d\n", i);
	printf("float: %.2f\n", f);
	printf("double: %.12e\n", d);
	double b = f - (int)f;
	printf("\n����� ����� ������������� ����� %d ������� %g", (int)f, b);
	printf("\n����������������� ��� ���������� ������� %X ���������� ��� ���������� ������� %d", i, i);
	printf("\n���������� �����, ��������������� 1/i %g", 1 /(double) i);
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
	printf("x : %d\n", x); // x ������� � ���������� �������������� �������
	printf("y : %.2f\n", y); // y ������� � ���������� ������� � ��������� ������
	printf("z : %.2f\n", z); // z ������� � ���������� ������� � ��������� ������

	printf("a/b ���� float: %.2f\n", (float)a / b);
	printf("a/b ���� double: %.2f\n", (double)a / b);
}
int task3()
{
	setlocale(LC_CTYPE, "RUS");

	int N, num1, num3, sum;

	printf("\n������� ����������� ����� �����: ");
	scanf("%d", &N);
	num1 = N / 100;
	num3 = N % 10;
	sum = num1 + num3 + (N / 10) % 10;
	printf("������ ����� �����: %d\n", num1);
	printf("��������� ����� �����: %d\n", num3);
	printf("����� ���� ���� �����: %d\n", sum);

}


void main()
{
	task1();
	task2();
	task3();
}
