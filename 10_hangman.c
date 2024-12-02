#include <stdio.h>
#include <string.h>

int main(){
    char ans[] = "Hello, World!";
    char guess;
    char now[] = "______ ______";
    do
    {
        printf("문자열 입력: ");
        guess = getchar();
        for(int i = 0; i < strlen(ans); i++){
            if(guess == ans[i]){
                now[i] = guess;
            }
        }
        printf("%s\n",now);
    } while (strcmp(now,ans) != 0);
}