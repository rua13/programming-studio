#include <stdio.h>

int main(){
    int kor, eng, math;
    int total;
    float average;

    scanf("%d %d %d", &kor, &eng, &math);
    total = kor + eng + math;
    average = total / 3.0;

    printf("%d %.1f\n", total, average);

    if (kor>=90){
        printf("Korean ");
    }
    if (eng>=90){
        printf("English ");
    }
    if (math>=90){
        printf("Math ");
    }

    return 0;
}