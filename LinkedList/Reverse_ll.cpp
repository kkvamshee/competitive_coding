#include<iostream>
struct Node{
	int data;
	Node* next;
};
void Insert(Node** pointerToHead, int x){
	Node* temp = new Node;
	temp->data = x;
	temp->next = *pointerToHead;
	*pointerToHead = temp;
}
void Print(Node* head){
	while(head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void Reverse(Node** pointerToHead){
	Node* current = *pointerToHead;
	Node* before = NULL;
	while(current!=NULL){
		Node* after = current->next;
		current->next = before;
		before = current;
		current = after;
	}
	*pointerToHead = before;	
}

int main(){
	Node* head = NULL;
	int n,x;
	printf("ENter size of the list \n");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &x);
		Insert(&head, x);
	}
	printf("Your list is \n");
	Print(head);
	printf("reversed list is \n");
	Reverse(&head);
	Print(head);
	
	return 0;
}
