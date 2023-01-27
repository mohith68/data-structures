#include <stdio.h>
#include <conio.h>

typedef struct node{
int info;
struct node *link;
}NODE;
 
NODE* create(NODE *start)
{
 NODE *temp,*t;
 int n,i;
 printf("Enter no of nodes you want to insert:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  temp=(NODE*) malloc(sizeof(NODE));
  printf("Enter data for node %d:",i+1);
  scanf("%d",&temp->info);
  temp->link=NULL;
  if(start==NULL) 
   start=temp;
  else
  {
   t=start;
   while(t->link!=NULL)
    t=t->link;
   t->link=temp;
  }
 }
 return start;
}

void disp(NODE *start)
{
 NODE *t;
 printf("\nElements of the list:");
 for(t=start;t!=NULL;t=t->link)
 {
  if(t->link!=NULL)
   printf("%d->",t->info);
  else
   printf("%d",t->info);
 }
 printf("\n");
}

NODE* append(NODE *start)
{
 NODE *t,*temp;
 temp=(NODE*) malloc(sizeof(NODE));
 printf("Enter data to be appended:");
 scanf("%d",&temp->info);
 for(t=start;t->link!=NULL;t=t->link);
 t->link=temp;
 temp->link=NULL;
 return start;
}

NODE* concat(NODE *s1,NODE *s2)
{
 NODE *t;
 t=s1;
 while(t->link!=NULL)
  t=t->link;
 t->link=s2;
 return s1;
}
 
NODE* fr(NODE *start)
{
 NODE *t;
 t=start;
 while(t!=NULL)
 {
  t=start;
  start=t->link;
  free(t);
 }
 return start;
} 

NODE* rev(NODE *start)
{ 
 NODE *t1,*t2,*s;
 for(t1=start;t1->link!=NULL;t1=t1->link);
 s=t1;
 while(t1!=start)
 { 
  for(t2=start;t2->link!=t1;t2=t2->link);
  t1->link=t2;
  t1=t2;
 }
 t1->link=NULL;
 return s;
}

NODE* dellast(NODE *start)
{
 NODE *t,*t2;
 for(t=start;t->link->link!=NULL;t=t->link);
 t2=t->link;
 free(t2);
 t->link=NULL;
 return start;
}

NODE* deln(NODE *start)
{
 int i=1,n;
 NODE *t,*t2;
 printf("\nEnter pos no of element to be deleted:");
 scanf("%d",&n);
 t=start;
 if(n!=1)
 {
  while(i<n-1)
  {
   t=t->link;
   i++;
  }
  t2=t->link;
  t->link=t2->link;
  free(t2);
 }
 else
 {
  start=t->link;
  free(t);
 }
 return start;
}
NODE* sort(NODE*);

NODE* comb(NODE *s1,NODE *s2)
{
 s1=concat(s1,s2);
 s1=sort(s1);
 return s1;
}
 
NODE* uni(NODE *s1,NODE *s2)
{
 NODE *s3,*t,*t2,*t3,*temp;
 int flag=1;
 s3=(NODE*) malloc(sizeof(NODE));
 s3=NULL;
 t=s1;
 while(t!=NULL)
 {
  temp=(NODE*) malloc(sizeof(NODE));
  temp->info=t->info;
  temp->link=NULL;
  if(s3==NULL)
   s3=temp;
  else
  {
   t2=s3;
   while(t2->link!=NULL)
    t2=t2->link;
   t2->link=temp;
  }
  t=t->link;
 }
 
 t2=s2;
 while(t2!=NULL)
 {
  t=s1;
  flag=1;
  while(t!=NULL)
  {
   if(t->info==t2->info)
   {
    flag=0;
    break;
   }
   t=t->link;
  }
  if(flag==1)
  {
   for(t3=s3;t3->link!=NULL;t3=t3->link);
   temp=(NODE*) malloc(sizeof(NODE));
   temp->info=t2->info;
   t3->link=temp;
   temp->link=NULL;
  }   
  t2=t2->link;
 }
 return s3;
}

NODE* inter(NODE *s1,NODE *s2)
{
 NODE *s3,*t1,*t2,*t3,*temp;
 s3=(NODE*) malloc(sizeof(NODE));
 s3=NULL;
 t1=s1;
 while(t1!=NULL)
 {
  t2=s2;
  while(t2!=NULL)
  {
   if(t1->info==t2->info)
   {
    temp=(NODE*) malloc(sizeof(NODE));
    temp->info=t1->info;
    temp->link=NULL;
    if(s3==NULL)
     s3=temp;
    else
    {
     for(t3=s3;t3->link!=NULL;t3=t3->link);
     t3->link=temp;
    }
    break;
   }
   t2=t2->link;
  }
  t1=t1->link;
 }  
 return s3;
} 

NODE* insertn(NODE *s)
{
 NODE *t,*t2,*temp;
 int n,i=1;
 printf("Enter data:");
 temp=(NODE*) malloc(sizeof(NODE));
 scanf("%d",&temp->info);
 printf("Enter position no at which element has to be inserted:");
 scanf("%d",&n);
 t=s;
 if(n!=1)
 {
  while(i<n-1)
  {
   t=t->link;
   i++;
