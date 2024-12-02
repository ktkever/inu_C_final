#include <stdio.h>

int main(){
    char str[100] = "";        //문자열 초기화(크기 지정해야 scanf 입력시 다 들어감)
    printf("문자열 입력: ");
    scanf("%s",str);        //문자열 = 배열 = 포인터(주소)
    //gets_s(); 한줄의 문자열 입력(변수, 문자열 크기)
    
    for(int i = 0; str[i] != 0; i++){
        if((str[i] >= 'A' && str[i] <= 'Z')|| (str[i] >= 'a' && str[i] <= 'z'))
        {
            printf("%c",str[i]);
        }
    }
}