#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int value;
	struct Node *next;
};

void insertNode(struct Node **head, int value)
{
	struct Node *previous;
	struct Node *current;
	struct Node *insert;
	
	current = *head;
	previous = NULL;
	
	while(current != NULL && current->value < value)
	{
		previous = current;
		current = current->next;
	} // current find the value being just bigger than value
	
	insert = (struct Node*) malloc(sizeof(struct Node));
	if(insert == NULL)
	{
		exit(1);
	}
	
	insert->value = value;
	insert->next = current;
	
	if(previous == NULL) // empty list
	{
		*head = insert;
	}
	else // not empty
	{
		previous->next = insert;
	}
}

void deleteNode(struct Node **head, int input)
{
	struct Node *previous, *current;
	current = *head;
	previous = NULL;
	
	while(current != NULL && current->value != input)
	{
		previous = current;
		current = current->next;
	}
	if(current == NULL) // empty list or no matching
	{
		printf("No matching node!\n");
		return;
	}
	else
	{
		if(previous == NULL) // current at the 1st node
		{
		*head = current->next;	
		}
		else
		{
			previous->next = current->next;
		}
	}
}

void printNode(struct Node *head)
{
	struct Node *current;
	current = head;
	
	putchar('\n');
	while(current != NULL)
	{
		printf("%d -> ", current->value);
		current = current->next;
	}
	printf("NULL\n\n");
}

int main(void)
{
	struct Node *head = NULL;
	int input;
	
	while(1)
	{
		printf("Input an integer (-1 means finished): ");
		scanf("%d", &input);
		if(input == -1)
		{
			break;
		}
		insertNode(&head, input);
	}
	
	printNode(head);
	
	while(1)
	{
		printf("Delete the values equal to (-1 means finished): ");
		scanf("%d", &input);
		if(input == -1)
		{
			break;
		}
		deleteNode(&head, input);
	}
	 
	printNode(head);
	
	return 0;
}
