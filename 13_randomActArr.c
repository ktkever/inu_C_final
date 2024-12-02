#include <stdio.h>
#include <stdlib.h>
#define size 1000

int main() {
    srand(time(NULL));
    int *arr = NULL;
    arr = (int*)malloc(size*sizeof(int));
    if(arr == NULL){
        printf("메모리 할당 실패");
        return 0;
    }
    for(int i = 0; i < size; i++){
        arr[i] = rand();
    }
    int maxItem = arr[0];
    for(int i = 0; i < size; i++){
        if(maxItem < arr[i])
            maxItem = arr[i];
    }
    printf("max: %d",maxItem);
}