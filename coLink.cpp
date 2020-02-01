/*�ϲ���������*/
#include <stdio.h>
#include <stdlib.h>
//����struct student����
typedef struct student{
    char num;
    struct student * next;
}LNode,*LinkList;
 
//����create(),ʵ�ִ���һ���������������ͷָ��
LinkList create(void){
    LinkList head;
    LNode *p1,*p2;
    char a;
    head=NULL;
    a=getchar();
    while(a!='\n'){  //���������ֵ���ո�������س�����
        p1=(LNode *)malloc(sizeof(LNode));  //p1Ϊ�½�ָ��
        p1->num=a;  //p1������ֵ
        if(head==NULL){
            head=p1;
        }else{
            p2->next=p1;  //p2ָ������β��
        }
        p2=p1;
        a=getchar();
    }
    p2->next=NULL;  //β����ָ���nextָ���ÿ�
    return head;
}
//����coalition(),ʵ�ֽ���������������ϲ�
LinkList coalition(LinkList L1,LinkList L2){
    LNode * temp;
    if(L1==NULL) 
	   return L2;
    else{
	    if(L2==NULL) 
		   return L1;
       else{
            for(temp=L1;temp->next!=NULL;temp=temp->next); //��������L1,������L1β��
               temp->next=L2;  //��L2���ӵ�L1β��
           }
        return L1;
    }
}
 
int main()
{
    LinkList L1,L2,L3;
    printf("��������������\n");
    printf("��һ�������ǣ�\n");
    L1=create();
    printf("�ڶ��������ǣ�\n");
    L2=create();
    coalition(L1,L2);  //������������
    printf("�ϲ���������ǣ�\n");
    while(L1){
        printf("%c",L1->num);
        L1=L1->next;
    }
    return 0;
}

