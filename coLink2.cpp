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
	pNode head,temp,pre,p,q;//头结点仍有数据的指针（命名为不带头结点的指针） 
	           //head:指向第一个节点，temp:用于每次开辟空间,pre:用于标记上一个节点（变化的）
			   //pre:方便用于下一次：pre->next=temp; 即新开辟的空间=上一个节点的next指向 
	head=NULL;
	temp=NULL;
	pre=NULL;//初始化指针指向 
	p=NULL;//p指针用于输出 
//	printf("依次输入节点对应的值：\n");
	head=(pNode)malloc(sizeof(struct node));//首先为head申请一个空间即使链表为空，头结点也不为空 
	head->next=NULL;
	pre=head;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		q=head;
		temp=(pNode)malloc(sizeof(struct node));
		temp->info=x;
		while(q->next!=NULL){
			  if(q->next->info>temp->info)//保证q->next位置是最小的 
			     break;          //即最小的都比新值小，即停止循环，将新值插到q->next之后 
			  else
			     q=q->next; 
			
		}
	temp->next=q->next;//使用temp->next来保存q->next的位置
		q->next=temp;		
	}
	p=head->next; 	
	return head;
} 


pNode shunxun(pNode q,pNode p)
{
    pNode head1,k,h,t,pnew;
    head1=q;
    pnew=p->next;
    while(pnew!=NULL)
    {
        t=pnew;
        pnew=pnew->next;
        h=head1;
        k=head1->next;
      while(k!=NULL&&k->info<t->info)
      {
          h=k;
          k=k->next;
      }
      h->next=t;
      t->next=k;
    }
   return head1;
}

int main(){	
	int n1,n2,x; 
	pNode head,head1,head2,temp,pre,p1,p2;//头结点仍有数据的指针（命名为不带头结点的指针） 
	           //head:指向第一个节点，temp:用于每次开辟空间,pre:用于标记上一个节点（变化的）
			   //pre:方便用于下一次：pre->next=temp; 即新开辟的空间=上一个节点的next指向 
	scanf("%d",&n1);//n个节点 
	head1=createLink(n1);
	scanf("%d",&n2);//n个节点 
	head2=createLink(n2);
	head=shunxun(head1,head2);	
	p2=head->next;
	//printf("合并链表2的数据如下：\n");
	while(p2!=NULL){
		printf("%d ",p2->info);
		p2=p2->next;
	}
	return 0;
}
