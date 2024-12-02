#include <stdio.h>

int main(){
    FILE*fp;
    fp = fopen("D:\\Programming\\inu_C_final\\grades.txt","w");

    if(fp == NULL)
        printf("파일을 열수 없습니다.");

    int num, input;
    char name[99];
    double score;
    do {
        printf("학번: ");
        scanf("%d",&num);
        printf("이름: ");
        scanf("%s",name);
        printf("성적: ");
        scanf("%lf",&score);
        
    } while (input != 0);
}