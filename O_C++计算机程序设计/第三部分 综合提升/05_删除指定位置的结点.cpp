#include "linearList.h"

node * delAt(node * h, int i)
{
	if(i<0) //序号非法，不删除
		return h;
	node *p=NULL, *q = h; // 定位删除结点，试图让q指向要删除结点，p指向其前面的结点
	for(int k=0;k<i;k++)
	{
		if(q->next==NULL) //后面没有结点了，序号非法
			return h;
		p=q;
		q=q->next;
	}
	if(p) //p指向的结点存在，不是删除首结点
	{
		//删除q指向的结点，让p指向结点的指针域指向q的后续结点
		p->next = q->next;
		//释放空间
		delete q;
		return h;
	}
	else //删除首结点
	{
		h = q->next; //下一个结点成了首结点
		//释放空间
		delete q;
		return h;
	}
}
