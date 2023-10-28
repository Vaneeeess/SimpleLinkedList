#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
	int data;
	struct node *next;
}list;


list *createNode(int data)
{
	list *newNode = (list*)malloc(sizeof(list));
	
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}
void printlist(list *head)
{
	list *curr = head;
	while(curr != NULL)
	{
		printf("%d\t", curr->data);
		curr = curr->next;
	}
}
int search(list *head, int data)
{
	list *curr = head;
	int found = 0;
	int foundya = 0;
	while(curr != NULL)
	{
		if(curr->data == data)
		{
			printf("%d is found! at position %d\n", data, found);
			foundya = 1;
		}
		curr = curr->next;
		found++;
	}
	if(foundya == 0)
	{
		printf("%d is not found!", data);
	}
}

int count(list *head)
{
	int count;
	while(head != NULL)
	{
		head = head->next;
		count++;
	}
	return count;
}

float average(list *head)
{
	float avg;
	int sum = 0;
	int count = 0;
	
	while(head != NULL)
	{
		sum+=head->data;
		head = head->next;
		count++;
	}
	
	avg = (float) sum / count;
	
	return avg;
}

int sum (list *head)
{
	int sum = 0;
	while(head != NULL)
	{
		sum+=head->data;
		head = head->next;
	}
	return sum;
}
int main()
{
	
	list *head = NULL;
	
	int node;
	char choice;
	do{
		printf("Enter data you want to add to the list: ");
		scanf("%d", &node);
		list *newNode = createNode(node);
		
		if(head == NULL)
		{
			head = newNode;
		}
		else 
		{
			list *temp = head;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
		printf("Do you want to add another data?: ");
		scanf(" %c", &choice);
	}while(choice == 'y' || choice == 'Y');
	
	system("cls");
	printf("Just only for 3 choice....\n");
	
	int lol;
	do
	{
		printf("\n1 - Search you want\n");
		printf("\n2 - Count\n");
		printf("\n3 - Average\n");
		printf("\n4 - Sum\n");
		printf("5 - Exit the program\n");
		printf("\nEnter your choice: ");
		scanf("%d", &lol);
		
		switch(lol)
		{
			case 1: {
				int num;
				printf("\nEnter the you want to search: ");
				scanf("%d", &num);
				search(head, num);
				break;
			}
			case 2: {
				printf("Total nodes in the list is: %d", count(head));
				break;
			}
			case 3: {
				printf("Average list is: %.2f", average(head));
				break;
			}
			case 4: {
				printf("Sum of list is: %d", sum(head));
				break;
			}
			case 5: {
				printf("Exit the Program...\n");
				break;
			}
			default:
				printf("Wrong Choice!");
		}
	}while(lol != 5);
}
