int main()
{
    LinkList head = createEmptyList();
    if(head != NULL && head->next == NULL)
    {
	printf("A empty list is created\n");
    }
    else
    {
	printf("faild to create a empty list\n");
    }
    
    return 0;
}
