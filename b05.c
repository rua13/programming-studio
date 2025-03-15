#include <stdio.h>

#define STUDENTS 5

int main(){
    int jumsu[STUDENTS][3];  // 5명의 3과목 점수를 저장하는 2차원 배열
    int sum[STUDENTS] = {0};  // 학생별 총점
    float average[STUDENTS];  // 학생별 평균
    char grade[5]; // 학생별 등급 

    int sum_class[3] = {0}; // 과목별 총점
    float average_class[3]; // 과목별 평균
    char class_name[3][20] = {"Korean", "English", "Math"};
    int i, j;

    for(i=0; i<STUDENTS; i++){
        for(j=0; j<3; j++){
            scanf("%d", &jumsu[i][j]);
            sum[i] += jumsu[i][j];
            sum_class[j] += jumsu[i][j];
        }
        average[i] = sum[i] / 3.0;
        if (average[i]>=90){
            grade[i] = 'A';
        }
        else if (average[i]>=80){
            grade[i] = 'B';
        }
        else if (average[i]>=70){
            grade[i] = 'C';
        }
        else if (average[i]>=60){
            grade[i] = 'D';
        }
        else if (average[i]<60){
            grade[i] = 'F';
        }
    }

    for(i=0; i<STUDENTS; i++){
        printf("%d) %d %.1f %c\n", i+1, sum[i], average[i], grade[i]);
    }
    for(j=0; j<3; j++){
        average_class[j] = sum_class[j]/(float)STUDENTS;
        printf("%s %d %.1f\n", class_name[j], sum_class[j], average_class[j]);
    }
    return 0;
}