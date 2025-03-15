#include <stdio.h>
#include <stdlib.h>

struct st_jumsu{
    char name[20]; // 이름 (공백 없이 영어 알파벳으로 구성)
    int jumsu[3]; // 3과목 점수 (국, 영, 수)
    int sum;	// 총점
    float avg;	// 평균
    char grade;	// 평균에 대한 등급
};

char getGrade(float score);
//파라미터: 평균 점수(score) 
//리턴값: 해당 평균 점수의 등급 ('A','B','C','D','F')
void makeJumsu(struct st_jumsu* p);
//파라미터: 점수 데이터의 포인터(p) 
//리턴값: 없음
//수행내용: 해당 학생의 점수 데이터 구조체 내의 과목 점수로 총점, 평균, 등급을 넣는다.
void printJumsu(struct st_jumsu* p);
//파라미터: 점수 데이터의 포인터(p) 
//리턴값: 없음
//수행내용: 해당 학생의 점수 데이터 구조체 내의 값을 출력한다.
int getClassSum(struct st_jumsu* data[], int size, int index);
//파라미터: 점수 데이터의 포인터 배열(data), 점수 데이터 개수, 과목번호(0~2) 
//리턴값: 과목번호에 해당하는 점수의 총 합계
//수행내용: 모든 점수 데이터의 특정 과목번호의 점수 합계를 구한다.

int main(){
	struct st_jumsu* jdata[20]; // 최대 20명의 점수 데이터
    int sum_class[3]; // 과목별 총점
    float average_class[3]; // 과목별 평균
    char class_name[3][20] = {"Korean", "English", "Math"};
    int all;
    int i, j;
    
    // 인원 수(최대 20)를 입력받는다.
    scanf("%d", &all);

    /*  인원 수만큼 반복
        인원 별로 3종류 과목의 점수를 입력받아 점수 데이터에 저장하고, 
        총점과 평균을 구해 점수 데이터에 저장한다.                     */
    for(i=0; i<all; i++){
        // 메모리를 할당
        jdata[i] = (struct st_jumsu*)malloc(sizeof(struct st_jumsu));
        // 이름을 입력받음
        scanf("%s", &(jdata[i]->name));

        for(j=0; j<3; j++){
            scanf("%d", &jdata[i]->jumsu[j]);
        }
        makeJumsu(jdata[i]);
    }

    // 모든 학생들의 점수를 출력한다.
    for(i=0; i<all; i++){
        printJumsu(jdata[i]);
    }

    // 세 과목의 총점과 평균을 계산하여 배열에 저장한다.
    for(j=0; j<3; j++){
        sum_class[j] = getClassSum(jdata, all, j);
        average_class[j] = sum_class[j]/(float)all;
        // 세 과목의 이름, 총점과 평균을 출력한다.
        printf("%s %d %.1f\n", class_name[j], sum_class[j], average_class[j]);
    }



    return 0;
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

void makeJumsu(struct st_jumsu* p){
    int sum = 0;

    for(int j=0; j<3; j++){
        sum += p->jumsu[j];
    }
    p->sum = sum;
    p->avg = sum/3.0;
    p->grade = getGrade(p->avg);
}

void printJumsu(struct st_jumsu* p){
    // 인원 수 만큼, 학생의 총점과 평균, 등급을 출력한다.
    printf("%s %d %.1f %c\n", p->name, p->sum, p->avg, p->grade);
}


int getClassSum(struct st_jumsu* data[], int size, int index){
    int c_sum = 0;

    for(int j=0; j<size; j++){
        c_sum += data[j]->jumsu[index];
    }
    return c_sum;
}
