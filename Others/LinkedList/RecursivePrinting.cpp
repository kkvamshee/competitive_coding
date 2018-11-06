#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
void Insert(Node** pointerToHead, int value, int pos){
	Node* temp = new Node;
	temp->data = value;
	temp->next = NULL;
	
	if(pos==0){
		temp->next = *pointerToHead;
		*pointerToHead = temp;
	}
	else{
		Node* temp1 = *pointerToHead;
		for(int i=0; i<pos-1; i++){
			temp1 = temp1->next;
		}
		temp->next = temp1->next;
		temp1->next = temp;
	}
}
void Print(Node* head){
	if(head==NULL){
		printf("\n");
		return;
	}
	printf("%d ", head->data);
	Print(head->next);
}
void PrintReverse(Node* head){
	if(head==NULL){
		return;
	}
	PrintReverse(head->next);
	printf("%d ", head->data);
}
int main(){
	int n,x;
	Node* head = NULL;
	printf("Enter size of the list\n");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &x);
		Insert(&head, x, i);
	}
	printf("Your list is : ");
	Print(head);
	printf("Reversed list is : ");
	PrintReverse(head);
	printf("\nProgram Completed.");
	return 0;	
}
