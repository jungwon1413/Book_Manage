#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct BOOK
{
	char* title;
	char* author;
	int page;
};

struct BOOK_INFO
{
	BOOK books[200];
	int bookCount;
};



void FreeBook (BOOK* bk)
{
	free(bk->title);
	free(bk->author);
}

void InputBookTitle(BOOK* bk)
{
	char buf[500];

	printf("제목을 입력하세요: ");
	gets_s(buf, 500);

	bk->title = (char*)malloc(strlen(buf)+1);
	
	strcpy_s(bk->title, strlen(buf)+1, buf);
}

void InputBookAuthor(BOOK* bk)
{
	char buf[500];

	printf("저자를 입력하세요: ");
	gets_s(buf, 500);

	bk->author = (char*)malloc(strlen(buf)+1);
	
	strcpy_s(bk->author, strlen(buf)+1, buf);
}

void InputBookPage(BOOK* bk)
{
	printf("페이지 수: ");
	scanf_s("%d", &bk->page, sizeof(int));
}

void InputBook(BOOK_INFO* bkarr)
{
	InputBookTitle(&bkarr->books[bkarr->bookCount]);
	InputBookAuthor(&bkarr->books[bkarr->bookCount]);
	InputBookPage(&bkarr->books[bkarr->bookCount]);
	fflush(stdin); // 다르게 바꿀 방법을 고민해봅시다.
	bkarr->bookCount++;
}

void PrintBookTitle(BOOK* bk)
{
	printf("제목: %s\n", bk->title);
}

void PrintBookAuthor(BOOK* bk)
{
	printf("저자: %s\n", bk->author);
}

void PrintBookPage(BOOK* bk)
{
	printf("페이지수: %d\n", bk->page);
}

void PrintBook(BOOK_INFO* bkarr)
{
	int i;
	for (i=0; i<bkarr->bookCount; ++i)
	{
		PrintBookTitle(&bkarr->books[i]);
		PrintBookAuthor(&bkarr->books[i]);
		PrintBookPage(&bkarr->books[i]);
		printf("\n");
	}
}

void SearchBookTitle(BOOK_INFO* bkarr)
{
	int i;
	int check;
	int status = 0;
	char buf[500];

	printf("제목 검색: ");
	gets_s(buf, 500);

	for (i=0; i < bkarr->bookCount; ++i)
	{
		check = strcmp(bkarr->books[i].title, buf);
		if (check == 0)
		{
			printf("\n[%d]\n", i+1);
			PrintBookTitle(&bkarr->books[i]);
			PrintBookAuthor(&bkarr->books[i]);
			PrintBookPage(&bkarr->books[i]);
			status = 1; // 하나라도 찾으면 status가 1로 변함
		}
		check = 1; // 검색비교자 리셋
	}

	if (status == 0)
		printf("\n해당 서적은 검색 결과에 없습니다.\n");
}

void SearchBookAuthor(BOOK_INFO* bkarr)
{
	int i;
	int check;
	int status = 0;
	char buf[500];

	printf("저자 검색: ");
	gets_s(buf, 500);

	for (i=0; i < bkarr->bookCount; ++i)
	{
		check = strcmp(bkarr->books[i].author, buf);
		if (check == 0)
		{
			printf("\n[%d]\n", i+1);
			PrintBookTitle(&bkarr->books[i]);
			PrintBookAuthor(&bkarr->books[i]);
			PrintBookPage(&bkarr->books[i]);
			status = 1; // 하나라도 찾으면 status가 1로 변함
		}
		check = 1; // 검색비교자 리셋
	}

	if (status == 0)
		printf("\n해당 서적은 검색 결과에 없습니다.\n");
}

void SearchBook(BOOK_INFO* bkarr)
{
	int input = 1;
	
	while(input)
	{
		printf("\n찾는 항목을 선택하세요\n");
		printf("1. 제목\n");
		printf("2. 저자\n");
		printf("0. 검색 종료\n");
		switch(_getch())
		{
			case '1':
				SearchBookTitle(bkarr);
				break;
			case '2':
				SearchBookAuthor(bkarr);
				break;
			case '0':
				printf("검색을 종료합니다.\n");
				input = 0;
				break;
			default:
				printf("잘못된 입력입니다.\n");
				break;
		}
	}
}

void FileSaveBook(BOOK_INFO* bkarr)
{
	int i;
	FILE* pf;
	fopen_s(&pf, "BookData.txt", "wt");
	for (i=0; i<bkarr->bookCount; ++i)
	{
		fprintf(pf, "[%d번]\n", i+1);
		fprintf(pf, "제목: %s\n", bkarr->books[i].title);
		fprintf(pf, "저자: %s\n", bkarr->books[i].author);
		fprintf(pf, "페이지수: %d\n\n", bkarr->books[i].page);
	}
	fclose(pf);
}

void ReadBinaryFile(BOOK_INFO* bkarr)
{
	FILE* pf;
	int i;

	fopen_s(&pf, "Book_Info.dsf", "rb");
	if (pf == NULL)
		return;
	fread(&bkarr->bookCount, sizeof(int), 1, pf);
	for (i=0; i<bkarr->bookCount; ++i)
	{
		int slen;
		fread(&slen, sizeof(int), 1, pf);
		bkarr->books[i].title = (char*) malloc (slen);
		fread(bkarr->books[i].title, slen, 1, pf);

		fread(&slen, sizeof(int), 1, pf);
		bkarr->books[i].author = (char*) malloc (slen);
		fread(bkarr->books[i].author, slen, 1, pf);
		
		fread(&bkarr->books[i].page, sizeof(int), 1, pf);
	}
	fclose(pf);
}

void WriteBinaryFile(BOOK_INFO* bkarr)
{
	FILE* pf;
	int i;

	fopen_s(&pf, "Book_Info.dsf", "wb");
	fwrite(&bkarr->bookCount, sizeof(int), 1, pf);
	for (i=0; i<bkarr->bookCount; ++i)
	{
		int slen = strlen(bkarr->books[i].title)+1;
		fwrite(&slen, sizeof(int), 1, pf);
		fwrite(bkarr->books[i].title, slen, 1, pf);

		slen = strlen(bkarr->books[i].author)+1;
		fwrite(&slen, sizeof(int), 1, pf);
		fwrite(bkarr->books[i].author, slen, 1, pf);

		slen = bkarr->books[i].page;
		fwrite(&slen, sizeof(int), 1, pf);
	}
	fclose(pf);
}


void ResetBook(BOOK_INFO* bkarr) // 완전리셋
{
	int i;
	char check;
	printf("모든 데이터를 삭제합니다. 정말 동의하십니까? (Y/N)\n");

	check = _getch();
	switch(check)
	{
		if (check == 'y' || check == 'Y')
		{
			case 'Y':
			case 'y':
				for (i=0; i<bkarr->bookCount; ++i)
				{
					FreeBook(&bkarr->books[i]);
				}
				bkarr->bookCount = 0;
				WriteBinaryFile(bkarr);
				printf("***모든 데이터를 제거하였습니다.***\n");
				break;
		}
		else if (check == 'n' || check == 'N')
		{
			case 'N':
			case 'n':
				printf("해당 작업을 종료합니다.\n");
				break;
		}
		else
		{
			default:
				printf("올바른 입력이 아닙니다.\n");
				ResetBook(bkarr);
				break;
		}
	}
}

void DeleteBook(BOOK_INFO* bkarr) // 선택삭제
{
	int i;
	int num;
	int input = 1;
	
	while (input)
	{
		printf("원하는 항목의 번호를 적어주세요: ");
		scanf_s("%d\n", &num);

		if (num<=0 || num>bkarr->bookCount)
			printf("해당 번호는 존재하지않습니다.\n");
		else
		{
			for (i=num; i<bkarr->bookCount; ++i)
			{
				if (i < bkarr->bookCount-1)
				{
					int slen = strlen(bkarr->books[i+1].title)+1;
					FreeBook(&bkarr->books[i]);
					bkarr->books[i].title = (char*)malloc(slen);
					bkarr->books[i].title = bkarr->books[i+1].title;

					slen = strlen(bkarr->books[i+1].author)+1;
					FreeBook(&bkarr->books[i]);
					bkarr->books[i].author = (char*)malloc(slen);
					bkarr->books[i].author = bkarr->books[i+1].author;

					bkarr->books[i].page = bkarr->books[i+1].page;
				}
				else
					FreeBook(&bkarr->books[i]);
			}
			input = 0;
		}
	}
}

void RemoveBook(BOOK_INFO* bkarr)
{
	int input = 1;

	while(input)
	{
		printf("\n원하는 메뉴를 선택하세요\n");
		printf("1. 전체 삭제 (모든 자료 삭제)\n");
		printf("2. 선택 삭제\n");
		printf("0. 삭제메뉴 종료\n");
		switch(_getch())
		{
		case '1':
			ResetBook(bkarr);
			break;
		case '2':
			DeleteBook(bkarr);
			break;
		case '0':
			printf("삭제메뉴를 종료합니다.\n");
			input = 0;
			break;
		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
}

void MENU()
{
	printf("==================\n");
	printf("1. 도서정보 입력\n");
	printf("2. 도서정보 출력\n");
	printf("3. 도서정보 파일저장\n");
	printf("4. 도서정보 검색\n");
	printf("5. 도서정보 삭제\n");
	printf("0. 프로그램 종료\n");
	printf("==================\n");
}

void RUN(BOOK_INFO* bkArray)
{
	int run = 1;
	while (run)
	{
		MENU();
		switch(_getch())
		{
		case '1':
			InputBook(bkArray);
			break;
		case '2':
			PrintBook(bkArray);
			break;
		case '3':
			FileSaveBook(bkArray);
			break;
		case '4':
			SearchBook(bkArray);
			break;
		case '5':
			RemoveBook(bkArray);
			break;
		case '0':
			printf("***프로그램을 종료합니다.***\n");
			run = 0;
			break;
		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
}

void InitBook(BOOK_INFO* bkarr)
{
	bkarr->bookCount = 0;
	ReadBinaryFile(bkarr);	
}

void EndBook(BOOK_INFO* bkarr)
{
	WriteBinaryFile(bkarr);
	int i;
	for (i=0; i<bkarr->bookCount; ++i)
		FreeBook(&bkarr->books[i]);
}

void main()
{
	BOOK_INFO bkArray;

	InitBook(&bkArray);
	RUN(&bkArray);
	EndBook(&bkArray);
}
