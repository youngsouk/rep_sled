#include <stdio.h>
#include <stdlib.h>

int main() {
	int cnt; // ������ RET����
	void *para1; // �����Ű���� �ϴ� �Լ��� ù��°�μ� �޸� �ּ�
	void *ebp; //���� ebp �ּ�
	int mode;

	while (1) {
		printf("�ȳ��ϼ���. �� ���α׷��� RET SLED ����� Ȱ���� ������ ���ϰ� ���ִ� ���α׷��Դϴ�.\n");
		printf("1. ������ �ʿ��� RET ���� ���ϱ�(������ ebp�ּҸ� �ȴٴ� ����)\n");
		printf("2. �����ų �Լ��� ù��° �μ� �ּ� ���ϱ�(RET ���� + ���� ebp �ּҴ� �ȴٴ� ����)\n");
		printf("0. ����\n");

		scanf_s("%d", &mode);
		if (mode < 0 || mode > 2) printf("�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
		else break;
	}

	if (mode == 1) {
		printf("�����Ű���� �ϴ� �Լ��� ù��° �μ��� �޸� �ּҸ� �Է��ϼ���. \n0x");
		scanf_s("%p", &para1);
		printf("������ ebp �޸� �ּҸ� �Է��ϼ���. \n0x");
		scanf_s("%p", &ebp);

		cnt = ((int)para1 - (int)ebp - 12) / 4;
		printf("������ �ʿ��� RET ������ %d���Դϴ�.\n", cnt);
		system("pause");
	}
	else if (mode == 2) {
		printf("������ ebp �޸� �ּҸ� �Է��ϼ���. \n0x");
		scanf_s("%p", &ebp);
		printf("������ RET�� ���� : ");
		scanf_s("%d", &cnt);

		para1 = (void *)((int)ebp + 4 * (cnt + 1) + 8);
		printf("�����ų �Լ��� ù��° �μ� �ּҴ� 0x%p �Դϴ�.", para1);
		system("pause");
	}
	else {
		return 0;
	}
}