#include <stdio.h>
int main(void)
{
    int age;
    printf("Age: ");
    scanf("%d", &age);
    if (age >= 18)
        {
            printf("You can vote\n");
        }
    else
        {
            printf("Too young\n");
        }
    return 0;
}