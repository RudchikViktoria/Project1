//variant E14

#include<stdio.h>
#include<locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_CAMERAS 50
#define MAX_DLINA 50
//Структура для холодильных камер
typedef struct {
    int id; //значение ID камеры
    float temperature; //значение температуры в камере
    float low_limit; //верхний предел температуры
    float up_limit; //нижний предел температуры
} Camera;

//Прототипы функций
int read_file(const char* filename, Camera* cameras);
void checktemperature(Camera* cameras, int camera_count);
void data(char* buffer, size_t size);
void log_changes(int camera_id, const char* user);
void update_limit(Camera* cameras, int camera_count);
void history();
void add_new_camera(Camera* cameras, int *camera_count);


//Главная функция
int main()
{
    setlocale(LC_CTYPE, "RUS");
    printf("**************************************************\n");
    printf("*    Добро пожаловать в 'Фригомонитор'!          *\n");
    printf("*   Ваш надежный помощник в мониторинге холода!  *\n");
    printf("*   Контролируйте температуру, избегайте аварий! *\n");
    printf("**************************************************\n");
    getchar();

    Camera cameras[MAX_CAMERAS];
    int camera_count = 0; //счетчик холодильных камер
    int choice; //выбор из меню

    //Чтение данных из файла
    camera_count = read_file("myfile.txt", cameras);
    if (camera_count == 0) {
        printf("Нет данных\n");
    }
 
    //Меню программы
    do {
        printf("\nВыберите режим работы: \n");
        printf("1 > Включить мониторинг\n");
        printf("2 > Настроить диапазоны температуры\n");
        printf("3 > Просмотреть историю изменений диапазонов температуры\n");
        printf("4 > Добавить холодильную камеру\n");
        printf("0 > Выход\n");
        printf("Ваш выбор > \n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            checktemperature(cameras, camera_count); //проверка температуры на отклонения
            break;
        case 2:
            update_limit(cameras, camera_count); //пользователь вводит новый диапазон температуры для камеры
            break;
        case 3:
            history(); //просмотр истории изменений диапазонов температур
            break;
        case 4:
            add_new_camera(cameras, &camera_count); //добавление новой камеры
            break;
        case 0:
            printf("Выход из программы\n");
            break;
        default:
            printf("Неверный выбор\n");
        }
    } while (choice != 0);
    return 0;
}

//Функция чтения файла с данными о камерах
int read_file(const char* filename, Camera* cameras) {
    FILE* file = fopen("myfile.txt", "r");
    if (file == NULL) {
        puts("Ошибка открытия файла");
    }
    int count = 0;
    char line[MAX_DLINA];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d-%f", &cameras[count].id, &cameras[count].temperature) == 2) {
            cameras[count].low_limit = -20;
            cameras[count].up_limit = 5;
            count++;
        }
    }
    fclose(file);
    return count;
}

//Функция для вычисления отклонений температур от заданных порогов
void checktemperature(Camera* cameras, int camera_count)
{
    printf("\nПроверка отклонений температуры в холодильных камерах: \n");
    for (int i = 0; i < camera_count; i++) {
        //запись температуры текущей камеры 
        float temp = cameras[i].temperature;
        float low = cameras[i].low_limit;
        float up = cameras[i].up_limit;

        float otcl_3 = (up - low) * 0.03;
        float otcl_10 = (up - low) * 0.1;
        float otcl_25 = (up - low) * 0.25;
        float procent = 0;

        if (temp < low - otcl_25 || temp > up + otcl_25) {
            procent = 25;
        }
        else if (temp < low - otcl_10 || temp > up + otcl_10) {
            procent = 10;
        }
        else if (temp < low - otcl_3 || temp > up + otcl_3) {
            procent = 3;
        }
        if (procent > 0) {
            printf("Камера ID %d: отклонение на %.0f% (текущая: %.2f, диапазон %.2f - %.2f)\n", cameras[i].id, procent, temp, low, up);
        }
    }
}

//Функция для указания даты и времени
void data(char* buffer, size_t size) { 
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t); //преобразование текущего времени в локальное время и хранение его в структуре tm
    strftime(buffer, size, "%d-%m-%Y %H:%M:%S", tm_info); //заполнение буфера
}

//Функция для записи изменений диапазонов температур в новый файл
void log_changes(int camera_id, const char* user) { 
    FILE* log_file = fopen("история.txt", "a");
    if (log_file == NULL) {
        puts("Ошибка открытия файла");
    }

    char datatime[50];
    data(datatime, sizeof(datatime));

    fprintf(log_file, "Дата изменения диапазона: %s, Камера ID: %d, Ответственный: %s\n", datatime, camera_id, user);
    fclose(log_file);
}

//Функция для изменения диапазона температуры в камере
void update_limit(Camera* cameras, int camera_count) {
    int id;
    char user[50]; //массив символов для хранения имени ответственного
    printf("\nВведите ID камеры для изменения диапазона температуры: \n");
    scanf("%d", &id);

    for (int i = 0; i < camera_count; i++) {
        if (cameras[i].id == id) { //проверка на наличие камеры
            printf("Текущий диапазон для камеры %d: %.2f - %.2f\n", id, cameras[i].low_limit, cameras[i].up_limit);
            printf("Введите новый нижний предел: ");
            float new_low_limit;
            scanf("%f", &new_low_limit);
            printf("Введите новый верхний предел: ");
            float new_up_limit;
            scanf("%f", &new_up_limit);
            printf("Введите имя ответственного: ");
            scanf("%s", &user);

            log_changes(id, user); //запись в историю изменений ID камеры и ответственного

            //обновление нижнего и верхнего предела для камеры
            cameras[i].low_limit = new_low_limit;
            cameras[i].up_limit = new_up_limit;
            puts("Диапазон успешно обновлен!\n");
            return;
        }
    }
    printf("Камера с ID %d не найдена\n", id);
}


//Функция для просмотра истории изменений диапазонов температур
void history() { 
    FILE* log = fopen("история.txt", "r");
    if (log == NULL) {
        printf("Ошибка открытия файла");
    }
    char line[100]; //массив символов для хранения строк с файла
    printf("История изменений диапазона температур: \n");
    while (fgets(line, sizeof(line), log)) { //считывает строки и помещает их в массив
        printf("%s", line);
    }
    fclose(log);
}

//Функция для добавления камеры
void add_new_camera(Camera* cameras, int *camera_count) { 
    if (*camera_count >= MAX_CAMERAS) {
        printf("Достигнуто максимальное количество холодильных камер");
        return;
    }
    //объявление переменных для хранения данных новой камеры
    int id;
    float temperature;
    float low_limit;
    float up_limit;
    printf("Введите ID новой камеры: ");
    scanf("%d", &id);
    
    for (int i = 0; i < *camera_count; i++) {
        if (cameras[i].id == id) {
            printf("Камера с таким ID уже существует\n");
            return;
        }
    }
    
    printf("Введите текущую температуру камеры: "); 
    scanf("%f", &temperature); 
    printf("Введите нижний предел температуры: "); 
    scanf("%f", &low_limit); 
    printf("Введите верхний предел температуры: "); 
    scanf("%f", &up_limit);
    cameras[*camera_count].id = id; 
    cameras[*camera_count].temperature = temperature; 
    cameras[*camera_count].low_limit = low_limit; 
    cameras[*camera_count].up_limit = up_limit; 
    (*camera_count)++;

    //добавление данных о новой камере в файл
    FILE* file = fopen("myfile.txt", "a"); 
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }
    fprintf(file, "%d-%f\n", id, temperature);
    fclose(file);

    printf("Камера ID %d успешно добавлена\n", id); 
}



