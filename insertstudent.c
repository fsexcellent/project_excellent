#include <stdio.h>
#include "head.h"

int input_student(student_t *pstu)
{
    static int id = 0;
again:
	printf("NAME\tAGE\tSCORE\n");
	if(scanf("%s%d%d",pstu->name,&(pstu->age),&(pstu->score)) != 3)
	{
		printf("Input invalid,input again!\n");
		while(getchar() != '\n');
		goto again;
	}

    id++;
    pstu->id = id;
	while(getchar()!= '\n');
	
	return 0;
}

int insert_student(Linklist *L)
{
	student_t stu;

	input_student(&stu);
    add_student_list(l,stu);	

	return 0;
}

