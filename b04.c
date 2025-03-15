#include <stdio.h>

int main(){
    int jumsu[5][3];  // 5명의 3과목 점수를 저장하는 2차원 배열
    int sum[5] = {0};  // 학생별 총점
    float average[5] = {0};  // 학생별 평균
    int i, j;

    for(i=0; i<5; i++){
        for(j=0; j<3; j++){
            scanf("%d", &jumsu[i][j]);
            sum[i] += jumsu[i][j];
        }
        average[i] = sum[i] / 3.0;
    }

    for(i=0; i<5; i++){
        printf("%d) %d %.1f\n", i+1, sum[i], average[i]);
    }

    return 0;
}