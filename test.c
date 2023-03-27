#include<stdio.h>

int main() {
    printf("hello world\n");
    int n;
    scanf("%d", &n);
    int i = 1;
    for(i; i <= n; i++)
        printf("So ban da nhap la: %d\n", i);
}