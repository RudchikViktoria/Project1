#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_CAMERAS 100
#define MAX_LINE_LENGTH 50

typedef struct {
    int id;
    float temperature;
    float lower_limit;
    float upper_limit;
} Camera;

// Функция проверки температуры
void check_temperature(Camera* cameras, int camera_count) {
    printf("\nМониторинг температур:\n");
    for (int i = 0; i < camera_count; i++) {
        float temp = cameras[i].temperature;
        float lower = cameras[i].lower_limit;
        float upper = cameras[i].upper_limit;

        float deviation_3 = (upper - lower) * 0.03;
        float deviation_10 = (upper - lower) * 0.10;
        float deviation_25 = (upper - lower) * 0.25;

        if (temp < lower - deviation_3 || temp > upper + deviation_3) {
            printf("Камера ID %d: Отклонение на 3%% (текущая: %.2f, диапазон: %.2f - %.2f)\n", cameras[i].id, temp, lower, upper);
        }
        if (temp < lower - deviation_10 || temp > upper + deviation_10) {
            printf("Камера ID %d: Отклонение на 10%% (текущая: %.2f, диапазон: %.2f - %.2f)\n", cameras[i].id, temp, lower, upper);
        }
        if (temp < lower - deviation_25 || temp > upper + deviation_25) {
            printf("Камера ID %d: Отклонение на 25%% (текущая: %.2f, диапазон: %.2f - %.2f)\n", cameras[i].id, temp, lower, upper);
        }
    }
}

// Функция изменения диапазонов температур
void update_limits(Camera* cameras, int camera_count) {
    int id;
    printf("\nВведите ID камеры для настройки: ");
    scanf("%d", &id);

    for (int i = 0; i < camera_count; i++) {
        if (cameras[i].id == id) {
            printf("Текущий диапазон для камеры %d: %.2f - %.2f\n", id, cameras[i].lower_limit, cameras[i].upper_limit);
            printf("Введите новый нижний предел: ");
            scanf("%f", &cameras[i].lower_limit);
            printf("Введите новый верхний предел: ");
            scanf("%f", &cameras[i].upper_limit);
            printf("Диапазон обновлен!\n");
            return;
        }
    }
    printf("Камера с ID %d не найдена.\n", id);
}

// Функция чтения данных из файла
int read_data_from_file(const char* filename, Camera* cameras) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Ошибка открытия файла %s\n", filename);
        return 0;
    }

    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d-%f", &cameras[count].id, &cameras[count].temperature) == 2) {
            cameras[count].lower_limit = -20.0;  // Стандартные пределы
            cameras[count].upper_limit = 5.0;
            count++;
        }
    }
    fclose(file);
    return count;
}

// Главная функция
int main() {
    setlocale(LC_CTYPE, "RUS");
    Camera cameras[MAX_CAMERAS];
    int camera_count = 0;
    int choice;
    int monitoring_enabled = 0;

    // Чтение данных из файла
    camera_count = read_data_from_file("myfile.txt", cameras);
    if (camera_count == 0) {
        printf("Нет данных для обработки.\n");
        return 1;
    }

    do {
        printf("\nВыберите режим:\n");
        printf("1. Включить/выключить мониторинг\n");
        printf("2. Настройка диапазонов температуры\n");
        printf("3. Выполнить мониторинг\n");
        printf("0. Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            monitoring_enabled = !monitoring_enabled;
            printf("Мониторинг %s\n", monitoring_enabled ? "включен" : "выключен");
            break;
        case 2:
            update_limits(cameras, camera_count);
            break;
        case 3:
            if (monitoring_enabled) {
                check_temperature(cameras, camera_count);
            }
            else {
                printf("Мониторинг отключен. Включите его для выполнения проверки.\n");
            }
            break;
        case 0:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}