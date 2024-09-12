#include <stdio.h>
#include <locale.h>
int main()
{
	task1();


}

int task1()
{
	setlocale(LC_CTYPE, "RUS");

	printf("123\n");
	printf("\n");
	printf("\n");
	printf("1\n2\n3\n");

	printf("%d\n \t%d\n \t\t%d\n \t\t\t%d", 1, 2, 3, 4);

	printf("\n%10.5f\n ", 12.234657);

	printf("Остаток от деления %d на %d равен %d\n ", 7, 5, 7 % 5);

	printf("Умножение %d на %d равно %d\n", 2000, 4, 2000 * 4);

	printf("%e разделить на %e равно %e\n ", 5., 2., 5. / 2);
}
int task2()
{
	setlocale(LC_CTYPE, "RUS");

	

}




