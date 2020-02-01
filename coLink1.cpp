#include<stdio.h> 
#include<stdlib.h>
//定义结构体
typedef struct node *pNode;
struct node{
	int info;
    pNode next;	
};

pNode createLink(int n){
	int x;
		pNode head,temp,pre,p;//头结点仍有数据的指针（命名为不带头结点的指针） 
	           //head:指向第一个节点，temp:用于每次开辟空间,pre:用于标记上一个节点（变化的）
			   //pre:方便用于下一次：pre->next=temp; 即新开辟的空间=上一个节点的next指向 
	head=NULL;
	temp=NULL;
	pre=NULL;//初始化指针指向 
	p=NULL;//p指针用于输出 
//	printf("依次输入节点对应的值：\n");
	head=(pNode)malloc(sizeof(struct node));//首先为head申请一个空间即使链表为空，头结点也不为空 
	pre=head;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		temp=(pNode)malloc(sizeof(struct node));
		temp->info=x;
		temp->next=NULL;
		pre->next=temp;
		pre=temp;		
	}
	p=head->next; 	
	return head;
} 
int main(){	
	int n1,n2,x; 
	pNode head1,head2,temp,pre,p1,p2;//头结点仍有数据的指针（命名为不带头结点的指针） 
	           //head:指向第一个节点，temp:用于每次开辟空间,pre:用于标记上一个节点（变化的）
			   //pre:方便用于下一次：pre->next=temp; 即新开辟的空间=上一个节点的next指向 
//	printf("输入链表1的节点个数："); 
	scanf("%d",&n1);//n个节点 
	head1=createLink(n1);
//	printf("输入链表2的节点个数：");
	scanf("%d",&n2);//n个节点 
	head2=createLink(n2);
	p1=head1->next; 
	//printf("链表1的数据如下：\n");
	while(p1->next!=NULL){
		//printf("%d\n",p1->info);
		p1=p1->next;
	}
	p1->next=head2->next;	
	p2=head1->next;
	//printf("合并链表2的数据如下：\n");
	while(p2!=NULL){
		printf("%d ",p2->info);
		p2=p2->next;
	}
	return 0;
}
