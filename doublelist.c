#include"doublelist.h"

ListNode* BuyListNode(LTDataType x) 
{
	  ListNode *buy = (ListNode *)malloc(sizeof(ListNode));
         buy->_next = NULL;
		 buy->_prev = NULL;
		 buy->_data = x;

		 return buy;
}
void ListInit(List* lt)
{
	//��ʼ��������ʹǰһ������һ����ָ����
	assert(lt);
	lt->_head =  BuyListNode(0);
	lt->_head->_next = lt->_head;
	lt->_head->_prev = lt->_head;

}
void ListDestory(List* lt)
{
	 ListNode * cur = NULL;
	   assert(lt);
	   assert(lt->_head);
	   while(lt->_head->_next != lt->_head->_prev)
	  {
		  ListErase(lt->_head->_next);

	  }
	   free(lt->_head);
	   lt->_head = NULL;


}
void ListPushBack(List* lt, LTDataType x)
{
	//ǰ�壬β�壬����һ���ģ�����ѭ����
	ListNode * buy = NULL;	
	assert(lt);
	buy = BuyListNode(x);
	buy->_prev = lt->_head->_prev;
	lt->_head->_prev->_next = buy;
	buy->_next = lt->_head;
	lt->_head->_prev = buy;
	
	

}
void ListPushFront(List* lt, LTDataType x)
{
	ListNode * buy = NULL;	

	assert(lt);
	buy = BuyListNode(x);
	buy->_prev = lt->_head->_prev;
	lt->_head->_prev->_next = buy;
	buy->_next = lt->_head;
	lt->_head->_prev = buy;
}
void ListPopBack(List* lt)
{
    assert(lt);
	ListErase(lt->_head->_prev);
}
void ListPopFront(List* lt)
{
	assert(lt);
	ListErase(lt->_head->_next);
}
ListNode* ListFind(List* lt, LTDataType x); 
void ListInsert(ListNode* pos, LTDataType x)
{
	//����λ�õĲ��벻��Ҫ����һ�飬ֻ��Ҫ�ҵ�����PREV

	ListNode * buy = NULL;	
	assert(pos);
	buy = BuyListNode(x);
	buy->_prev = pos->_prev;
	pos->_prev->_next = buy;
	buy->_next = pos;
	pos->_prev = buy;
	
}
void ListErase(ListNode* pos)
{
	ListNode * cur = NULL;
	assert(pos);

	 cur = pos->_next;
	 cur->_prev = pos->_prev;
	 pos->_prev->_next = cur;
	 free(pos);


}
int ListSize(List* lt)
{
	int size = 0;
	ListNode * cur = NULL;
	cur = lt->_head;
	assert(lt);
	while(cur->_next != lt->_head)
	{
		++size;
		cur = cur->_next;

	}
	return size;
}
int ListEmpty(List* lt)
{
	 assert(lt);
	 if (lt->_head->_next == lt->_head->_prev)
	        return 0;
	 else 
		 return 1;	  

}
void ListPrint(List* lt)
{
	ListNode * cur = NULL;
	assert(lt);
	assert(lt->_head);
	
	cur = lt->_head->_next;
	while(cur->_next != lt->_head)
	{
		printf("%d \n",cur->_data);
		cur = cur->_next;
	}
		printf("%d \n",cur->_data);

}
	 