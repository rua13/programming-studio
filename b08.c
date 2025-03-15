#include <stdio.h>

struct st_jumsu{
    char name[20]; // 이름 (공백 없이 영어 알파벳으로 구성)
    int jumsu[3]; // 3과목 점수 (국, 영, 수)
    int sum;	// 총점
    float avg;	// 평균
    char grade;	// 평균에 대한 등급
};

int main(){
    struct st_jumsu one; // one의 점수 데이터
    int sum = 0;

    scanf("%s", one.name);

    for(int i=0; i<3; i++){
        scanf("%d", &one.jumsu[i]);
        sum += one.jumsu[i];
    }
    
    one.sum = sum;
    one.avg = one.sum / 3.0;
    if (one.avg>=90){
        one.grade = 'A';
    }
    else if (one.avg>=80){
        one.grade = 'B';
    }
    else if (one.avg>=70){
        one.grade = 'C';
    }
    else if (one.avg>=60){
        one.grade = 'D';
    }
    else if (one.avg<60){
        one.grade = 'F';
    }

    printf("%s %d %.1f %c\n", one.name, one.sum, one.avg, one.grade);
    return 0;
}