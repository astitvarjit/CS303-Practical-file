#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void insertFirst()
{
	int val;
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("OVERFLOW\n\n");
	}
	else
	{
		printf("Enter value : ");
		scanf("%d",&val);
		new->data=val;
		new->next=start;
		start=new;
		printf("Insertion successful\n\n");
	}
};
void display()
{
	struct node *temp;
	temp=start;
	if(temp==NULL)
	{
		printf("UNDERFLOW\n\n");
	}
	else
	{
		printf("\nSTART -> ");
		while(temp->next!=NULL)
		{
			printf("%d -> ",temp->data);
			temp=temp->next;
		}
		printf("%d -> ",temp->data);
		printf("NULL\n\n");
	}
};
void insertLast()
{
	int val;
	struct node *new,*temp;
	new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("OVERFLOW\n\n");
	}
	else
	{
		printf("Enter value : ");
		scanf("%d",&val);
		new->data=val;
		new->next=NULL;
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new;
	}
};
int length()
{
	int count=1;
	struct node *temp;
	temp=start;
	if (temp==NULL)
		return 0;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
};

void insertLoc()
{
	int val,loc,l,count;
	struct node *new,*temp;
	printf("Enter location : ");
	scanf("%d",&loc);
	l=length();
	if(loc>l || loc<=0)
	{
		printf("Invalid Location\n\n");
	}
	else
	{
		new=(struct node*)malloc(sizeof(struct node));
		if(new==NULL)
		{
			printf("OVERFLOW\n\n");
		}
		else
		{
			printf("Enter value : ");
			scanf("%d",&val);
			new->data=val;
			temp=start;
			count=1;
			while(count<loc)
			{
				temp=temp->next;
				count++;
			}
			new->next=temp->next;
			temp->next=new;
			printf("Insertion Successful\n\n");
		}
	}
};

void deleteFirst()
{
	if (start==NULL)
	{
		printf("UNDERFLOW...\n\n");
	}
	else
	{
		int val=start->data;
		struct node *temp;
		temp=start;
		start=start->next;
		free(temp);
		printf("Deletion of %d successful\n\n",val);
	}
};
void deleteLast()
{
	if (start==NULL)
	{
		printf("UNDERFLOW...\n\n");
	}
	else
	{
		int val;
		struct node *temp,*prev;
		temp=start;
		prev=temp;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		val=temp->data;
		prev->next=NULL;
		free(temp);
		printf("Deletion of %d successful\n\n",val);
	}
};
void deleteGiven()
{
	if (start==NULL)
	{
		printf("UNDERFLOW...\n\n");
	}
	else
	{
		int val;
		struct node *temp,*prev;
		temp=start;
		prev=temp;
		printf("Enter value of node to delete : ");
		scanf("%d",&val);
		while(temp->data!=val || temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp->data!=val)
		{
			printf("Node with given value not found...\n\n");
		}
		else
		{
			prev->next=temp->next;
			free(temp);
			printf("Deletion of %d successful\n\n",val);
		}
	}
};
void find()
{
	if (start==NULL)
	{
		printf("UNDERFLOW...\n\n");
	}
	else
	{
		int val,count;
		struct node *temp;
		temp=start;
		printf("Enter value of node to find : ");
		scanf("%d",&val);
		count=0;
		while(temp->data!=val || temp->next!=NULL)
		{
			temp=temp->next;
			count++;
		}
		if(temp->data!=val)
		{
			printf("Node with given value not found...\n\n");
		}
		else
		{
			count++;
			printf("Node with given value found at location %d...\n\n",count);
		}
	}
};
int main()
{
	int choice;
	while(choice!=0)
	{
		printf("1. Insert at Start\n");
		printf("2. Insert at End\n");
		printf("3. Insert at Location\n");
		printf("4. Delete at Start\n");
		printf("5. Delete at End\n");
		printf("6. Delete Given Val\n");
		printf("7. Find\n");
		printf("8. Length \n");
		printf("9. Display\n");
		printf("0. Exit\n");
		printf("Enter choice (0-9) : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			insertFirst();
			break;
			case 2:
			insertLast();
			break;
			case 3:
			insertLoc();
			break;
			case 4:
			deleteFirst();
			break;
			case 5:
			deleteLast();
			break;
			case 6:
			deleteGiven();
			break;
			case 7:
			find();
			break;
			case 8:
			printf("\n\nLength : %d\n\n",length());
			break;
			case 9:
			display();
			break;
			case 0:
			printf("Thanks for using our program...\n\n");
			break;
			default:
			printf("Incorrect  choice\n\n");
			break;
		}
	}
	return 0;}