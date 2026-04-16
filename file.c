#include <stdio.h>
#include <conio.h>

/* Structure must be identical to the others */
struct Member {
    char name[50];
    int age;
    char plan[20];
    int y, m, d;
};

void main() {
    struct Member mem;
    FILE *fp;
    int count = 0;

    clrscr();
    printf("--- Members Joined After 2025-01-01 ---\n\n");

    fp = fopen("gym.txt", "r");

    if (fp == NULL) {
        printf("Error: gym.txt not found!\n");
    } else {
        /* Reading the file */
        while (fscanf(fp, "%s %d %s %d-%d-%d", mem.name, &mem.age, mem.plan, &mem.y, &mem.m, &mem.d) != EOF) {
            
            /* The Logic: Check if Year > 2025 
               OR if Year is 2025 and Month/Day is after Jan 1st */
            if (mem.y > 2025 || (mem.y == 2025 && (mem.m > 1 || (mem.m == 1 && mem.d > 1)))) {
                printf("Name: %-15s | Joined: %d-%02d-%02d\n", mem.name, mem.y, mem.m, mem.d);
                count++;
            }
        }
        
        if (count == 0) {
            printf("No members found who joined after 2025-01-01.\n");
        } else {
            printf("\nTotal found: %d", count);
        }
        
        fclose(fp);
    }

    printf("\n\nPress any key to exit...");
    getch();
}