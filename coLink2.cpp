#include<stdio.h> 
#include<stdlib.h>
//����ṹ��
typedef struct node *pNode;
struct node{
	int info;
    pNode next;	
};

pNode createLink(int n){
	int x;
	pNode head,temp,pre,p,q;//ͷ����������ݵ�ָ�루����Ϊ����ͷ����ָ�룩 
	           //head:ָ���һ���ڵ㣬temp:����ÿ�ο��ٿռ�,pre:���ڱ����һ���ڵ㣨�仯�ģ�
			   //pre:����������һ�Σ�pre->next=temp; ���¿��ٵĿռ�=��һ���ڵ��nextָ�� 
	head=NULL;
	temp=NULL;
	pre=NULL;//��ʼ��ָ��ָ�� 
	p=NULL;//pָ��������� 
//	printf("��������ڵ��Ӧ��ֵ��\n");
	head=(pNode)malloc(sizeof(struct node));//����Ϊhead����һ���ռ伴ʹ����Ϊ�գ�ͷ���Ҳ��Ϊ�� 
	head->next=NULL;
	pre=head;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		q=head;
		temp=(pNode)malloc(sizeof(struct node));
		temp->info=x;
		while(q->next!=NULL){
			  if(q->next->info>temp->info)//��֤q->nextλ������С�� 
			     break;          //����С�Ķ�����ֵС����ֹͣѭ��������ֵ�嵽q->next֮�� 
			  else
			     q=q->next; 
			
		}
	temp->next=q->next;//ʹ��temp->next������q->next��λ��
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
	pNode head,head1,head2,temp,pre,p1,p2;//ͷ����������ݵ�ָ�루����Ϊ����ͷ����ָ�룩 
	           //head:ָ���һ���ڵ㣬temp:����ÿ�ο��ٿռ�,pre:���ڱ����һ���ڵ㣨�仯�ģ�
			   //pre:����������һ�Σ�pre->next=temp; ���¿��ٵĿռ�=��һ���ڵ��nextָ�� 
	scanf("%d",&n1);//n���ڵ� 
	head1=createLink(n1);
	scanf("%d",&n2);//n���ڵ� 
	head2=createLink(n2);
	head=shunxun(head1,head2);	
	p2=head->next;
	//printf("�ϲ�����2���������£�\n");
	while(p2!=NULL){
		printf("%d ",p2->info);
		p2=p2->next;
	}
	return 0;
}
