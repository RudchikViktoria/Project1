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

// ������� �������� �����������
void check_temperature(Camera* cameras, int camera_count) {
    printf("\n���������� ����������:\n");
    for (int i = 0; i < camera_count; i++) {
        float temp = cameras[i].temperature;
        float lower = cameras[i].lower_limit;
        float upper = cameras[i].upper_limit;

        float deviation_3 = (upper - lower) * 0.03;
        float deviation_10 = (upper - lower) * 0.10;
        float deviation_25 = (upper - lower) * 0.25;

        if (temp < lower - deviation_3 || temp > upper + deviation_3) {
            printf("������ ID %d: ���������� �� 3%% (�������: %.2f, ��������: %.2f - %.2f)\n", cameras[i].id, temp, lower, upper);
        }
        if (temp < lower - deviation_10 || temp > upper + deviation_10) {
            printf("������ ID %d: ���������� �� 10%% (�������: %.2f, ��������: %.2f - %.2f)\n", cameras[i].id, temp, lower, upper);
        }
        if (temp < lower - deviation_25 || temp > upper + deviation_25) {
            printf("������ ID %d: ���������� �� 25%% (�������: %.2f, ��������: %.2f - %.2f)\n", cameras[i].id, temp, lower, upper);
        }
    }
}

// ������� ��������� ���������� ����������
void update_limits(Camera* cameras, int camera_count) {
    int id;
    printf("\n������� ID ������ ��� ���������: ");
    scanf("%d", &id);

    for (int i = 0; i < camera_count; i++) {
        if (cameras[i].id == id) {
            printf("������� �������� ��� ������ %d: %.2f - %.2f\n", id, cameras[i].lower_limit, cameras[i].upper_limit);
            printf("������� ����� ������ ������: ");
            scanf("%f", &cameras[i].lower_limit);
            printf("������� ����� ������� ������: ");
            scanf("%f", &cameras[i].upper_limit);
            printf("�������� ��������!\n");
            return;
        }
    }
    printf("������ � ID %d �� �������.\n", id);
}

// ������� ������ ������ �� �����
int read_data_from_file(const char* filename, Camera* cameras) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("������ �������� ����� %s\n", filename);
        return 0;
    }

    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d-%f", &cameras[count].id, &cameras[count].temperature) == 2) {
            cameras[count].lower_limit = -20.0;  // ����������� �������
            cameras[count].upper_limit = 5.0;
            count++;
        }
    }
    fclose(file);
    return count;
}

// ������� �������
int main() {
    setlocale(LC_CTYPE, "RUS");
    Camera cameras[MAX_CAMERAS];
    int camera_count = 0;
    int choice;
    int monitoring_enabled = 0;

    // ������ ������ �� �����
    camera_count = read_data_from_file("myfile.txt", cameras);
    if (camera_count == 0) {
        printf("��� ������ ��� ���������.\n");
        return 1;
    }

    do {
        printf("\n�������� �����:\n");
        printf("1. ��������/��������� ����������\n");
        printf("2. ��������� ���������� �����������\n");
        printf("3. ��������� ����������\n");
        printf("0. �����\n");
        printf("��� �����: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            monitoring_enabled = !monitoring_enabled;
            printf("���������� %s\n", monitoring_enabled ? "�������" : "��������");
            break;
        case 2:
            update_limits(cameras, camera_count);
            break;
        case 3:
            if (monitoring_enabled) {
                check_temperature(cameras, camera_count);
            }
            else {
                printf("���������� ��������. �������� ��� ��� ���������� ��������.\n");
            }
            break;
        case 0:
            printf("����� �� ���������.\n");
            break;
        default:
            printf("�������� �����. ���������� �����.\n");
        }
    } while (choice != 0);

    return 0;
}