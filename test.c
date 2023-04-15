#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000] = "Vu Minh Hieu";
    char *b = strstr(a, "Minh");
    if (b != NULL)
    {
        printf("%s\n", b);
    }
}