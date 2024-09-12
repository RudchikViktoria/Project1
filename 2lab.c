#include <stdio.h>
#include <locale.h>

int main()
{
	
	getchar();
	task2();


}

int task1()
{

	setlocale(LC_ALL, "RUS");
	printf("123\n");
	printf("\n");
	printf("\n");
	printf("1\n2\n3\n");
	printf("\n");
	printf("\n");
	printf("1\n\t2\n\t\t3");
	printf("\n");
	printf("%i\n%2i\n%3i\n%4i", 1, 2, 3, 4);
	printf("\n");
	printf("\n");
	printf("%10.5f\n ", 12.234657);
	printf("\n");
	printf("Остаток от деления %d на %d равен %d\n ", 7, 5, 7 % 5);
	printf("\n");
	printf("Умножение %d на %d равно %d", 2000, 4, 2000 * 4);
	printf("\n");
	printf("%e разделить %e равно %e\n", 5., 2., 5. / 2);
	printf("\n");
}
int task2()
{
	setlocale(LC_ALL, "RUS");
	int N, K;
	N = 10;
	K = 33;
	printf("Сейчас %d часов %d минут 00 секунд", N, K);
	printf("\nИдет %d минута суток", N * 60 + K);
	printf("\nДо полуночи осталось %d часов и %d минут", 23 - N, 60 - K);
	printf("\nС 8.00 прошло %i секунд", N * 60 * 60 + K * 60 - 8 * 60 * 60);
	printf("\nТекущий час = %5.2f суток и текущая минута = %5.2f часа", N / 24., K / 60.);

}

