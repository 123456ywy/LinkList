#include<stdio.h> 
#include<stdlib.h>
//����ṹ��
typedef struct node *pnode; 
typedef struct node *plinkList;
struct node{
	int info;
   pnode next;	
};
plinkList  reverse(plinkList head){//�����ú���������������ͷָ����� 
plinkList p,q,temp; //p����ѭ���ƶ��ĵ㣬
                    //temp������ʱ����p->next��ָ��
					//q����ָ�򽻻����Ӻ�� ���һ���ڵ�
					 //ָ�룬�����¶Ͽ����pֱ��������q���� 
 p=head->next;//��ͷ����ָ�룬��ȥ��ͷ��㿪ʼѭ�� 
 q=NULL;
 head->next=NULL;//�� head->nextָ��Ϊ�գ����ڽ����ú�������ٴ���ͷ������� 
while(p){
	temp=p->next;//temp������ʱ����p->next��ָ��
	p->next=q;//����p��q 
	q=p;//q��ǰ�ƶ��������� 
	p=temp; //pָ������ƶ�ָ��	�������� 
	//����ѭ����q��Զָ���һ���ڵ�,(����ʱ�ڵ�������Ѿ�������) 
}	
 head->next=q;//�����ú�������ٴ���ͷ�������
 return head;		
}



int main(){
		int n,x; 
plinkList head,temp,pre,p,pNew;//ͷ����������ݵ�ָ�루����Ϊ����ͷ����ָ�룩 
	           //head:ָ���һ���ڵ㣬temp:����ÿ�ο��ٿռ�,pre:���ڱ����һ���ڵ㣨�仯�ģ�
			   //pre:����������һ�Σ�pre->next=temp; ���¿��ٵĿռ�=��һ���ڵ��nextָ�� 
	head=NULL;
	temp=NULL;
	pre=NULL;//��ʼ��ָ��ָ�� 
	p=NULL;//pָ��������� 
	printf("������ڵ�ĸ���:");
	scanf("%d",&n);//n���ڵ� 
	head=(struct node *)malloc(sizeof(struct node));//����Ϊhead����һ���ռ伴ʹ����Ϊ�գ�ͷ���Ҳ��Ϊ�� 
	pre=head;
	for(int i=0;i<n;i++){
		printf("��%d���ڵ��ֵ",i+1);
		scanf("%d",&x);
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=x;
		temp->next=NULL;
		pre->next=temp;
		pre=temp;		
	}
	p=head->next; 
	printf("��ʼ�������������Ϊ��\n");
	while(p!=NULL){
		printf("%d\n",p->info);
		p=p->next;
	}
plinkList head1=reverse(head);
	      pNew=head1->next;
	printf("���ú��������������Ϊ��\n");
	while(pNew!=NULL){
		printf("%d\n",pNew->info);
		pNew=pNew->next;
	}
	
	return 0;
}
