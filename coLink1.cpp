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
		pNode head,temp,pre,p;//ͷ����������ݵ�ָ�루����Ϊ����ͷ����ָ�룩 
	           //head:ָ���һ���ڵ㣬temp:����ÿ�ο��ٿռ�,pre:���ڱ����һ���ڵ㣨�仯�ģ�
			   //pre:����������һ�Σ�pre->next=temp; ���¿��ٵĿռ�=��һ���ڵ��nextָ�� 
	head=NULL;
	temp=NULL;
	pre=NULL;//��ʼ��ָ��ָ�� 
	p=NULL;//pָ��������� 
//	printf("��������ڵ��Ӧ��ֵ��\n");
	head=(pNode)malloc(sizeof(struct node));//����Ϊhead����һ���ռ伴ʹ����Ϊ�գ�ͷ���Ҳ��Ϊ�� 
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
	pNode head1,head2,temp,pre,p1,p2;//ͷ����������ݵ�ָ�루����Ϊ����ͷ����ָ�룩 
	           //head:ָ���һ���ڵ㣬temp:����ÿ�ο��ٿռ�,pre:���ڱ����һ���ڵ㣨�仯�ģ�
			   //pre:����������һ�Σ�pre->next=temp; ���¿��ٵĿռ�=��һ���ڵ��nextָ�� 
//	printf("��������1�Ľڵ������"); 
	scanf("%d",&n1);//n���ڵ� 
	head1=createLink(n1);
//	printf("��������2�Ľڵ������");
	scanf("%d",&n2);//n���ڵ� 
	head2=createLink(n2);
	p1=head1->next; 
	//printf("����1���������£�\n");
	while(p1->next!=NULL){
		//printf("%d\n",p1->info);
		p1=p1->next;
	}
	p1->next=head2->next;	
	p2=head1->next;
	//printf("�ϲ�����2���������£�\n");
	while(p2!=NULL){
		printf("%d ",p2->info);
		p2=p2->next;
	}
	return 0;
}
