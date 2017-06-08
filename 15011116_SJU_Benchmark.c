#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 2��° �ɼ��� �������� Ȯ�� */
int is_int(char *s)
{
	size_t size = strlen(s);

	if (size == 0) return 0;
	
	// size ��ŭ Ž���ϸ鼭 ���ڰ� �ƴ� ���� �ִ��� Ȯ��
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

	/* ���� ���� */
	if (argc != 3)	// ���ڰ� 3���� �ƴ� ��
	{
		fprintf(stderr, "������ ������ �߸��Ǿ����ϴ�.\n");
		exit(-1);
	}

	/* ���ڰ� �������� �� */
	else
	{
		/* ���� �Ǻ� �� �Է� Ƚ�� ���� */
		if (is_int(argv[2]))
		{
			count = atoi(argv[2]);	// ���ڷ� ���� ���ڸ� int�� ������ ��ȯ
		}
		else
		{
			fprintf(stderr, "Ƚ���� ��Ȯ�ϰ� �Է��Ͽ��ֽʽÿ�.\n");
			exit(-1);
		}

		for (int i = 0; i < count; i++)
		{
			// ���α׷� ����
			clock_t begin = clock();
			system(argv[1]);
			clock_t end = clock();
			// ���α׷� ����

			printf(".");

			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; // ���α׷� ���� �ð� ���
			total_time += time_spent; // �� ����ð�
		}
		printf("\n%f��ŭ �ҿ�Ǿ����ϴ�.\n", total_time);
	}
}