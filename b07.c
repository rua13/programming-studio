#include <stdio.h>

int studentSum(int s[20][3], int size, int index);
char getGrade(float score);
int classSum(int s[20][3], int size, int index);
int firstRanking(int s[20], int size);

int main(){
	int jumsu[20][3]; // 최대 20명의 3과목 점수를 저장하고 있는 2차원 배열 
	int sum_student[20]; // 최대 20명의 학생별 총점
	float average_student[20];  // 최대 20명의 학생별 평균
	char grade[20]; // 최대 20명의 학생별 등급 
	int first;	// 1등 학생 번호
	int all;	// 인원수
	int sum_class[3]; // 과목별 총점
	float average_class[3]; // 과목별 평균
	char class_name[3][20] = {"Korean", "English", "Math"};
    int i, j;
    
    // 인원 수(최대 20)를 입력받는다.
    scanf("%d", &all);

    // 인원 수 만큼 3종류 과목의 점수를 입력받는다.
    for(i=0; i<all; i++){
        for(j=0; j<3; j++){
            scanf("%d", &jumsu[i][j]);
        }
    }

    // 인원 수 만큼 학생별 총점과 평균을 계산하여 배열에 저장한다. 
    for(i=0; i<all; i++){
        sum_student[i] = studentSum(jumsu, all, i);
        average_student[i] = sum_student[i] / 3.0;
        grade[i] = getGrade(average_student[i]);
        // 인원 수 만큼, 학생의 총점과 평균, 등급을 출력한다.
        printf("%d) %d %.1f %c\n", i+1, sum_student[i], average_student[i], grade[i]);
    }

    // 세 과목의 총점과 평균을 계산하여 배열에 저장한다.
    for(j=0; j<3; j++){
        sum_class[j] = classSum(jumsu, all, j);
        average_class[j] = sum_class[j]/(float)all;
        // 세 과목의 이름, 총점과 평균을 출력한다.
        printf("%s %d %.1f\n", class_name[j], sum_class[j], average_class[j]);
    }


    printf("1st Ranking: %d\n", firstRanking(sum_student, all)+1);

    return 0;
}

// size를 준 의도가 무엇인지 모르겠다..
int studentSum(int s[20][3], int size, int index){
    int s_sum = 0;

    if(index > size){
        printf("error");
    }

    for(int j=0; j<3; j++){
        s_sum += s[index][j];
    }
    return s_sum;
}

char getGrade(float score){
    if (score>=90){
        return 'A';
    }
    else if (score>=80){
        return 'B';
    }
    else if (score>=70){
        return 'C';
    }
    else if (score>=60){
        return 'D';
    }
    else if (score<60){
        return 'F';
    }
}

int classSum(int s[20][3], int size, int index){
    int c_sum = 0;
    for(int i=0; i<size; i++){
        c_sum += s[i][index];
    }
    return c_sum;
}

int firstRanking(int s[20], int size){
    int top, top_index = 0;
    // 학생 별 총점이 기록된 배열을 parameter로 받을 것
    for(int i=0; i<size; i++){
        if(top < s[i]){
            top = s[i];
            top_index = i; 
        }
    }
    return top_index;
}
