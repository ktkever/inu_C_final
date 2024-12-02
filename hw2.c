#include <stdio.h>
#include <string.h>
#include <conio.h>
#define size 25

typedef struct tel{
    char sName[size];
    char sNumber[size];
    int sAge, isEmpty;
} TEL;

int contactIndex = -1;
int foundIndex = -1;
int foundsIndex = -1;

void addtel(int address);
void searchbyname();
void correct(int f);
TEL contact[1000] = {};

int main() {
    printf("%d",contact[0].isEmpty);
    for(int i = 0; i < 1000; i++)
        contact[i].isEmpty = 1;

    int input;
    do {
        printf("\n1. 연락처 추가\n2. 연락처 검색\n3. 종료\n선택하세요: ");
        scanf("%d",&input);
        switch (input) {
        case 1:
            addtel(-1);
            break;
        case 2:
            searchbyname();
            break;
        
        default:
            break;
        }
    } while (input < 3);
    printf("종료합니다\n");
    /*
    for(int k = 0; k < 5; k++)
        printf("%d. 이름: %s, 전화번호: %s, 나이: %d\n",k, contact[k].s_name, contact[k].s_number, contact[k].s_age);
    */
}

void addtel(int address) {
    //선언 및 값 받기
    char name[size];
    char number[size];
    int age;
    printf("이름: ");
    scanf("%s",name);
    printf("전화번호: ");
    scanf("%s",number);
    printf("나이: ");
    scanf("%d",&age);

    if(foundIndex >= 0)
        contactIndex = foundIndex-1;
    else if(foundsIndex >= 0)
        contactIndex = foundsIndex-1;

    while (contactIndex < 1000) {
        contactIndex++;
        if(contact[contactIndex].isEmpty == 1)
            break;
    }
    
    if((contactIndex < 1000)){
        strcpy(contact[contactIndex].sName,name);
        strcpy(contact[contactIndex].sNumber,number);
        contact[contactIndex].sAge = age;
        contact[contactIndex].isEmpty = 0;
    }
}

void searchbyname() {
    char searchName[30] = {};
    printf("이름을 입력하세요: ");
    scanf("%s",searchName);
    int found, selectedInd = 0;
    int foundInd[1000];
    for(int i = 0; i < 1000; i++){
        if((strcmp(searchName, contact[i].sName) == 0) && contact[i].isEmpty == 0){
            printf("\n연락처를 찾았습니다.\n");
            printf("이름: %s\n전화번호: %s\n나이: %d\n",contact[i].sName,contact[i].sNumber,contact[i].sAge);
            foundInd[found] = i;
            found++;
            foundIndex = i;
        }
    }
    if(found == 0)
        printf("%s를 찾을수 없습니다.\n",searchName);
    else if(found > 1) {
        printf("%d개의 연락처를 찾았습니다. 수정/삭제할 연락처를 선택하세요(0 ~ %d): ",found,found-1);
        scanf("%d",&selectedInd);
        foundIndex = -1;
        foundsIndex = foundInd[selectedInd];
        correct(foundInd[selectedInd]);
    }
    else
        correct(foundIndex);
}

void correct(int f) {
    int select, age;
    char name[99];
    char number[99];
    printf("    1. 연락처 수정\n    2. 연락처 삭제\n");
    printf("선택하세요: ");
    scanf("%d",&select);

    switch (select) {

    case 1:
        printf("이름(수정 안할 시 q입력): ");
        scanf("%s",name);
        printf("전화번호(수정 안할 시 q입력):");
        scanf("%s",number);
        printf("나이(수정 안할 시 -1 입력): ");
        scanf("%d",&age);
        if(strcmp(name, "q") != 0) 
            strcpy(contact[f].sName,name);
        if(strcmp(number,"q") != 0)
            strcpy(contact[f].sNumber, number);
        if(age != -1 )
            contact[f].sAge = age;
        break;

    case 2:
        strcpy(contact[f].sName,"");
        strcpy(contact[f].sNumber,"");
        contact[f].sAge = 0;
        contact[f].isEmpty = 1;
        printf("삭제되었습니다.\n");
    
    default:
        break;
    }
}