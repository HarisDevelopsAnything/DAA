#include<stdio.h>
#include<math.h>
struct Point {
    int x;
    int y;
};

struct Pair {
    struct Point p1;
    struct Point p2;
    int pn1;
    int pn2;
    float dist;
};

struct Pair ClosestPair(struct Point* P, int n){
    struct Pair p;
    float min = 999999999;
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            float dis= pow((P[i].x - P[j].x),2)+pow((P[i].y - P[j].y),2);
            if(dis < min)
            {
                min= dis;
                p.p1= P[i];
                p.p2= P[j];
                p.pn1= i+1;
                p.pn2= j+1;
                p.dist= dis;
            }
        }
    }
    return p;
}

int main(){
    printf("Enter the no. of points: ");
    int n;
    scanf("%d", &n);
    struct Point points[n];
    int i;
    for(i= 0;i<n;i++){
        printf("Enter coords for point %d:\n", (i+1));
        printf("X: ");
        scanf("%d", &points[i].x);
        printf("Y: ");
        scanf("%d", &points[i].y);
    }
    struct Pair cp= ClosestPair(points, n);
    printf("Closest pair: Points %d and %d\n", cp.pn1, cp.pn2);
    printf("Point 1: (%d, %d)\n", cp.p1.x, cp.p1.y);
    printf("Point 2: (%d, %d)\n", cp.p2.x, cp.p2.y);

}