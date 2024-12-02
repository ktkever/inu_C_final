#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};

int main() {
    struct point p1;
    struct point p2;
    printf("x1와 y1의 좌표 입력: ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("x2와 y2의 좌표입력: ");
    scanf("%d %d", &p2.x, &p2.y);
    double diffx = p1.x*p1.x -p2.x*p2.x;
    double diffy = p1.y*p1.y - p2.y*p2.y;
    double dist = sqrt(diffx + diffy);
    printf("%lf", dist);

}