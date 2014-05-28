#include <stdio.h>
#include "head.h"
#include "linklist.h"

void printf_linklist(Linklist *p)
{
    while(p->next != NULL)
    {
        printf("name\tage\tid\tscore\n");
        printf("%s\t%d\t%d\t%d\n",p->next->data.name,p->next->data.age,p->next->data.id,p->next->data.score);
    }
}

void printf_student(DATATYPE *q)
{
    printf("name\tage\tid\tscore\n");
    printf("%s\t%d\t%d\t%d\n",q->name,q->age,q->id,q->score);
}

void new_massage(DATATYPE *q)
{   
    char str[20];
    int m = 0;

    printf("New name :");
    fgets(atr,sizeof(str),stdin);
    printf("\n");
    q->name = atr;

    printf("New age : ");
    scanf("%d\n",&m);
    q->age = m;

    printf("New id : ");
    scanf("%d\n",&m);
    q->id = m;

    printf("New score : ");
    scanf("%d\n",&m);
    q->score = m;
}

int modify_student(Linklist *L)
{
    //printf("modify student!\n");
    printf("please into name\n");
    Linklist *p = NULL;
    char buf[20];
    int n = 0;
    int id = 0;
    DATATYPE *q = NULL;

    fgets(buf,sizeof(buf),stdin);
    n = lookup_student_list_by_name(L,buf,&p);
    if(n = 0)
    {
        printf("without the student !\n");
    }
    else if(n != 1)
    {
        printf("Please into ID who you want to modify !");
        printf_linklist(p);
        scanf("%d",&id);
        q = lookup_student_list_by_id(p,id);
        printf_student(q);
    }
    else if(n = 1)
    {
        printf_linklist(p);
        new_massage(q);
    }
    
	return 0;
}
