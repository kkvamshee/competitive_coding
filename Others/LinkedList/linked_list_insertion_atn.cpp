#include <iostream>
struct Node{
	int data;
	Node* next;
};

void Print(Node* head){
	while(head!=NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void Insert(Node** pointerToHead, int value, int pos){
	Node* temp = new Node;
	temp->data = value;
	temp->next = NULL;
	
	if(pos==0){
		temp->next = *pointerToHead;
		*pointerToHead = temp;
	}
	else{
		Node* head = *pointerToHead;
		for(int i=0; i<pos-1; i++){
			head = head->next;
		}
		temp->next = (*head).next;
		(*head).next = temp;
	}
}

int main(){
	int n;
	Node* head;
	printf("Enter size of the list \n");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int x, idx;
		scanf("%d %d", &x, &idx);
		Insert(&head, x, idx);
		Print(head);
	}
	
	return 0;
}
