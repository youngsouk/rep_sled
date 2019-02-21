#include <stdio.h>
#include <stdlib.h>

int main() {
	int cnt; // 삽입할 RET갯수
	void *para1; // 실행시키고자 하는 함수의 첫번째인수 메모리 주소
	void *ebp; //원래 ebp 주소
	int mode;

	while (1) {
		printf("안녕하세요. 이 프로그램은 RET SLED 기법을 활용한 공격을 편리하게 해주는 프로그램입니다.\n");
		printf("1. 삽입이 필요한 RET 갯수 구하기(원래의 ebp주소를 안다는 전제)\n");
		printf("2. 실행시킬 함수의 첫번째 인수 주소 구하기(RET 갯수 + 원래 ebp 주소는 안다는 전제)\n");
		printf("0. 종료\n");

		scanf_s("%d", &mode);
		if (mode < 0 || mode > 2) printf("잘못입력하셨습니다. 다시 입력해주세요.\n\n");
		else break;
	}

	if (mode == 1) {
		printf("실행시키고자 하는 함수의 첫번째 인수의 메모리 주소를 입력하세요. \n0x");
		scanf_s("%p", &para1);
		printf("원래의 ebp 메모리 주소를 입력하세요. \n0x");
		scanf_s("%p", &ebp);

		cnt = ((int)para1 - (int)ebp - 12) / 4;
		printf("삽입이 필요한 RET 갯수는 %d개입니다.\n", cnt);
		system("pause");
	}
	else if (mode == 2) {
		printf("원래의 ebp 메모리 주소를 입력하세요. \n0x");
		scanf_s("%p", &ebp);
		printf("삽입할 RET의 갯수 : ");
		scanf_s("%d", &cnt);

		para1 = (void *)((int)ebp + 4 * (cnt + 1) + 8);
		printf("실행시킬 함수의 첫번째 인수 주소는 0x%p 입니다.", para1);
		system("pause");
	}
	else {
		return 0;
	}
}