#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
void show(Node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}
void push(Node** headRef, int data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}
Node* MergeList(Node* head1, Node* head2){
	Node* merged = NULL;
	Node** ref = &merged;
	while(head1 && head2){
		if(head1->data<=head2->data){
			*ref = head1;
			head1 = head1->next;
		}
		else{
			*ref = head2;
			head2 = head2->next;
		}
		ref = &((*ref)->next);
	}
	*ref = head1?head1:head2;
	return merged;
}
void SplitList(Node* head, Node** headRef, Node** midRef){
	Node* slow, *fast;
	slow=fast=head;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			slow=slow->next;
			fast = fast->next;
		}
	}
	*headRef = head;
	*midRef = slow->next;
	slow->next = NULL;
}
void MergeSort(Node** headRef){
	Node* head = *headRef;
	Node *a, *b;
	
}
int main(){
	int t, n, val;
	cin>>t;
	while(t--){
		cin>>n;
		Node* head = NULL;
		for(int i=0; i<n; i++){
			cin>>val;
			push(&head, val);
		}
		MergeSort(&head);
		show(head);
	}
	return 0;
}
