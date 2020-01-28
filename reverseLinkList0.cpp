#include<stdio.h> 
#include<stdlib.h>
//定义结构体
typedef struct node *pnode; 
typedef struct node *plinkList;
struct node{
	int info;
   pnode next;	
};
plinkList  reverse(plinkList head){//链表倒置函数，主函数传递头指针参数 
plinkList p,q,temp; //p用来循环移动的点，
                    //temp用于临时保存p->next的指针
					//q用于指向交换链接后的 最后一个节点
					 //指针，便于新断开后的p直接链接上q即可 
 p=head->next;//带头结点的指针，即去除头结点开始循环 
 q=NULL;
 head->next=NULL;//将 head->next指向为空，便于将倒置后的链表再次与头结点相连 
while(p){
	temp=p->next;//temp用于临时保存p->next的指针
	p->next=q;//连接p与q 
	q=p;//q向前移动（新链表） 
	p=temp; //p指针向后移动指向	（旧链表） 
	//结束循环后q永远指向第一个节点,(但此时节点的数据已经交换好) 
}	
 head->next=q;//将倒置后的链表再次与头结点相连
 return head;		
}



int main(){
		int n,x; 
plinkList head,temp,pre,p,pNew;//头结点仍有数据的指针（命名为不带头结点的指针） 
	           //head:指向第一个节点，temp:用于每次开辟空间,pre:用于标记上一个节点（变化的）
			   //pre:方便用于下一次：pre->next=temp; 即新开辟的空间=上一个节点的next指向 
	head=NULL;
	temp=NULL;
	pre=NULL;//初始化指针指向 
	p=NULL;//p指针用于输出 
	printf("请输入节点的个数:");
	scanf("%d",&n);//n个节点 
	head=(struct node *)malloc(sizeof(struct node));//首先为head申请一个空间即使链表为空，头结点也不为空 
	pre=head;
	for(int i=0;i<n;i++){
		printf("第%d个节点的值",i+1);
		scanf("%d",&x);
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=x;
		temp->next=NULL;
		pre->next=temp;
		pre=temp;		
	}
	p=head->next; 
	printf("初始链表的数据依次为：\n");
	while(p!=NULL){
		printf("%d\n",p->info);
		p=p->next;
	}
plinkList head1=reverse(head);
	      pNew=head1->next;
	printf("倒置后的链表数据依次为：\n");
	while(pNew!=NULL){
		printf("%d\n",pNew->info);
		pNew=pNew->next;
	}
	
	return 0;
}
