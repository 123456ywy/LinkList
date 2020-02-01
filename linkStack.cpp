#include<stdio.h>
#include<stdlib.h>
typedef struct node *pNode;
struct node {
	int info;
	pNode link;
}; 
struct linkSatck{
	pNode top;
};
typedef struct linkSatck *plinkStack;
plinkStack createEmptStack(void){
	plinkStack plstack;
	plstack=(plinkStack)malloc(sizeof(struct node));
	if(plstack!=NULL)
	   plstack->top=NULL;
	else
	  printf("¿ª±Ù¿Õ¼äÊ§°Ü");
	return plstack; 
}


void push(plinkStack plstack,int x){
	pNode p;
	p=(pNode)malloc(sizeof(struct node));
	if(p==NULL)
	   printf("¿ª±Ù¿Õ¼äÊ§°Ü");
	else{	
		p->info=x;
		p->link=plstack->top;
		plstack->top=p;
	} 
}
int isEmptyStack(plinkStack plstack){
	return (plstack->top==NULL);
}
void pop(plinkStack plstack){
	pNode p;
    if(isEmptyStack(plstack))
	  printf("Õ»Îª¿Õ");
	else{
	  p=plstack->top;
	  plstack->top=plstack->top->link;
	  free(p);		
	}	
}

int top(plinkStack plstack){
	if(plstack->top==NULL)
	   printf("Õ»Îª¿Õ");
	else
	return (plstack->top->info);	
}
 void printf(plinkStack pStack){
 	while(pStack->top!=NULL){
	 	int num=top(pStack);
	 	printf("%d",num);
	    pop(pStack);	
	 }
 }
int main() {
	int j,n;
	plinkStack pStack=createEmptStack(); 
	scanf("%d",&n);
    if(n==0)
       printf("%d",n);
    else{
	     j=n;
	 for(int i=0;j>0;i++){
	   	 push(pStack,j%2);	
	   	  j=j/2;
	 }
	 printf(pStack);
	 }
	return 0;
}
