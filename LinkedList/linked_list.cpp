#include <iostream>

struct Node{
	int data;
	Node* next;
};

void Insert(Node** pointerToHead, int x)
{
	Node* temp = new Node;
	(*temp).data = x;
	(*temp).next = *pointerToHead;
	*pointerToHead=temp;
}

void Print(Node* head)
{
	while(head!=NULL)
	{
		printf("%d ", head->data);
		//printf("%d\n", temp->next);
		head = head->next;
	}
	printf("\n");
}

void Delete(Node** pointerToHead, int n){
	if(n==0){
		*pointerToHead = (**pointerToHead).next;
		delete *pointerToHead;
		return;
	}
	Node* temp = *pointerToHead;
	for(int i=0; i<n-1; i++){
		temp = (*temp).next;
	}
	temp->next = (*((*temp).next)).next;
	delete temp->next;
}


int main()
{
	Node* head = NULL;
	int n, idx;
	printf("Enter the size of list \n");
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int x;
		printf("Enter the number \n");
		scanf("%d", &x);
		Insert(&head, x);
		Print(head);
	}
	
	for(int i=0; i<3; i++){
		printf("Enter the index you want to delete \n");
		std::cin>>idx;
		Delete(&head, idx);
		Print(head);
	}
	
	return 0;
}
