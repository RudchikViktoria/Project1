#include <stdio.h>
#include <locale.h>

int main() 
{
    setlocale(LC_CTYPE, "RUS");
   //Составить программу, которая определяет порядковый номер введенной буквы в алфавите.
    char c;
    printf("Введите букву алфавита: ");
    scanf("%c", &c);

    switch (c) {
    case 'a': printf("Порядковый номер: 1\n"); break;
    case 'b': printf("Порядковый номер: 2\n"); break;
    case 'c': printf("Порядковый номер: 3\n"); break;
    case 'd': printf("Порядковый номер: 4\n"); break;
    case 'e': printf("Порядковый номер: 5\n"); break;
    case 'f': printf("Порядковый номер: 6\n"); break;
    case 'g': printf("Порядковый номер: 7\n"); break;
    case 'h': printf("Порядковый номер: 8\n"); break;
    case 'i': printf("Порядковый номер: 9\n"); break;
    case 'j': printf("Порядковый номер: 10\n"); break;
    case 'k': printf("Порядковый номер: 11\n"); break;
    case 'l': printf("Порядковый номер: 12\n"); break;
    case 'm': printf("Порядковый номер: 13\n"); break;
    case 'n': printf("Порядковый номер: 14\n"); break;
    case 'o': printf("Порядковый номер: 15\n"); break;
    case 'p': printf("Порядковый номер: 16\n"); break;
    case 'q': printf("Порядковый номер: 17\n"); break;
    case 'r': printf("Порядковый номер: 18\n"); break;
    case 's': printf("Порядковый номер: 19\n"); break;
    case 't': printf("Порядковый номер: 20\n"); break;
    case 'u': printf("Порядковый номер: 21\n"); break;
    case 'v': printf("Порядковый номер: 22\n"); break;
    case 'w': printf("Порядковый номер: 23\n"); break;
    case 'x': printf("Порядковый номер: 24\n"); break;
    case 'y': printf("Порядковый номер: 25\n"); break;
    case 'z': printf("Порядковый номер: 26\n"); break;
    default: printf("Некорректный ввод!\n"); break;
    }

}