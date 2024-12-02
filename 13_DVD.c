#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dvd{
    char title[99];
    double point;
} dvd;

int main() {
    dvd *d = NULL;
    int count;
    printf("영화 개수: ");
    scanf("%d",&count);
    getchar();      //버퍼 초기화
    d = (dvd*)malloc(count*sizeof(dvd));
    if(d == NULL) {
        printf("메모리 할당 실패");
        return 0;
    }
    for(int i = 0; i < count; i++){
        printf("영화 제목: ");
        fgets(d[i].title,sizeof(d[i].title),stdin);
        printf("평점: ");
        scanf("%lf",&d[i].point);
        getchar();
    }
    printf("==================\n");
    for(int i = 0; i < count; i++) {
        printf("영화제목: %s",d[i].title);
        printf("평점: %.2lf\n",d[i].point);
    }
    printf("==================");
}