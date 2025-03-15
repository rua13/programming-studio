#include <stdio.h>

int main(){
    int kor, eng, math;
    int total;
    float average;

    scanf("%d %d %d", &kor, &eng, &math);
    total = kor + eng + math;
    average = total / 3.0;

    printf("%d\n", total);
    printf("%.1f", average);

    return 0;
}