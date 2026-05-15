#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int firstUniqChar(char *s)
{
    int size = strlen(s);
    int *map = calloc(26, sizeof(int));

    for (int i = 0; i < size; i++)
    {
        map[s[i] - 'a']++;
    }
    for (int i = 0; i < size; i++)
    {
        if (map[s[i] - 'a'] == 1)
        {
            free(map);
            return i;
        }
    }

    free(map);
    return -1;
}

int main()
{
    char string[] = "loveleetcode";
    int pos;

    pos = firstUniqChar(string);

    printf("\nLetra: \'%c\'\n", string[pos]);

    return 0;
}
