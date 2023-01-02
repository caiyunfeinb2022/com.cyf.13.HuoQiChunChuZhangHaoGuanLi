#include<stdio.h>
#include<stdlib.h>

#define N 12
struct student
{
	char num[6];
	char name[4];
	int score[4];
}stu[N];

void input(struct student stu[])
{
	for (int i = 0; i < N; i++)
	{
		printf("\n 请输入第 %d 门课程\n", i + 1);
		printf("课程序号:");
		scanf("%s", stu[i].num);
		printf("课程名称:");
		scanf("%s", stu[i].name);
			for (int j = 0; j < 1; j++)
		{
			printf("学分:");
			scanf("%d", &stu[i].score[j]);
		}
		
		printf("\n");
	}
}

void output(struct student stu[])
{
	int j; 
	printf("\n 序号   课程名   学分\n");
	for (int i = 0; i < N; i++)
	{
		printf("%-6s%-10s", stu[i].num, stu[i].name);
		for (int j = 0; j < 1; j++)
		{
			printf("%-8d", stu[i].score[j]);
		}
		printf("\n");
	}
}

int main()
{
	input(stu);
	output(stu);
	system("pause");
	return 0;
}
