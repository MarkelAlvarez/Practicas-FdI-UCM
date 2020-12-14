#include <stdio.h>

int main(void) {
    char name[100];

    printf("Enter your name: ");
    if (scanf("%s", name) != 1) {
            printf("Error/EOF\n");
            return 1;
    } else {
            printf("Hi %s!!\n", name);
            return 0;
    }
}
