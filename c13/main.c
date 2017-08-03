#include <stdio.h>
#include "link_list.h"

int main(int argc, char *argv[])
{
	int i = 0;
	datatype_t tmp = 0;

	link_list_t l = create_empty_link_list();

	if(is_link_list_empty(l))
		printf("link list empty\n");

	for(i = 0; i < 10; i++)
		insert_into_link_list_by_postion(l, i+1, i);

	printf("length : %d\n", length_of_link_list(l));

	print_link_list_data_info(l);

	reverse_link_list(l);

	printf("after reverse : \n");

	print_link_list_data_info(l);

	insert_into_link_list_by_postion(l, 5, 100);

	delete_from_link_list_by_postion(l, 7, &tmp);

	printf("after insert at postion 5 : \n");

	print_link_list_data_info(l);

	insert_head(l,250);

	printf("after insert at head: \n");
	
	print_link_list_data_info(l);

	insert_back(l,250);
	
	printf("after insert at back: \n");
	
	print_link_list_data_info(l);



	clear_link_list(l);

	print_link_list_data_info(l);

	destroy_link_list(l), l = NULL;
	return 0;
}
