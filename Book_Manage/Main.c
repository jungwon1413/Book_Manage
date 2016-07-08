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
	/*아래 주석은 대략적인 도서관리 시스템 구성요소를 적어놓습니다.
	1. 메뉴의 구성
	- 입력 (종료 시퀀스 입력시까지 무한입력) - 추후에 파일로 입력할 예정입니다.
	- 출력 (각 항목, 또는 전체 선택가능) - 추후에 파일에서 직접 읽어들일 예정입니다.
	- 검색 (원하는 항목을 찾아서 해당 서적의 상세정보 표기)
	- 수정 (책 순번 입력후 수정을 원하는 항목을 지정하여 변경)
	- 정렬 (원하는 항목으로)
	- 종료
	
	2. 도서 구조체
	- 책이름
	- 저자
	- 페이지*/
	BOOK arr[300];
	int count = 0;
	int i = 0;
	int run = 1;
	int ch;
	char condition = 0;
	printf("1. 도서정보 입력\n");
	printf("2. 도서정보 출력\n");
	printf("3. 도서검색\n");
	printf("4. 도서정보 수정\n");
	printf("5. 항목 정렬\n");
	printf("6. 프로그램 종료\n\n");
	ch = _getch(); // 여기까지 MENU()라는 명령어로 구현해보자

	switch (ch)
	{
	case '1':
		while (run != 0)
		{
			if (run != 0)
			{
				printf("제목 : ");
				gets_s(arr[count].title, sizeof(arr[count].title)); // 이 함수는 버퍼를 이미 소진하는 함수이다. 그러므로 fflush나 while (getchar...)같은 버퍼비움절차가 필요하지 않습니다.
				//while (getchar() != '\n'); // fflush(stdin)대신에 써봅니다. 원래 의도했던 동작과 다를때가 많음...

				printf("저자 : ");
				gets_s(arr[count].author, sizeof(arr[count].author));
				while (getchar() != '\n');

				printf("페이지수 : ");
				scanf_s("%d", &arr[count].page);
				while (getchar() != '\n');

				printf("\n");
				++count;
			}
			else
				break;
			while (condition != ('y' || 'Y' || 'n' || 'N')) // 따로따로 T/F 연산을 할수있도록 해줍시다.
			{
				printf("추가 입력을 하시겠습니까?\n");
				printf("----(Y/N)----\n");
				//문자입력을 버퍼없이 받고싶은데 뭔가 되지를 않습니다.
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
					printf("잘못된 입력입니다. 다시 입력해주십시오.\n\n");
			}
		}
		break;
	case '2': // 일단 전체출력만 구현해놓았습니다.
		for (i=0; i<count; ++i)
		{
			printf("====%d번 도서====\n", i);
			printf("제목 : %s\n", arr[i].title);
			printf("저자 : %s\n", arr[i].author);
			printf("페이지수 : %d\n", arr[i].page);
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
		printf("잘못된 입력입니다. 다시 입력해주십시오.\n");
		break;
	}
}