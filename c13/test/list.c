static LNode *createNewNode(int value)
{
    LNode *newNode = NULL;
    newNode = (LNode *)calloc(1,sizeof(LNode));
    if(newNode == NULL)
    {
	return NULL;
    }
    newNode->next = NULL;

    newNode->data = value;
    return newNode;
}

LinkList createEmptyList()
{
    return createNewNode(-1);
}

static LNode *insertAt(LNode *p1,int value)
{
    assert(p1 != NULL);

    LNode *newNode = creatNewNode(value);
    if(newNode != NULL)
    {
	newNode->next = p1->next;
	p1->next = newNode;
    }
    return newNode;
}

int insertFromHead(LinkList list,int values[],size_t size)
{
    assert
}
