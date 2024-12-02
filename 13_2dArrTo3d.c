#include <stdio.h>
#include <stdlib.h>

int main() {
    int ***arr = NULL;
    int row = 2, col = 5, k = 3;
    arr = (int***)malloc(k*sizeof(int**));
    if(arr == NULL) { printf("error malloc1\n"); return 0; }

    for(int i = 0; i < k; i++){
        arr[i] = (int**)malloc(row*sizeof(int*));
        if(arr[i] == NULL) { printf("error malloc2\n"); return 0; }
    }
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < row; j++){
            arr[i][j] = (int*)malloc(col*sizeof(int));
            if(arr[i] == NULL) { printf("error malloc3\n"); return 0; }
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < row; j++){
            for(int ii = 0; ii < col; ii++) {
                printf("%d ", i*10 + j*5 + ii);
            }
            printf("\n");
        }
        printf("\n");
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            free(arr[i][j]);
        }
    }
    for(int i = 0; i < 3; i++) free(arr[i]);
    free(arr);
}