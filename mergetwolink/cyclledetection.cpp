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
		insertAtTail(head, d);
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


bool detectCycle(Node *head){
	Node * slow = head;
	Node * fast = head;
	while(fast != NULL && fast-> next != NULL){
		fast = fast-> next->next;
		slow = slow-> next;

		if(fast == slow)
			return true;
	}
	return false;
}

void deleteCycle(Node *& head){
	Node * slow = head;
	Node * fast = head;
	while(fast != NULL && fast -> next != NULL){
		fast = fast -> next->next;
		slow = slow-> next;
		if(fast == slow)
			break;
	}
	slow = head;
	while(fast->next != slow){
		slow = slow ->next;
		fast = fast -> next;
	}
	fast->next = NULL;
}


int main(){
	//hardcoded linkedlist
return 0;
}