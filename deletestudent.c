#include <stdio.h>
#include "head.h"
#include <string.h>
#include "linklist.h"

int delete_student(Linklist *L)
{
    
    Linklist *head;
    Linklist *namelist;
    DATATYPE *stu1;
    char name[100];
    int choice_n;
    int id;
    int ensure;
    int number_name;
  

    while(1)
    {
        head = L->next;
        if(head == NULL)
        {
            puts("Empty Linklist,Please add students first!");
            return 0;
        }
        printf("name\tage\tid\tscore\n");

        while(head)
        {
            printf("%s\t%d\t%d\t%d\n",head->data.name, head->data.age, head->data.id, head->data.score);
            head = head->next;
        }

        puts("Please insert your choice to lookup,1 for id,2 for name,0 for quit!");
        scanf("%d",&choice_n);
        while(getchar() != '\n');
        if(1 == choice_n)
        {
            puts("Please input your id:");
            scanf("%d",&id);
            while(getchar() != '\n');
            
            stu1 = lookup_student_list_by_id(L,id);
            printf("name\tage\tid\tscore\n");
            printf("%s\t%d\t%d\t%d\n",stu1->name, stu1->age, stu1->id, stu1->score);
            delete_student_list(L,stu1);
        }
        else if(2 == choice_n)
        {
            puts("Please input the name you want to delete");
            scanf("%s",name);
            while(getchar() != '\n');

            name[strlen(name)] = '\0';
            puts(name);

            number_name = lookup_student_list_by_name(L,name,&namelist);
            if(number_name)
            {
                printf("There are %d students for %s\n",number_name,name);
            }
            else
            {
                puts("No student match!");
                continue;
            }
            head = namelist->next;
            printf("name\tage\tid\tscore\n");

            while(head)
            {
                *stu1 = head->data;
                printf("%s\t%d\t%d\t%d\n",stu1->name, stu1->age, stu1->id, stu1->score);
                delete_student_list(L,stu1);

                head = head->next;
            }
        }
        else if(0 == choice_n)
        {
            puts("Are you want to quit delate? input 0 to ensure");
            scanf("%d",&ensure);
            while(getchar() != '\n');

            if(0 == ensure)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        else
        {
            puts("Your input is invalid,please input again!");
            continue;
        }
    }
	printf("delete student!\n");
	return 0;
}
