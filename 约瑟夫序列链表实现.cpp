#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int x;
	struct node *next;
}LNode,*LinkList;
LinkList Creat_LinkList()  
{
	LinkList head=NULL,last,p;
	int length;
	printf("����������:\n");
	scanf("%d",&length);
	p=(LinkList)malloc(sizeof(LNode));
	p->next=NULL;
	printf("����������Ԫ��:\n");
	for(int i=1;i<=length;i++)
	{
		if(head==NULL) head=last=p;
		else last->next=p;last=p;
		scanf("%d",&p->x);
		p=(LinkList)malloc(sizeof(LNode));
		p->next=NULL;
	}
	last->next=head;
	return head;
}

int josephus_LinkList(LinkList LL,int s,int m)
{
		LinkList p,pre;
		int count;
		if(!LL)
		{
			printf("������Ԫ��\n");
			return 0;
		}
		p=LL;
		for(count=1;count<s;count++)
			p=p->next;
		printf("Լɪ������Ϊ:\n");
		while(p!=p->next)
		{
			for(count=1;count<m;count++)
			{
				pre=p;
				p=p->next;
			}
			printf("%d ",p->x);
			pre->next=p->next;
			free(p);
			p=pre->next;
		}
		printf("%d\n",p->x);
		free(p);
		return 1;
}
int main()
{
	int m,s;
	LinkList head;
	printf("������������ӵڼ�����ʼ��������������:\n");
	scanf("%d%d",&s,&m);
	head=Creat_LinkList();
	josephus_LinkList(head,s,m);
	return 0;
}
