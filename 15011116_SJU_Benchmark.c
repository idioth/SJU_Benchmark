#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 2번째 옵션이 숫자인지 확인 */
int is_int(char *s)
{
	size_t size = strlen(s);

	if (size == 0) return 0;
	
	// size 만큼 탐색하면서 숫자가 아닌 것이 있는지 확인
	for (int i = 0; i < (int)size; i++)
	{
		if (s[i] <'0' || s[i] >'9')
			return 0;
	}

	return 1;
}

int main(int argc, char *argv[])
{
	int count;
	double time_spent, total_time = 0;

	/* 인자 오류 */
	if (argc != 3)	// 인자가 3개가 아닐 때
	{
		fprintf(stderr, "인자의 개수가 잘못되었습니다.\n");
		exit(-1);
	}

	/* 인자가 정상적일 때 */
	else
	{
		/* 정수 판별 및 입력 횟수 저장 */
		if (is_int(argv[2]))
		{
			count = atoi(argv[2]);	// 문자로 받은 숫자를 int형 정수로 변환
		}
		else
		{
			fprintf(stderr, "횟수를 정확하게 입력하여주십시오.\n");
			exit(-1);
		}

		for (int i = 0; i < count; i++)
		{
			// 프로그램 시작
			clock_t begin = clock();
			system(argv[1]);
			clock_t end = clock();
			// 프로그램 종료

			printf(".");

			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; // 프로그램 수행 시간 계산
			total_time += time_spent; // 총 수행시간
		}
		printf("\n%f만큼 소요되었습니다.\n", total_time);
	}
}