#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int player() {
    int choice;
    printf("Выберите:\n");
    printf("0 - Камень\n");
    printf("1 - Ножницы\n");
    printf("2 - Бумага\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);
    return choice;
}
void winner(int user, int computer) {
    printf("Компьютер выбрал: ");
    if (computer == 0) {
        printf("Камень\n");
    }
    else if (computer == 1) {
        printf("Ножницы\n");
    }
    else {
        printf("Бумага\n");
    }

    if (user == computer) {
        printf("Ничья\n");
    }
    else if ((user == 0 && computer == 1) ||
        (user == 1 && computer == 2) ||
        (user == 2 && computer == 0)) {
        printf("Вы выиграли :)\n");
    }
    else {
        printf("Компьютер выиграл :(\n");
    }
}
int main() {
    srand(time(0));
    setlocale(LC_CTYPE, "RUS");

    int user, computer;
    
    user = player();
    computer = rand() % 3;
    winner(user, computer);
    return 0;
}

