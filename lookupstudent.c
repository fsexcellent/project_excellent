#include <stdio.h>
#include "head.h"
#include <string.h>
#include "linklist.h"

#define ID 1
#define NAME 2

int lookup_student(Linklist *L)
{
    int i;
    int type;
    int id;
    int num;
    char name[14];
    DATATYPE *ret;
    Linklist *result;

	printf("lookup  student!\n");
    printf("Please chose type.\n");
    printf("1.id 2.name.\n");

    scanf("%d",&type);    
    getchar();

    if(ID == type)
    {
        printf("id>");
        scanf("%d",&id);    
        getchar();

        ret = lookup_student_list_by_id(L,id);
        if(NULL == ret)
        {
            printf("Not exist.\n");
            return -1;
        }

        printf("name\tage\tid\tscore\n");
        printf("%s\t%d\t%d\t%d\n",\
            ret->name, ret->age, ret->id, ret->score); 
        
    }
    if(NAME == type)
    {
        printf("name>");
        fgets(name,sizeof(name),stdin);    
        name[strlen(name) - 1] = 0; 
        Linklist *p;

        num = lookup_student_list_by_name(L,name,&result);
        if(num == 0)
        {
            printf("Not exist.\n");
            return -1;
        }

        p = result->next;
        printf("  name\tage\tid\tscore\n");

        for(i = 1;i <= num;i++)
        {
            printf("%d.",i);
            printf("%s\t%d\t%d\t%d\n",\
            p->data.name, p->data.age, p->data.id, p->data.score); 

            p = p->next;
        } 

    }

	return 0;
}
