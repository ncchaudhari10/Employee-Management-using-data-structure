#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node {

char ename[20];
int eid;
double data;
struct node *link;

};
struct node *root=NULL;
void insert_end()
{
    struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the details\nenter name:  ");
scanf("%s",temp->ename);
printf("\n enter id :");scanf("%d",&temp->eid);
printf("\n enter salary :");
scanf("%d",&temp->data);
temp->link=NULL;
  if(root==NULL)
  root = temp;
  else
  {
    struct node *p;
    p=root;
    while(p->link!= NULL){
	p=p->link;

    }
    p->link=temp;
  }
}
void display(){
struct node *temp;
temp=root;
printf("displaying the elements\n");
printf("\nID \tNAME \tSALARY\n");
while(temp!=NULL){

    printf("%d\t%s\t%d\n",temp->eid,temp->ename,temp->data);
    temp=temp->link;
}

}
void addafter()
{
struct node *temp,*p;
int loc,i=1;
printf("enter the location\n");
scanf("%d",&loc);
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data\n");
scanf("%d",&temp->data);
temp->link=NULL;
p=root;
while(i<loc){
p=p->link;
i++;

}
temp->link=p->link;
p->link=temp;
}
void insert_beg()
{
struct node *temp,*p;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data\n");
scanf("%d",&temp->data);
temp->link=NULL;
  p=root;
  temp->link=p;
  root=temp;
}
int length(){
struct node *temp,*p;
p=root;
int i = 0;
while(p!=NULL){
 p=p->link;
 i++;
}
 return i;
}
 void delete_at()
 {int len=length();
 int loc;
 int i=1;
 printf("currently list containing %d amounts of nodes\n",len);
 printf("enter location, to delete that node\n");
 scanf("%d",&loc);
 struct node *temp;
 if(loc==1){
  temp=root;
  root=temp->link;
  temp->link=NULL;
  free(temp);
 } else
 {struct node *p,*q;
 p=root;
 while(i<loc-1)
 {
 p=p->link;
 i++;
 }q=p->link;
 p->link=q->link;
 q->link=NULL;
 free(q);


 }


 }



void main(){
    clrscr();
    int choice;
    int i,j;
     do{
    printf("**********MENU**********\n");
    printf("1. Add employee\n2. Display employee \n3. exit\n ");
    printf("************************");
    printf("\n enter your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
	case 1:
	printf("\n no. of employees");
	scanf("%d",&i);
	for(j=0;j<i;j++){
	    insert_end();
	}
	 break;
	 case 2:   clrscr();
	 display(); break;
	case 3:
	break;
    }

    }while(choice!=3);
   
}

  
