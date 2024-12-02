#include <stdio.h>
#define SIZE 5
double get_array_avg(int *vals,int n);
void print_array(int *vals, int n);

int main() {
    
    int i;
    int data[SIZE] = {10, 20, 30, 40, 50};
    print_array(data,SIZE);
    double res = get_array_avg(data,SIZE);
    printf("%.3lf",res);

}

void print_array(int *vals, int n){
    printf("[ ");
    for(int i = 0; i < n; i++){
        if(i != 4)
            printf("%d, ",vals[i]);
        else
            printf("%d",vals[i]);
    }
    printf(" ]\n");
}

double get_array_avg(int *vals, int n){
    double sum = 0;
    double res;
    for(int i = 0; i<n; i++){
        sum+=vals[i];
        res = sum/n;

    }
    return res;
}