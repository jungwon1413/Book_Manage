#include <stdio.h>

typedef struct Book 
{
	char title[300];
	char author[100];
	int page;
}book;

void main()
{
	/*�Ʒ� �ּ��� �뷫���� �������� �ý��� ������Ҹ� ��������ϴ�.
	1. �޴��� ����
	- �Է� (���� ������ �Է½ñ��� �����Է�)
	- ��� (�� �׸�, �Ǵ� ��ü ���ð���)
	- �˻� (���ϴ� �׸��� ã�Ƽ� �ش� ������ ������ ǥ��)
	- ���� (å ���� �Է��� ������ ���ϴ� �׸��� �����Ͽ� ����)
	- ���� (���ϴ� �׸�����)
	- ����
	
	2. ���� ����ü
	- å�̸�
	- ����
	- ������*/
	book arr[3];
	int count = 0;
	int i = 0;
	int run = 1;
	int ch;
	char condition;
	printf("1. �������� �Է�\n");
	printf("2. �������� ���\n");
	printf("3. �����˻�\n");
	printf("4. �������� ����\n");
	printf("5. �׸� ����\n");
	printf("6. ���α׷� ����\n");
	ch = _getch(); // ������� MENU()��� ��ɾ�� �����غ���

	switch (ch)
	{
	case 1:
		while (run == 1)
		{
			if (run != 0)
			{
				printf("���� : ");
				gets_s(arr.title[i], sizeof(arr[i]));
				++i;
				printf("���� : ");
				gets_s(arr.author[i], sizeof(arr[i]));
				++i;
				printf("�������� : ");
				scanf_s(arr.page[i], sizeof(arr[i]));
				i = 0;
				++count;
			}
			else
				break;
			
			printf("�߰� �Է��� �Ͻðڽ��ϱ�?\n");
			printf("(Y / N)\n");
			condition = _getch();
			if (condition == ('y' || 'Y'))
				run = 1;
			else if (condition == ('n' || 'N'))
				run = 0;
			else
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ֽʽÿ�.\n")
		}
		break;
	case 2:
		for (i=0; i<count; ++i)
		{
			printf("====%d�� ����====\n", i);
			printf("���� : %s\n", arr.title[i]);
			printf("���� : %s\n", arr.author[i]);
			printf("�������� : %s\n", arr.page[i]);
		}
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ֽʽÿ�.\n");
		break;
	}
}