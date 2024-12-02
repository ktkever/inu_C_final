#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // 동적 메모리 사용을 위해 추가
#include <locale.h>  // 한글 처리를 위해 추가
#define Size 25

typedef struct tel {
    char s_name[size];
    char s_number[size];
    int sAge, isEmpty;
} TEL;

TEL contact[1000]; // 구조체 배열
TEL *first_empty = NULL; // 첫 번째 빈 공간을 가리키는 포인터

void initContacts();
void addtel();
void searchbyname();
void correct(TEL *entry);

int main() {
    setlocale(LC_ALL, "");  // 한글 입출력 설정
    initContacts();         // 연락처 초기화

    int input;
    do {
        printf("\n1. 연락처 추가\n2. 연락처 검색\n3. 종료\n선택하세요: ");
        scanf("%d", &input);
        switch (input) {
        case 1:
            addtel();
            break;
        case 2:
            searchbyname();
            break;
        default:
            break;
        }
    } while (input < 3);

    printf("종료합니다\n");
    printf("\n");
    for(int k = 0; k < 5; k++)
        printf("%d. 이름: %s, 전화번호: %s, 나이: %d\n",k, contact[k].s_name, contact[k].s_number, contact[k].sAge);

    return 0;
}

// 연락처 초기화
void initContacts() {
    for (int i = 0; i < 1000; i++) {
        contact[i].isEmpty = 1;
    }
    first_empty = &contact[0]; // 첫 번째 빈 공간 설정
}

// 연락처 추가
void addtel() {
    if (first_empty == NULL) {
        printf("저장 공간이 가득 찼습니다.\n");
        return;
    }

    TEL *entry = first_empty; // 첫 번째 빈 공간을 가리키는 포인터
    printf("이름: ");
    scanf("%s", entry->s_name);
    printf("전화번호: ");
    scanf("%s", entry->s_number);
    printf("나이: ");
    scanf("%d", &entry->sAge);
    entry->isEmpty = 0;

    // 다음 빈 공간 찾기
    for (TEL *p = entry + 1; p < contact + 1000; p++) {
        if (p->isEmpty) {
            first_empty = p;
            return;
        }
    }
    first_empty = NULL; // 더 이상 빈 공간이 없을 경우 NULL 설정
}

// 이름으로 연락처 검색
void searchbyname() {
    char searchname[size];
    printf("이름을 입력하세요: ");
    scanf("%s", searchname);

    TEL *found[1000]; // 검색 결과를 저장할 포인터 배열
    int found_count = 0;

    // 이름 검색
    for (TEL *p = contact; p < contact + 1000; p++) {
        if (!p->isEmpty && strcmp(searchname, p->s_name) == 0) {
            printf("\nindex = %ld\n이름: %s\n전화번호: %s\n나이: %d\n",
                   p - contact, p->s_name, p->s_number, p->sAge);
            found[found_count++] = p;
        }
    }

    if (found_count == 0) {
        printf("%s를 찾을 수 없습니다.\n", searchname);
        return;
    }

    // 동명이인 처리
    if (found_count > 1) {
        int selected;
        printf("%d개의 연락처를 찾았습니다. 수정/삭제할 연락처를 선택하세요 (0~%d): ", found_count - 1);
        scanf("%d", &selected);

        if (selected >= 0 && selected < found_count) {
            correct(found[selected]);
        } else {
            printf("잘못된 선택입니다.\n");
        }
    } else {
        correct(found[0]);
    }
}

// 연락처 수정 및 삭제
void correct(TEL *entry) {
    int select, age;
    char name[size];
    char number[size];

    printf("    1. 연락처 수정\n    2. 연락처 삭제\n선택하세요: ");
    scanf("%d", &select);

    switch (select) {
    case 1:
        printf("이름(수정 안 할 시 q 입력): ");
        scanf("%s", name);
        printf("전화번호(수정 안 할 시 q 입력): ");
        scanf("%s", number);
        printf("나이(수정 안 할 시 -1 입력): ");
        scanf("%d", &age);

        if (strcmp(name, "q") != 0)
            strcpy(entry->s_name, name);
        if (strcmp(number, "q") != 0)
            strcpy(entry->s_number, number);
        if (age != -1)
            entry->sAge = age;

        break;
    case 2:
        entry->isEmpty = 1;
        printf("삭제되었습니다.\n");

        // 삭제된 후 빈 공간 갱신
        if (first_empty == NULL || entry < first_empty) {
            first_empty = entry;
        }
        break;
    default:
        printf("잘못된 선택입니다.\n");
        break;
    }
}