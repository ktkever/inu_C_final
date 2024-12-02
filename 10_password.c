#include <stdio.h>
#include <conio.h>

int main(){
    char pass[8];

    printf("password: ");
    for(int i = 0; i < 8; i++){
        pass[i] = _getch();     //버퍼 사용X 따라서 출력X
        printf("*");
    }
    printf("\n");
    printf("입력한 비밀번호는 다음과 같습니다\n");
    printf("%s",pass);
}