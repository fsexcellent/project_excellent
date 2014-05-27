#include <stdio.h>
#include "head.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int create_file()
{
    char buf[20];
    int fd;

again:
    printf("please input filename:");
    scanf("%s",buf);
    while(getchar() != '\n');

    if((fd = open(buf,O_WRONLY|O_CREAT|O_APPEND,0666)) < 0)
    {
        perror("open file failure");
        goto again;
    }

    return fd;
}

int print_to_file(Linklist *L,int fd)
{
    static int i = 0;
    Linklist *head = NULL;
    char buf[50] = "ID      NAME    AGE     SCORE\n";

    if(i == 0)
    {
        write(fd,buf,strlen(buf));
        i = 1;
    }

    for(head = L;head != NULL;head = head->next)
    {
        if(head->data.id != 0)
        {
            bzero(buf,sizeof(buf));
            sprintf(buf,"%-8d%-8s%-8d%-8d\n",head->data.id,head->data.name,head->data.age,head->data.score);
            write(fd,buf,strlen(buf));
        }

    }


    return 0;
}

int to_file_student(Linklist *L)
{
    int fd;

    fd = create_file();
    print_to_file(L,fd);

    return 0;
}

