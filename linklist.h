#ifndef _LINK_H
#define _LINK_H

extern int do_free(Linklist *head);
extern int is_empty(Linklist *head);
extern int add_student_list(Linklist *head,DATATYPE data);
extern int delete_student_list(Linklist *head,DATATYPE *data);
extern DATATYPE *lookup_student_list(Linklist *head,DATATYPE *data);
extern int lookup_student_list_by_name(Linklist *head,char *name,Linklist **result);
extern DATATYPE *lookup_student_list_by_id(Linklist *head,int id);
#endif
