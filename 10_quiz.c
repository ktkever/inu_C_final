#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(){
    char answer[99] = "C";
    char input[99] = "";
    do
    {
        printf("임베디드 장치에 가장 많이 사용되는 언어는?");
        gets(input);
    } while (strcmp(input,answer) != 0);

    printf("정답!");
}