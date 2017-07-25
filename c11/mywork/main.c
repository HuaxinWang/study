#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int select_no = 0;
	student_t stu;
	list_t list;
	memset(&stu, 0, sizeof(stu));
	memset(&list, 0, sizeof(list));
	while(1)
	{
		memset(&stu, 0, sizeof(stu));
		print_menu();
		scanf("%d", &select_no);
		switch(select_no)
		{
			case MENU_ITEM_ADD:
				input_student_info(&stu);								
				add_student_to_list(&list, stu);
				break;
			case MENU_ITEM_DEL:
				del_student_from_list(&list, &stu);			
				break;
			case MENU_ITEM_UPDATE:
				update_student_info(&list);
				break;
			case MENU_ITEM_FIND:
				find_student_info(&list, &stu);
				print_student_info(stu);
				break;
			case MENU_ITEM_PRINT:
			print_students_info(&list);
				break;
			case MENU_ITEM_EXIT:
				printf("谢谢使用!!!\n");
				exit(0);
				break;
			default:
				break;
		}
	}
	return 0;
}
