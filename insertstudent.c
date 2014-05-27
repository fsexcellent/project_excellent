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
<<<<<<< HEAD
	student_t stu;

	input_student(&stu);
    add_student_list(L,stu);	

=======
>>>>>>> 687c5f6766b69dcafbe18fa9a5653929ab12ed38
	return 0;
}

