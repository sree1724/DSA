#include <stdio.h>
#include <stdlib.h>

#define MAX_DAYS 7

struct Day {
    char *name;
    int date;
    char *activity;
};

void create(struct Day calendar[7]) {
    for (int i = 0; i < 7; i++) {
        calendar[i].name = (char *)malloc(20 * sizeof(char));
        //calendar[i].date = (int *)malloc(20 * sizeof(int));
        calendar[i].activity = (char *)malloc(50 * sizeof(char));
    }
}

void read(struct Day calendar[7]) 
{
    
    for (int i = 0; i < 7; i++) 
    {
       //int j=1; 
       printf("Enter the details for day:%d\n", i+1);
       //printf(j);
       //j++;
        printf("Enter day name: ");
        scanf("%s", calendar[i].name);
        printf("Enter date: ");
        scanf("%d", &calendar[i].date);
        printf("Enter activity: ");
        scanf("%s", calendar[i].activity);
    }
}

void display(struct Day calendar[7]) {
    printf("\nWeek's Activity Details:\n");
    for (int i = 0; i < 7; ++i) {
        printf(" Day: %s\n Date: %d\n, Activity: %s\n", calendar[i].name, calendar[i].date, calendar[i].activity);
    printf("\n");
    }
}

int main() {
    struct Day calendar[7];

    create(calendar);
    read(calendar);
    display(calendar);

    // Free dynamically allocated memory
    for (int i = 0; i < 7; ++i) {
        free(calendar[i].name);
        free(calendar[i].activity);
    }

    return 0;
}
