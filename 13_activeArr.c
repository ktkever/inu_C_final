#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int count;
    printf("항목의 개수: ");
    scanf("%d",&count);
    arr = (int*)malloc(count*sizeof(int));
    if(arr == NULL) {
        printf("메모리 할당 실패\n");
        return 0;
    }
    
    for(int i = 0; i < count; i++) {
        printf("원소(정수) 입력: ");
        scanf("%d",&arr[i]);         //(arr+i)
    }
    printf("입력 값: ");
    for (int i = 0; i < count; i++) {
        printf("%d ",*(arr+i));
    }
}