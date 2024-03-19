/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main(){
	char mnames[10][20]; // 남학생명단(최대 10명)
	int mroom[10];		// 남학생명단별 호실 배정 목록
	char wnames[10][20]; // 여학생명단(최대 10명)
	int wroom[10];		// 여학생명단별 호실 배정 목록
	int person[2][5]={0};   // 2개 층별 5개 호실의 배정 인원 수 
	int mcount=0, wcount=0; // 인원 합계 (남, 여)
	int menu;

	srand(time(0));
	printf("===========================================\n");
	printf("생활관 호실 배정 프로그램\n");
	printf("===========================================\n");
	while(1){
		printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
		scanf("%d", &menu);
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", mnames[mcount]);
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", wnames[wcount]);
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
			wcount++;
		}
	}

	printf("===========================================\n");
	printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
	printf("===========================================\n");
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}

int findRoom(int persons[5]){
/*
리턴 : 랜덤으로 짜여진 호
만약 person배열에 값이 없다면 count++ (중복방지)
*/
    int rooms[5] = {0};
    int i, count = 0;
    for (i = 0; i < 5; i++) {
        if (persons[i] == 0) {
            rooms[count] = i + 1; 
            count++;
        }
    }
    if (count > 0) {
        return rooms[rand() % count];
    } else {
        return -1;
    }
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
//모든 방을 출력한 뒤, 만약 방에 사람이 있다면 정확하게 그 방 번호와 비교하여 이름 출력
        printf("남학생 명단 (%d명)\n", mc);
    for (int i = 0; i < mc; i++) {
        printf("%d. %s: [%d호]\n", i + 1, mn[i], mr[i]);
    }

    printf("\n");

    printf("여학생 명단 (%d명)\n", wc);
    for (int i = 0; i < wc; i++) {
        printf("%d. %s: [%d호]\n", i + 1, wn[i], wr[i]);
    }

    printf("\n");

    printf("호실별 배정 명단\n");
    for (int i = 0; i < 5; i++) {
        printf("%d호: ", i + 101);
        for (int j = 0; j < mc; j++) {
            if (mr[j] == i + 101) {
                printf("%s ", mn[j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++) {
        printf("%d호: ", i + 201);
        for (int j = 0; j < wc; j++) {
            if (wr[j] == i + 201) {
                printf("%s ", wn[j]);
            }
        }
        printf("\n");
    }
}
