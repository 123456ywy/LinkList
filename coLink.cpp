/*合并两个链表*/
#include <stdio.h>
#include <stdlib.h>
//声明struct student类型
typedef struct student{
    char num;
    struct student * next;
}LNode,*LinkList;
 
//函数create(),实现创建一个链表，返回链表的头指针
LinkList create(void){
    LinkList head;
    LNode *p1,*p2;
    char a;
    head=NULL;
    a=getchar();
    while(a!='\n'){  //输入链表的值，空格隔开，回车结束
        p1=(LNode *)malloc(sizeof(LNode));  //p1为新建指针
        p1->num=a;  //p1数据域赋值
        if(head==NULL){
            head=p1;
        }else{
            p2->next=p1;  //p2指向链表尾部
        }
        p2=p1;
        a=getchar();
    }
    p2->next=NULL;  //尾部的指针的next指针置空
    return head;
}
//函数coalition(),实现将创建的两个链表合并
LinkList coalition(LinkList L1,LinkList L2){
    LNode * temp;
    if(L1==NULL) 
	   return L2;
    else{
	    if(L2==NULL) 
		   return L1;
       else{
            for(temp=L1;temp->next!=NULL;temp=temp->next); //遍历链表L1,并到达L1尾部
               temp->next=L2;  //将L2链接到L1尾部
           }
        return L1;
    }
}
 
int main()
{
    LinkList L1,L2,L3;
    printf("请输入两个链表：\n");
    printf("第一个链表是：\n");
    L1=create();
    printf("第二个链表是：\n");
    L2=create();
    coalition(L1,L2);  //连接两个链表
    printf("合并后的链表是：\n");
    while(L1){
        printf("%c",L1->num);
        L1=L1->next;
    }
    return 0;
}

