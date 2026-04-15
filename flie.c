#include <stdio.h>
#include <string.h>

struct Member {
    int id;
    char name[50];
    int age;
    char plan[20];   // Weekly, Monthly, Yearly, Premium
    char joinDate[15];
};

int main() {
    struct Member m[5] = {
        {1, "Ram", 25, "Monthly", "2025-02-10"},
        {2, "Shyam", 30, "Premium", "2024-12-01"},
        {3, "Hari", 18, "Weekly", "2025-03-15"},
        {4, "Sita", 40, "Yearly", "2023-11-20"},
        {5, "Gita", 22, "Premium", "2025-01-05"}
    };

    int i;

    // 1. Find oldest & youngest member
    int oldest = 0, youngest = 0;
    for(i = 1; i < 5; i++) {
        if(m[i].age > m[oldest].age)
            oldest = i;
        if(m[i].age < m[youngest].age)
            youngest = i;
    }

    printf("Oldest Member: %s (%d years)\n", m[oldest].name, m[oldest].age);
    printf("Youngest Member: %s (%d years)\n\n", m[youngest].name, m[youngest].age);

    

    return 0;
}