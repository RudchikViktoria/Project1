#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int player() {
    int choice;
    printf("��������:\n");
    printf("0 - ������\n");
    printf("1 - �������\n");
    printf("2 - ������\n");
    printf("��� �����: ");
    scanf("%d", &choice);
    return choice;
}
void winner(int user, int computer) {
    printf("��������� ������: ");
    if (computer == 0) {
        printf("������\n");
    }
    else if (computer == 1) {
        printf("�������\n");
    }
    else {
        printf("������\n");
    }

    if (user == computer) {
        printf("�����\n");
    }
    else if ((user == 0 && computer == 1) ||
        (user == 1 && computer == 2) ||
        (user == 2 && computer == 0)) {
        printf("�� �������� :)\n");
    }
    else {
        printf("��������� ������� :(\n");
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

