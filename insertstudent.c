#include <stdio.h>
#include "head.h"

int input_student(student_t *pstu)
{
again:
	printf("NAME\tAGE\tID\tSCORE\n");
	if(scanf("%s%d%d%d",pstu->name,&(pstu->age),&(pstu->id),&(pstu->score)) != 4)
	{
		printf("Input invalid,input again!\n");
		while(getchar() != '\n');
		goto again;
	}

	while(getchar()!= '\n');
	
	return 0;
}

int insert_student(Linklist *L)
{
	student_t stu;

	input_student(&stu);
	insert_student(L,stu);

	return 0;
}

