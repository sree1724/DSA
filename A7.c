#include<stdio.h> 
#include<stdlib.h> 

 
struct list 
{ 
 	char usn[15],name[20],programme[30],phno[12]; 
 	int  sem; 
 	struct list *next; 
}; 
typedef struct list node; 
 
node* insertfront(node *first) 
{ 
 	node *temp; 
 	temp=(struct list *)malloc(sizeof(node));  	
 	if(temp!=NULL) 
 	    printf("memory allocated\n"); 
 	printf("1.Enter the USN\n 2.Name\n3.Programme\n4.Sem\n5.Ph.No.\n"); 
 	scanf("%s%s%s%d%s",&temp->usn,&temp->name,&temp->programme,   
          &temp->sem, &temp->phno);  	
    temp->next=NULL;  	
    if(!first) 
 	 	return(temp); 
 	temp->next=first;  	
 	first=temp; 
 	return first; 
} 
node* delfront(node *first) 
{ 
 int i;  node *temp=first; 
 	if(first==NULL) 
 	{ 
 	 	printf("List is empty..can't delete\n"); 
 	 	return first; 
 	} 
 	else 
 	{ 
 	 	printf("The student record deleted is %s \n",temp->name);  	 	
		first=temp->next; 
 	 	free(temp); 
 
 	} 
   return first; 
} 
 
void insertend(node *first) 
{ 
 	node *ptr,*temp; 
 	temp=(struct list *)malloc(sizeof(node)); 
 	printf("Enter the 1.USN\n,2.No.\n"); 
 	scanf("%s%s%s%d%s",&temp->usn,&temp->name,&temp->programme, 
          &temp->sem,&temp->phno);  	
    temp->next=NULL;  	
    ptr=first;  
    while(ptr->next!=NULL) 
 	    ptr=ptr->next; 
     	ptr->next=temp; 
} 
 
node* delend(node *first) 
{ node *last,*ptr; ptr=last=first; 
 	if(first==NULL) 
 	{ 
 	 	printf("List is empty..can't delete\n"); 
 	 	return first; 
 	} 
 	if(first->next==NULL) 
 	{ 
 	      printf("\nThe record deleted is %s \n",first->name); 
 	      free(first); 
 	      return NULL; 
 	} 
 	while(last->next) 
 	{ 
 	      ptr=last; 
 	      last=last->next; 
 	} 
 	printf("\nThe record deleted is %s \n",last->name);  	ptr->next=NULL; 
 	free(last); 
   return first; 
} 
 
void display(node *first) 
{ 
 	int count=0; 
 	node *temp=first; 
 
 	if(first==NULL) 
 	{ 
 	     printf("List is Empty : No records to display.. ! \n"); 
 	     return; 
 	} 
 	while(temp!=NULL) 
 	{ 
     count++; printf("\n%s\n%s\n%s\n%d\n%s\n",temp->usn,temp->name, temp-> programme, temp->sem,temp->phno); 
 	     temp=temp->next; 
 	} 
 	printf("\n Total number of records is = %d\n\n",count); } 
 
void main() 
{     
    int i,n,choice;     
    node *first=NULL; 
    //clrscr(); 
    printf("Singly linked list Implementation .. \n");    
    while(1) 
    { 
       printf("\n 1.Create a List\n 2.Insert front\n 3.Insert end\n\n");        
	   printf("4.Delete at front\n 5.Delete at end\n 6.Display\t 7.Exit \n\n");        
	   printf("Enter your choice\n");        
	   scanf("%d",&choice); 
       switch(choice) 
       { 
 	   case 1:printf("\n Enter the number of students\n"); 
 	 	  scanf("%d",&n);  	 	  for(i=1;i<=n;i++) 
 	 	     first=insertfront(first); 
 	 	  break; 
 	   case 2:first=insertfront(first); 
 	 	  break; 
 	   case 3:insertend(first); 
 	 	  break; 
 	   case 4:first=delfront(first); 
 	 	  break; 
 	   case 5:first=delend(first); 
 	 	  //getch();  	 	  break; 
 	   case 6:display(first);  	  break; 
   case 7:exit(0); 
 	   default: printf("Invalid choice: Kindly give valid choice\n"); 
 	 	  break; 
 	} 
    } 
}