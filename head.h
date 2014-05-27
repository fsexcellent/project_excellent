#ifndef _HEAD_H 
#define _HEAD_H 

typedef struct 
{
	char name[14];
	int  age;
	int  id;
	int  score;
}student_t;

typedef student_t DATATYPE;

typedef struct node 
{
	DATATYPE data;
	struct node *next;
}Linklist;

extern Linklist *create_empty_linklist();
extern int insert_student(Linklist *L);
extern int modify_student(Linklist *L);
extern int delete_student(Linklist *L);
extern int lookup_student(Linklist *L);
extern int to_file_student(Linklist *L);

#endif 
