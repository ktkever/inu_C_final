#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SOL "apple"

int main() {
    srand(time(NULL));
    char in[99] = "";
    char ans[99] = "apple";
    
    for(int i = 0; i < strlen(SOL); i ++){
        int r1 = rand()%strlen(ans);
        int r2 = rand()%strlen(ans);
        char tmp;
        tmp = ans[r1];
        ans[r1] = ans[r2];
        ans[r2] = tmp;
    }

    do
    {
        printf("%s의 원래 단어 맞추기: ", ans);
        scanf("%s",in);

    } while (strcmp(in,SOL) != 0);
    printf("정답!");
}