#include <string.h>
#include <stdio.h>

int main()
{
    char value[100], words[10][30];
    int cnt = 0;

    scanf("%[^'\n']s", value);
    //printf("%s\n\n", value);

    char *newValue = strtok(value, " ");
    //printf("%s", newValue);
    while(newValue != NULL)
    {
        strcpy(words[cnt], newValue);
        newValue = strtok(NULL, " ");
        cnt++;
    }
    printf("ok");
    printf("\n\n");
    for (int i = 0; i < cnt; i++)
        printf("%s\n", words[i]);
    return 0;
}

