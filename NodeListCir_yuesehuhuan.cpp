#include<stdio.h> 
#include<stdlib.h>
//定义结构体
struct node{
	int info;
    struct node *next;	
};
int n,s,m;

struct node* creat_xunhuanList(){ 
	struct node *head,*temp,*pre,*p;//头结点仍有数据的指针（命名为不带头结点的指针） 
	           //head:指向第一个节点，temp:用于每次开辟空间,pre:用于标记上一个节点（变化的）
			   //pre:方便用于下一次：pre->next=temp; 即新开辟的空间=上一个节点的next指向 
	head=NULL;
	temp=NULL;
	pre=NULL;//初始化指针指向 
	p=NULL;//p指针用于输出 
//	head=(struct node *)malloc(sizeof(struct node));//首先为head申请一个空间即使链表为空，头结点也不为空 

	for(int i=0;i<n;i++){	
		temp=(struct node *)malloc(sizeof(struct node));
		if(i==0){
	    	head=temp;
			pre=temp;	
		}
		temp->info=i+1;
		temp->next=head;
		pre->next=temp;
		pre=temp;		
	}
	return head;	
}
void yuesefuhuan(struct node*head){
	struct node*p;
	p=head;
	int i=1;//代表头结点
	while(s--) 
	   p=p->next;//将p走s步走向开始报数节点 
	while(p!=NULL){
		if(p==p->next){//表示已经只剩下一个有效数据节点（除头结点外） 
			printf("%d\n",p->info);
			break; 
		}
		if((i+1)%(m-1)==0){//然后输出下一个
		printf("%d,",p->next->info);//这样方便删除
		p->next=p->next->next;//删除下一个节点
		}
		p=p->next;		
		i++;		
	} 
//	p=head->next; 
//	while(p!=head){
//		printf("%d\n",p->info);
//		p=p->next;
//	}
}
int main(){
	while(scanf("%d%d%d",&n,&s,&m)!=EOF){
	if(n==0&&s==0&&m==0)
	   break;
	struct node*head;
	head=creat_xunhuanList();
	yuesefuhuan(head); 	
}
return 0;
}
