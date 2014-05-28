#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"
#include "linklist.h"

#define INSERT 1 
#define DELETE 2 
#define MODIFY 3 
#define LOOKUP 4
#define QUIT   5
#define TO_FILE   6

#define NAMESIZE 10

manage_account_t accounts[2] = {
	{"admin", "123456", 1}, 
	{"normal", "123456", 0},
};

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

int login()
{
	char account[NAMESIZE];
	char password[NAMESIZE];
	int i = 0;
	int flag = 0;
	DATATYPE *stu;
	printf("account:");
	fgets(account, NAMESIZE, stdin);
	account[strlen(account) - 1] = '\0';	
	for(i = 0; i < sizeof(accounts) / sizeof(accounts[0]); i++)
	{
//		printf("%s, %s\n", account, accounts[i].name);
		if(strcmp(account, accounts[i].name) == 0)	
		{
			printf("password:");
			fgets(password, NAMESIZE, stdin);
			password[strlen(password) - 1] = '\0';	
			if(strcmp(password, accounts[i].password) == 0)
			{
				flag = 1; 
				break;
			}
			else
			{
				printf("invalid password!");		
				return -2;
			}
		}
	}

	if(flag == 0)
	{
		printf("invalid account!\n");	
		return -1;
	}
	
	return accounts[i].privilege;
}

int main(int argc, const char *argv[])
{
	int cmd, pri = 0;
	int login_times = 0; 
	int pass = 0;
	char ch;
	Linklist *L;

	while(login_times < 3)
	{
		pri = login();
		if(pri < 0)
		{
			printf("try again? y/n\n");	
			ch = getchar();				
			while(getchar() != '\n');
			if(ch == 'y' || ch == 'Y')
			{
				login_times++;	
				continue;
			}
			else
			{
				printf("system exit!\n");
				exit(-1);	
			}
		}
		else
		{
			pass = 1;
			break;		
		}
	}

	if(pass == 0)
	{
		printf("system exit!\n");
		exit(-1);	
	}

	L = create_empty_linklist();
	while(1)
	{
		help();
		printf("input cmd>");
		scanf("%d",&cmd);
		while(getchar() != '\n');

		switch(cmd)
		{
		case INSERT:
			if(pri == 1)
				insert_student(L);
			else
				printf("permission denied!\n");
			break;

		case MODIFY:
			if(pri == 1)
				modify_student(L);
			else
				printf("permission denied!\n");
			break;

		case DELETE:
			if(pri == 1)
				delete_student(L);
			else
				printf("permission denied!\n");
			break;

		case LOOKUP:
			lookup_student(L);
			break;

        case TO_FILE:
            to_file_student(L);
            break;

		case QUIT:
			goto next;
		
		default:
			continue;
		}
	}

next:
	return 0;
}
