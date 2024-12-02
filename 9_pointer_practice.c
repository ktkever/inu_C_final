#include <stdio.h>

int main() {
    int num = 10;
    int *p = &num;

    // printf("%u\n",p);
    // p = p+5;    //pointer + 20 int 단위만큼씩 증가하기에 +4*5
    // printf("%u\n",p);

    // printf("%d",sizeof(p));     //pointer 변수 크기는 같다. 64bit pc = 8byte

    //포인터 연산
    printf("%u\n",*p);      //주소에 존재하는값
    printf("%u\n",p);       //주소값
    (*p)++;                 //주소에 존재하는 값++
    printf("%u\n",*p);
    *p++;                   //주소값++  주소값 이동(100번지->104번지) => 쓰레기값 존재(초기화하지 않았으므로)
    printf("%u\n",p);
    printf("%u\n",*p);      //쓰레기값 출력

}