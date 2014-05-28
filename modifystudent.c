#include <stdio.h>
#include "head.h"
#include "linklist.h"
#include "string.h"

void printf_linklist(Linklist *p)
{
    printf("NAME\tAGE\tID\tSCORE\n");
    while(p->next != NULL)
    {
        printf("%s\t%d\t%d\t%d\n",p->next->data.name,p->next->data.age,p->next->data.id,p->next->data.score);
        p = p->next;
    }
}

void printf_student(DATATYPE *q)
{
    printf("NAME\tAGE\tID\tSCORE\n");
    printf("%s\t%d\t%d\t%d\n",q->name,q->age,q->id,q->score);
}

void new_massage(DATATYPE *q)
{   
    char str[14];
    int m = 0;

    printf("New name :");
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = 0;
    strcpy(q->name,str);

    printf("New age : ");
    scanf("%d",&m);
    while(getchar() != '\n');
    q->age = m;

    printf("New score : ");
    scanf("%d",&m);
    while(getchar() != '\n');
    q->score = m;
}

int modify_student(Linklist *L)
{
    //printf("modify student!\n");
    Linklist *p = NULL;
    char buf[20];
    int n = 0;
    int id = 0;
    DATATYPE *q = NULL;

    printf_linklist(L);
    printf("name:");
    fgets(buf,sizeof(buf),stdin);
    buf[strlen(buf) -1] = 0;
    n = lookup_student_list_by_name(L,buf,&p);
    
    if(n == 0)
    {
        printf("the student no exist!\n");
    }
    else if(n > 0)
    {
        printf_linklist(p);
        printf("Please input ID who you want to modify !\n");
        scanf("%d",&id);
        while(getchar() != '\n');
        q = lookup_student_list_by_id(L,id);
        if(q == NULL)
        {
            printf("id no exist!\n");
            return -1;
        }
        printf_student(q);
        new_massage(q);
    }
    /*else if(n = 1)*/
    /*{*/
        /*printf_student(q);*/
        /*new_massage(q);*/
    /*}*/
    
	return 0;
}
