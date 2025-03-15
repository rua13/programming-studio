#include <stdio.h>

int main(){
    int kor, eng, math;
    int total;
    float average;
    char grade;

    scanf("%d %d %d", &kor, &eng, &math);
    total = kor + eng + math;
    average = total / 3.0;

    printf("%.1f ", average);

    if (average>=90){
        grade = 'A';
    }
    else if (average>=80){
        grade = 'B';
    }
    else if (average>=70){
        grade = 'C';
    }
    else if (average>=60){
        grade = 'D';
    }
    else if (average<60){
        grade = 'F';
    }

    printf("%c\n", grade);

    return 0;
}