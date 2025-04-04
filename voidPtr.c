#include <stdio.h>
#include <stdlib.h>

struct node {
void* data;
char ch;
void* next;
};

struct node* newnode;

void createList(struct node** h, void* i, long size, char c){
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=malloc(size);
 newnode->ch=c;
 if(c=='F')
	 *(float*)(newnode->data)=*(float*)i;
 else if(c=='C')
	 *(char*)(newnode->data)=*(char*)i;
 else if(c=='I')
	 *(int*)(newnode->data)=*(int*)i;
((struct node*)(*h))->next=newnode;
*h=newnode;
newnode=NULL;
}

void printList(struct node* n){
    printf("The linked list is:\n");
    while(n!=NULL){
    if((n->ch)=='I')
	    printf("%d\n",*(int*)(n->data));
    if((n->ch)=='F')
            printf("%f\n",*(float*)(n->data));
    if((n->ch)=='C')
            printf("%c\n",*(char*)(n->data));
    n=n->next;
  }
}

void main(){
int n,inp;
float inp1;
char ch,inp2;
printf("Enter the no of elements:\n");
scanf("%d",&n);
struct node* head=(struct node*)malloc(sizeof(struct node));
struct node* temp;
printf("Enter the type of element 1:(I-integer, F-float, C-character)\n");
scanf(" %c",&ch);
printf("Enter the data for element 1:\n");
if(ch=='I'){
	head->data=malloc(sizeof(int));
	scanf(" %d",&inp);
        *(int*)(head->data)=inp;
}
if(ch=='F'){
	head->data=malloc(sizeof(float));
        scanf(" %f",&inp1);
	*(float*)(head->data)=inp1;
}
if(ch=='C'){
        head->data=malloc(sizeof(char));
	scanf(" %c",&inp2);
	*(char*)(head->data)=inp2;
}
head->ch=ch;
head->next=NULL;
temp=head;
for(int i=0;i<n-1;i++){
printf("Enter the type of element %d:\n",(i+2));
scanf(" %c",&ch);
printf("Enter the data for element %d:\n",(i+2));
if(ch=='I'){
  scanf(" %d",&inp);
  createList(&temp,&inp,sizeof(int),ch);
 }
if(ch=='F'){
  scanf(" %f",&inp1);
    createList(&temp,&inp1,sizeof(float),ch);
     }
if(ch=='C'){
  scanf(" %c",&inp2);
    createList(&temp,&inp2,sizeof(char),ch);
  }
}
printList(head);
}
