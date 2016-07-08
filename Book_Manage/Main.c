#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct _BOOK 
{
	char title[300];
	char author[100];
	int page;
} BOOK;

void main()
{
	/*�Ʒ� �ּ��� �뷫���� �������� �ý��� ������Ҹ� ��������ϴ�.
	1. �޴��� ����
	- �Է� (���� ������ �Է½ñ��� �����Է�) - ���Ŀ� ���Ϸ� �Է��� �����Դϴ�.
	- ��� (�� �׸�, �Ǵ� ��ü ���ð���) - ���Ŀ� ���Ͽ��� ���� �о���� �����Դϴ�.
	- �˻� (���ϴ� �׸��� ã�Ƽ� �ش� ������ ������ ǥ��)
	- ���� (å ���� �Է��� ������ ���ϴ� �׸��� �����Ͽ� ����)
	- ���� (���ϴ� �׸�����)
	- ����
	
	2. ���� ����ü
	- å�̸�
	- ����
	- ������*/
	BOOK arr[300];
	int count = 0;
	int i = 0;
	int run = 1;
	int ch;
	char condition = 0;
	printf("1. �������� �Է�\n");
	printf("2. �������� ���\n");
	printf("3. �����˻�\n");
	printf("4. �������� ����\n");
	printf("5. �׸� ����\n");
	printf("6. ���α׷� ����\n\n");
	ch = _getch(); // ������� MENU()��� ��ɾ�� �����غ���

	switch (ch)
	{
	case '1':
		while (run != 0)
		{
			if (run != 0)
			{
				printf("���� : ");
				gets_s(arr[count].title, sizeof(arr[count].title)); // �� �Լ��� ���۸� �̹� �����ϴ� �Լ��̴�. �׷��Ƿ� fflush�� while (getchar...)���� ���ۺ�������� �ʿ����� �ʽ��ϴ�.
				//while (getchar() != '\n'); // fflush(stdin)��ſ� �Ế�ϴ�. ���� �ǵ��ߴ� ���۰� �ٸ����� ����...

				printf("���� : ");
				gets_s(arr[count].author, sizeof(arr[count].author));
				while (getchar() != '\n');

				printf("�������� : ");
				scanf_s("%d", &arr[count].page);
				while (getchar() != '\n');

				printf("\n");
				++count;
			}
			else
				break;
			while (condition != ('y' || 'Y' || 'n' || 'N')) // ���ε��� T/F ������ �Ҽ��ֵ��� ���ݽô�.
			{
				printf("�߰� �Է��� �Ͻðڽ��ϱ�?\n");
				printf("----(Y/N)----\n");
				//�����Է��� ���۾��� �ް������ ���� ������ �ʽ��ϴ�.
				if (condition == ('y' || 'Y'))
				{
					run = 1;
					break;
				}
				else if (condition == ('n' || 'N'))
				{
					run = 0;
					break;
				}
				else
					printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ֽʽÿ�.\n\n");
			}
		}
		break;
	case '2': // �ϴ� ��ü��¸� �����س��ҽ��ϴ�.
		for (i=0; i<count; ++i)
		{
			printf("====%d�� ����====\n", i);
			printf("���� : %s\n", arr[i].title);
			printf("���� : %s\n", arr[i].author);
			printf("�������� : %d\n", arr[i].page);
		}
		break;
	case '3':
		break;
	case '4':
		break;
	case '5':
		break;
	case '6':
		break;
	default:
		printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ֽʽÿ�.\n");
		break;
	}
}