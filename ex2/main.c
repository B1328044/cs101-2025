#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[12];
    int age;
    float salary;
} employee_t;

void emp_info(employee_t emp) {
    printf("employee id = %d\n", emp.id);
    printf("employee name = %s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %.2f\n\n", emp.salary);
}

int emp_average_age(employee_t emp[], int n) {
    if (n == 0) return 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += emp[i].age;
    }
    return sum / n;
}

void emp_writefile(employee_t emp[], int n) {
    FILE* fp = fopen("employee.bin", "wb");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(emp, sizeof(employee_t), n, fp);
    fclose(fp);
}

int emp_readfile(employee_t emp[], int max_size) {
    FILE* fp = fopen("employee.bin", "rb");

    int count = 0;
    while (count < max_size && fread(&emp[count], sizeof(employee_t), 1, fp)) {
        count++;
    }
    fclose(fp);
    return count;
}

int main() {
    employee_t emp[3] = {
        {1, "IU", 20, 30000.0},
        {2, "Taylor", 26, 36000.0},
        {3, "Swift", 31, 90000.0}
    };

    emp_writefile(emp, 3);

    employee_t read_emp[10];
    int count = emp_readfile(read_emp, 10);

    for (int i = 0; i < count; i++) {
        emp_info(read_emp[i]);
    }

    return 0;
}
