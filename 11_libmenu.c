#include <stdio.h>
#include <string.h>
#define size 99

typedef struct bookinfo {
    int booknum;
    char writter[size];
    char bookname[size];
    int isEmpty;

} BOOK;

void searchbynum();
void searchbyauthor();
void searchbytitle();
void addbook();
int countbook();
BOOK books[size];

int main() {
    int select;
    do {
        printf("==================\n");
        printf("1. 도서 번호로 찾기\n");
        printf("2. 저자 이름으로 찾기\n");
        printf("3. 제목으로 찾기\n");
        printf("4. 새 책 추가\n");
        printf("5. 소장한 도서 수 표시\n");
        printf("==================\n");
        printf("하나를 선택하세요: ");
        scanf("%d",&select);

        switch (select) {
        case 1:
            searchbynum();
            break;
        case 2:
            searchbyauthor();
            break;
        case 3:
            searchbytitle();
            break;
        case 4:
            addbook();
            break;
        case 5:
            countbook();
            break;

        default:
            break;
        }
    } while (select <= 5);
    
}

void searchbynum() {
    int num;
    printf("도서 번호 입력: ");
    scanf("%d",&num);
    int i;
    for (i = 0; i < size; i++) {
        if(books[i].booknum == num){
            printf("번호: %d\n",books[i].booknum);
            printf("작가: %s\n",books[i].writter);
            printf("제목: %s\n",books[i].bookname);
            break;
        }
    }
    if(i == size)
        printf("책을 찾지 못했습니다.\n");
}

void searchbyauthor(){
    char name[size];
    printf("저자 이름 검색: ");
    scanf("%s",name);
    int i;
    for(i = 0; i < size; i++){
        if(strcmp(books[i].writter, name)== 0){
            printf("번호: %d\n",books[i].booknum);
            printf("작가: %s\n",books[i].writter);
            printf("제목: %s\n",books[i].bookname);
            break;
        }
    }
    if(i == size)
        printf("책을 찾지 못했습니다.\n");
}

void searchbytitle(){
    char title[size];
    printf("제목 검색: ");
    scanf("%s",title);
    int i;
    for(i = 0; i < size; i++){
        if(strcmp(books[i].bookname, title)== 0){
            printf("번호: %d\n",books[i].booknum);
            printf("작가: %s\n",books[i].writter);
            printf("제목: %s\n",books[i].bookname);
            break;
        }
    }
    if(i == size)
        printf("책을 찾지 못했습니다.\n");
}

void addbook(){
    int numinput;
    char authorinput[size];
    char titleinput[size];
    printf("책 제목 입력: ");
    scanf("%s",titleinput);
    printf("저자 입력: ");
    scanf("%s",authorinput);
    printf("책 번호 입력: ");
    scanf("%d",&numinput);

    for(int i = 0; i < size; i++){
        if(books[i].isEmpty != 1){
            books[i].booknum = numinput;
            strcpy(books[i].bookname, titleinput);
            strcpy(books[i].writter, authorinput);
            books[i].isEmpty = 1;
        }

    }
}

int countbook() {
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(books[i].isEmpty == 1)
            count++;
    }
    printf("%d\n",count);
}