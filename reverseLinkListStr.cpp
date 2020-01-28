#include<stdio.h> 
#include<stdlib.h>
//定义结构体
typedef struct node *pnode; 
typedef struct node *plinkList;
struct node{
	char info;
   pnode next;	
};
plinkList  reverse(plinkList head){
plinkList p,q,temp;                   
 p=head->next;
 q=NULL;
 head->next=NULL; 
while(p){
	temp=p->next;
	p->next=q;
	q=p; 
	p=temp; 
}	
 head->next=q;
 return head;		
}

int main(){
		char str[1000];
plinkList head,temp,pre,p,pNew;
    scanf("%s",str);
	head=(struct node *)malloc(sizeof(struct node));
	pre=head;
	for(int i=0;str[i]!='\0';i++)
    {	
       temp=(struct node *)malloc(sizeof(struct node));
		temp->info=str[i];
		temp->next=NULL;
		pre->next=temp;
		pre=temp;
    
	}
plinkList head1=reverse(head);
	      pNew=head1->next;
	      //printf("倒置后的链表数据依次为：\n");
	      while(pNew!=NULL){
		        printf("%c",pNew->info);
		        pNew=pNew->next;
	      }
	return 0;
}
