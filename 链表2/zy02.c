#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
typedef struct xs{
	int data;
	int *next;
}link;

link* init();//初始化
void initlist(link *hd,int n);//初始化赋值
void insert(link *hd,int n,int c);//插入
link* search(link *hd,int n);//查找
link* dele(link *hd,int n);//删除
int dele1(link *hd,int n);
void display(link *hd);//遍历显示
void deleall(link *hd);//删除整个链表
void clear(link *hd,int n);
int main()
{	
	int n,c;
	link *hd=NULL,*w=NULL;
	hd=init();w=init();
	printf("请输入初始链表1的长度\n");
	scanf("%d",&n);
	initlist(hd,n);
				printf("请输入初始链表2的长度\n");
				scanf("%d",&c);
				initlist(w,c);
	printf("两集合合并：\n");
	insert(hd,w,n,c);printf("并集为：\n");
	clear(hd,n+c);
	display(hd);
	printf("开始清空链表：\n");
	deleall(hd);
	return 0;
}
void clear(link *hd,int n)
{
	int i,j,f;
	link *p=hd,*w,*e;

	for(i=1;i<n;i++)
	{
		w=search(hd,i);
		for(j=i+1;j<=n;j++)
		{	e=search(hd,j);
	
			if(w->data==e->data)
			{	
				f=dele1(hd,j);
				if(f==-1)
					break;
			j--;n--;
			}
		}
	}
}
void insert(link *hd,link *w,int n,int c)//n=链表1的长度，c=链表2的长度
{
	int i=0,b=0;
	link *p,*e;
	p=search(hd,n-1);
while(i<c)
{
	e=dele(w,1);
	if(e==NULL)
	{	break;
	}
	e->next=p->next;
	p->next=e;
	i++;
		
}
	display(hd);
}
void deleall(link *hd)
{
	link *p,*q;
	p=hd->next;
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	hd->next=NULL;
	display(hd);

}
void display(link *hd)
{
	link *p=hd;
	printf("操作结果：");
	while(p->next)
	{
		p=p->next;
		printf("%d ",p->data);
	}
	printf("\n");
}
int dele1(link *hd,int n)
{
	
	link *q,*p;
	p=search(hd,n-1);
	if(!p)
		return -1;
	q=p->next;
	p->next=q->next;
	free(q);
	return 0;
}
link* dele(link *hd,int n)
{
	link *q,*p;
	p=search(hd,n-1);
	if(!p)
		return NULL;
	q=p->next;
	p->next=q->next;
	return q;

}
link* search(link *hd,int n)
{
	int i=0;
	link *p;
	p=hd;
	while(p&&i<n)
	{	p=p->next;
		i++;
	}
	if(!p||i>n)
		return NULL;
	return p;

}
void initlist(link *hd,int n)
{
	int i;
	link *p;
		for(i=0;i<n;i++)
	{
		p=(link *)malloc(sizeof(link));
		p->data=i;
		p->next=hd->next;
		hd->next=p;
	}
		display(hd);
}
link* init()
{
	link *hd=(link *)malloc(sizeof(link));
	hd->next=NULL;
	return  hd;
}
