#include <stdio.h>
#include <locale.h>

int task()
{
	setlocale(LC_CTYPE, "RUS");
	int a, b, c, max1, max2;
	printf("������� ����� �: ");
	scanf("%d", &a);
	printf("������� ����� b: ");
	scanf("%d", &b);
	printf("������� ����� c: ");
	scanf("%d", &c);
	if (a > b)
	{
		if (a > c)
		{
			max1 = a;
			max2 = b > c ? b : c;
		}
		else
		{
			max1 = c;
			max2 = a;
		}
	}
	else
	{
		if (b > c)
		{
			max1 = b;
			max2 = a > c ? a : c;
		}
		else
		{
			max1 = c;
			max2 = b;
		}

	}
	int d = max1 * max2;
	printf("������������ ���� ���������� ����� �����: %d\n ", d);


}
void main()
{
	task();
}