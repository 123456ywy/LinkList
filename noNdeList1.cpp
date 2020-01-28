#include<stdio.h> 
#include<stdlib.h>
//定义结构体
struct node{
	int info;
    struct node *next;	
};

int main(){
	
	int n,x; 
	struct node *head,*temp,*pre,*p;//头结点仍有数据的指针（命名为不带头结点的指针） 
	           //head:指向第一个节点，temp:用于每次开辟空间,pre:用于标记上一个节点（变化的）
			   //pre:方便用于下一次：pre->next=temp; 即新开辟的空间=上一个节点的next指向 
	head=NULL;
	temp=NULL;
	pre=NULL;//初始化指针指向 
	p=NULL;//p指针用于输出 
	scanf("%d",&n);//n个节点 
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=x;
		temp->next=NULL;
		if(i==0)//此时代表第一个节点 
			head=temp; //head用于标记，方便输出 
		else
		    pre->next=temp;
		pre=temp;
	}
	p=head; 
	while(p!=NULL){
		printf("%d\n",p->info);
		p=p->next;
	}
	return 0;
}
