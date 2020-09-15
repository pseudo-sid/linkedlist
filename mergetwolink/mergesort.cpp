#include<bits/stdc++.h>
using namespace std;


class Node{
public:
	int data;
	Node* next;
	Node(int d){
		data = d;
		next = NULL;
	}
};

void insertAthead(Node* &head, int data){
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
}
void print(Node* head){
	while(head != NULL){
		cout << head->data <<"->";
		head = head->next;
	}
	cout << endl;
}

void insertInMiddle(Node* &head, int d, int p){
	int i = 1;
	Node* temp = head;
	while(i < p){
		temp = temp->next;
		i++;
	}

	Node* t = new Node(d);
	t->next = temp->next;
	temp->next = t;

}
void insertAtTail(Node* &head, int d){
	if(head == NULL)
	{
		head = new Node(d);
		return;
	}
	Node* tail = head;
	while(tail-> next != NULL)
		tail = tail->next;
	tail->next = new Node(d);
}

void reverselist(Node* &prev, Node * &cur){
	if(prev == NULL || cur == NULL)
		return;
	reverselist(cur, cur->next);
	cur->next = prev;
	return;
}

Node* take_input(){
	int d;	cin >> d;
	Node* head;
	do
		insertAthead(head, d);
		while(cin >> d);
	return head;
}

ostream& operator<<(ostream &os, Node* head){
	print(head);
	return os;
}
istream& operator >> (istream &is, Node* &head){
	head = take_input();
	return is;
}

Node* midpoint(Node* head){
	if(head == NULL || head->next == NULL)
		return head;
	Node* slow = head;
	Node* fast = head->next;


	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

Node *merge(Node * a, Node * b){
	if (a == NULL )
		return  b;
	if(b == NULL)
		return a;
	Node * c;
	if(a->data < b->data){
		c = a;
		c->next = merge(a->next, b);
	}
	else{
		c = b; 
		c->next = merge(a, b->next);
	}
	return c;
}

Node * mergeSort(Node * head){
	if(head == NULL || head->next == NULL)
		return head;
	Node* mid = midpoint(head);
	Node *a = head;
	Node *b = mid->next;
	mid->next = NULL;
	a = mergeSort(a);
	b = mergeSort(b);
	return merge(a,b);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Node* head = take_input();

	cout << mergeSort(head);
	return 0;
}