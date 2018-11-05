#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};

Node* GetNewNode(int x){
	Node* newNode = new Node;
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = x;
	return newNode;
}

void InsertAtHead(Node** pointerToHead, int x){
	Node* temp = GetNewNode(x);
	if(*pointerToHead == NULL){
		*pointerToHead = temp;
		return;
	}
	(**pointerToHead).prev = temp;
	temp->next = *pointerToHead;
	*pointerToHead = temp;
}

void InsertAtEnd(Node** pointerToHead, int x){
	Node* temp = GetNewNode(x);
	if(*pointerToHead == NULL){
		*pointerToHead = temp;
		return;
	}
	Node* temp1 = *pointerToHead;
	while(temp1->next!=NULL){
		temp1 = temp1->next;
	}
	temp1->next = temp;
	temp->prev = temp1;
}

void PrintBothWays(Node* head){
	printf("Input array is : ");
	while(head->next!=NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("%d\n", head->data);//printing the last element of the list
	//currently the local variable head points towards last node of the linked list.
	printf("Reversed list is : ");
	while(head->prev!=NULL){
		printf("%d ", head->data);
		head = head->prev;
	}
	printf("%d\n", head->data);
}
int main(){
	int n, x;
	printf("Enter size of the array\n");
	scanf("%d", &n);
	Node* head = NULL;
	for(int i=0; i<n; i++){
		scanf("%d", &x);
		if(x%2 == 0) InsertAtHead(&head, x);
		else InsertAtEnd(&head, x);
	}
	PrintBothWays(head);
	return 0;
}
