//variant E14

#include<stdio.h>
#include<locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_CAMERAS 50
#define MAX_DLINA 50
//��������� ��� ����������� �����
typedef struct {
    int id; //�������� ID ������
    float temperature; //�������� ����������� � ������
    float low_limit; //������� ������ �����������
    float up_limit; //������ ������ �����������
} Camera;

//��������� �������
int read_file(const char* filename, Camera* cameras);
void checktemperature(Camera* cameras, int camera_count);
void data(char* buffer, size_t size);
void log_changes(int camera_id, const char* user);
void update_limit(Camera* cameras, int camera_count);
void history();
void add_new_camera(Camera* cameras, int *camera_count);


//������� �������
int main()
{
    setlocale(LC_CTYPE, "RUS");
    printf("**************************************************\n");
    printf("*    ����� ���������� � '������������'!          *\n");
    printf("*   ��� �������� �������� � ����������� ������!  *\n");
    printf("*   ������������� �����������, ��������� ������! *\n");
    printf("**************************************************\n");
    getchar();

    Camera cameras[MAX_CAMERAS];
    int camera_count = 0; //������� ����������� �����
    int choice; //����� �� ����

    //������ ������ �� �����
    camera_count = read_file("myfile.txt", cameras);
    if (camera_count == 0) {
        printf("��� ������\n");
    }
 
    //���� ���������
    do {
        printf("\n�������� ����� ������: \n");
        printf("1 > �������� ����������\n");
        printf("2 > ��������� ��������� �����������\n");
        printf("3 > ����������� ������� ��������� ���������� �����������\n");
        printf("4 > �������� ����������� ������\n");
        printf("0 > �����\n");
        printf("��� ����� > \n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            checktemperature(cameras, camera_count); //�������� ����������� �� ����������
            break;
        case 2:
            update_limit(cameras, camera_count); //������������ ������ ����� �������� ����������� ��� ������
            break;
        case 3:
            history(); //�������� ������� ��������� ���������� ����������
            break;
        case 4:
            add_new_camera(cameras, &camera_count); //���������� ����� ������
            break;
        case 0:
            printf("����� �� ���������\n");
            break;
        default:
            printf("�������� �����\n");
        }
    } while (choice != 0);
    return 0;
}

//������� ������ ����� � ������� � �������
int read_file(const char* filename, Camera* cameras) {
    FILE* file = fopen("myfile.txt", "r");
    if (file == NULL) {
        puts("������ �������� �����");
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

//������� ��� ���������� ���������� ���������� �� �������� �������
void checktemperature(Camera* cameras, int camera_count)
{
    printf("\n�������� ���������� ����������� � ����������� �������: \n");
    for (int i = 0; i < camera_count; i++) {
        //������ ����������� ������� ������ 
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
            printf("������ ID %d: ���������� �� %.0f% (�������: %.2f, �������� %.2f - %.2f)\n", cameras[i].id, procent, temp, low, up);
        }
    }
}

//������� ��� �������� ���� � �������
void data(char* buffer, size_t size) { 
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t); //�������������� �������� ������� � ��������� ����� � �������� ��� � ��������� tm
    strftime(buffer, size, "%d-%m-%Y %H:%M:%S", tm_info); //���������� ������
}

//������� ��� ������ ��������� ���������� ���������� � ����� ����
void log_changes(int camera_id, const char* user) { 
    FILE* log_file = fopen("�������.txt", "a");
    if (log_file == NULL) {
        puts("������ �������� �����");
    }

    char datatime[50];
    data(datatime, sizeof(datatime));

    fprintf(log_file, "���� ��������� ���������: %s, ������ ID: %d, �������������: %s\n", datatime, camera_id, user);
    fclose(log_file);
}

//������� ��� ��������� ��������� ����������� � ������
void update_limit(Camera* cameras, int camera_count) {
    int id;
    char user[50]; //������ �������� ��� �������� ����� ��������������
    printf("\n������� ID ������ ��� ��������� ��������� �����������: \n");
    scanf("%d", &id);

    for (int i = 0; i < camera_count; i++) {
        if (cameras[i].id == id) { //�������� �� ������� ������
            printf("������� �������� ��� ������ %d: %.2f - %.2f\n", id, cameras[i].low_limit, cameras[i].up_limit);
            printf("������� ����� ������ ������: ");
            float new_low_limit;
            scanf("%f", &new_low_limit);
            printf("������� ����� ������� ������: ");
            float new_up_limit;
            scanf("%f", &new_up_limit);
            printf("������� ��� ��������������: ");
            scanf("%s", &user);

            log_changes(id, user); //������ � ������� ��������� ID ������ � ��������������

            //���������� ������� � �������� ������� ��� ������
            cameras[i].low_limit = new_low_limit;
            cameras[i].up_limit = new_up_limit;
            puts("�������� ������� ��������!\n");
            return;
        }
    }
    printf("������ � ID %d �� �������\n", id);
}


//������� ��� ��������� ������� ��������� ���������� ����������
void history() { 
    FILE* log = fopen("�������.txt", "r");
    if (log == NULL) {
        printf("������ �������� �����");
    }
    char line[100]; //������ �������� ��� �������� ����� � �����
    printf("������� ��������� ��������� ����������: \n");
    while (fgets(line, sizeof(line), log)) { //��������� ������ � �������� �� � ������
        printf("%s", line);
    }
    fclose(log);
}

//������� ��� ���������� ������
void add_new_camera(Camera* cameras, int *camera_count) { 
    if (*camera_count >= MAX_CAMERAS) {
        printf("���������� ������������ ���������� ����������� �����");
        return;
    }
    //���������� ���������� ��� �������� ������ ����� ������
    int id;
    float temperature;
    float low_limit;
    float up_limit;
    printf("������� ID ����� ������: ");
    scanf("%d", &id);
    
    for (int i = 0; i < *camera_count; i++) {
        if (cameras[i].id == id) {
            printf("������ � ����� ID ��� ����������\n");
            return;
        }
    }
    
    printf("������� ������� ����������� ������: "); 
    scanf("%f", &temperature); 
    printf("������� ������ ������ �����������: "); 
    scanf("%f", &low_limit); 
    printf("������� ������� ������ �����������: "); 
    scanf("%f", &up_limit);
    cameras[*camera_count].id = id; 
    cameras[*camera_count].temperature = temperature; 
    cameras[*camera_count].low_limit = low_limit; 
    cameras[*camera_count].up_limit = up_limit; 
    (*camera_count)++;

    //���������� ������ � ����� ������ � ����
    FILE* file = fopen("myfile.txt", "a"); 
    if (file == NULL) {
        printf("������ �������� �����\n");
        return;
    }
    fprintf(file, "%d-%f\n", id, temperature);
    fclose(file);

    printf("������ ID %d ������� ���������\n", id); 
}



