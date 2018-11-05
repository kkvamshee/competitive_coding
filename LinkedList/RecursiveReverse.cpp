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
void Reverse(Node* p, Node** pointerToHead){
	if(p->next==NULL){
		*pointerToHead = p;
		return;
	}
	Reverse(p->next, pointerToHead);
	p->next->next = p;
	p->next = NULL;	
}
void Print(Node* head){
	while(head!=NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
int main(){
	int n, x;
	Node* head = NULL;
	printf("Enter the size of your list\n");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &x);
		Insert(&head, x, i);
	}
	Print(head);
	Reverse(head, &head);
	Print(head);
	
	return 0;
}
