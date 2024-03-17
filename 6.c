#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define max 5
int front=0,rear=-1, count=0;
char cq[max];
void cqinsert()
{
char ele;
if(count==max)
{
printf("Queue is full\n\n");
return;
}
printf("Enter the element to be inserted\n\n");
scanf("%s",&ele);
rear=(rear+1)%max;
cq[rear]=ele;
count++;
}

void cqdelete()
{
if(count==0)
{
printf("Queue is empty\n\n"); return;
}
printf("Element deleted is = %c \n\n",cq[front]);
front =(front+1)%max;
count--;
}
void cqdisplay()
{
int j=front,i;
if(count==0)
{
printf("Queue is empty\n\n"); return;
}
printf("Circular Queue content is \n\n");
for(i=1;i<=count;i++)
{
printf("%c\t",cq[j]);
j=(j+1)%max;
} 
printf("\n\n");
}
void main()
{
int ch;
do
{
printf("1:insert\t 2:delete\t 3:display\t 4:exit\n\n");
printf("Enter your choice\n\n");
scanf("%d",&ch);
switch(ch)

{
 case 1: cqinsert();
 break;
 case 2: cqdelete();
 break;
 case 3: cqdisplay();
 break;
 case 4: exit(0);
 default: printf("Invalid choice\n\n"); break;
}
 }while(1);
}
