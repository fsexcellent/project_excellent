#include <stdio.h>
#include <stdlib.h>
#include "head.h"

Linklist *create_empty_linklist()
{
	Linklist *head;

    head = (Linklist *)malloc(sizeof(Linklist));

    bzero(head,sizeof(Linklist));
    head->next = NULL; 
	
	return  head;
}

int is_empty(Linklist *head)
{
    if(head->next == NULL)
    {
        return 1;
    }

    return 0;
}

int delete_student_list(Linklist *head,DATATYPE *data)
{
    Linklist *tmp = NULL;

    while(head->next != NULL)
    {
        if(memcmp(&(head->next->data),data,sizeof(DATATYPE)) == 0)
        {
            tmp = head->next;
            head->next = tmp->next;
            free(tmp);
            return 0;
        }

        head = head->next;
    }

    return -1;
}

int add_student_list(Linklist *head,DATATYPE data)
{
    Linklist *p = (Linklist *)malloc(sizeof(Linklist));

    p->next = head->next;
    p->data = data;
    head->next = p;

    return 0;
}

int lookup_student_list_by_name(Linklist *head,char *name,Linklist **result)
{
    int num = 0;
    *result = create_empty_linklist();

    while(head->next != NULL)
    {
        if(strcmp(head->next->data.name,name) == 0)
        {
            add_student_list(*result,head->next->data);
            num++;
        }

        head = head->next;
    }

    if(num == 0)
    {
        free(*result);
    }

    return num;
}

DATATYPE *lookup_student_list_by_id(Linklist *head,int id)
{
    while(head->next != NULL)
    {
        if(head->next->data.id == id)
        {
            return &(head->next->data);
        }

        head = head->next;
    }

    return NULL;
}

int do_free(Linklist *head)
{
    Linklist *tmp = NULL;

    while(head)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }

    return 0;
}
