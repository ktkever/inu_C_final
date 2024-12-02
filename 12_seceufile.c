#include <stdio.h>

int main(){
    FILE *fp = NULL;

    fp = fopen("D:/Programming/inu_C_final/12_origin.txt", "r");

    if(fp == NULL) {
        fprintf(stderr,"12_origin.txt 파일을 열 수 없습니다");
        return 0;
    };
}