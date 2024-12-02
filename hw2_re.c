#include <stdio.h>
#include <string.h>
#define size 20
typedef struct phoneBook{
    char structName[20];
    char sPhoneNumber[20];
    int age, isntEmpty;
} tel;
void addTel();
void searchByName();
void correct(int index);

tel telBook[1000] = {};

int main() {
    int input;
    do {
        printf("\n1. 연락처 추가\n2. 연락처 검색\n3. 종료\n선택하세요: ");
        scanf("%d",&input);
        switch(input) {
        case 1:
            addTel();
            break;
        case 2:
            searchByName();
            break;
        
        default:
            break;
        }
    } while (input < 3);
    printf("종료합니다\n");
}

void addTel(){
    int structIndex = 0;
    char inputName[size];
    while(structIndex < 1000) {
        structIndex++;
        if(telBook[structIndex].isntEmpty == 1){    //구조체 배열의 인덱스가 비어있으면 추가

        }
    }
}