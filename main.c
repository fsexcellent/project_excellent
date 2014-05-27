#include <stdio.h>
#include "head.h"
#include "linklist.h"

#define INSERT 1 
#define DELETE 2 
#define MODIFY 3 
#define LOOKUP 4
#define QUIT   5
#define TO_FILE   6

void help()
{
	printf("----------学生管理系统---------\n");
	printf("1.增加学生信息\n");
	printf("2.删除学生信息\n");
	printf("3.修改学生信息\n");
	printf("4.查找学生信息\n");
	printf("5.退出学生管理系统\n");
	printf("6.打印学生信息到文件\n");
	printf("-------------------------------\n\n\n");
	return ;
}

int main(int argc, const char *argv[])
{
	int cmd;
	Linklist *L = create_empty_linklist();

	while(1)
	{
		help();
		printf("input cmd>");
		scanf("%d",&cmd);

		switch(cmd)
		{
		case INSERT:
			insert_student(L);
			break;

		case MODIFY:
			modify_student(L);
			break;

		case DELETE:
			delete_student(L);
			break;

		case LOOKUP:
			lookup_student(L);
			break;

        case TO_FILE:
            to_file_student(L);
            break;

		case QUIT:
			goto next;
		}
	}

next:
	return 0;
}
