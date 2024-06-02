#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node* prev;

	node(int d)
	{
		data = d;
		next = NULL;
		prev = NULL;
	}

	void deleteattail(node*& head, node*& tail)
	{
		node* temp = tail;
		tail = temp->prev;
		tail->next = head;
		head->prev = tail;
		temp->next = NULL;
		temp->prev = NULL;
		delete temp;
	}

	void display(node*& head)
	{
		node* temp = head;

		do {
			cout << temp->data << "->";
			temp = temp->next;
		} while (temp != head);
		cout << "(head)";
	}
};

void main()
{
	node* node1 = new node(1);
	node* node2 = new node(2);
	node* node3 = new node(3);
	node* head = node1;
	node1->next = node2;
	node2->prev = node1;
	node2->next = node3;
	node3->prev = node2;
	node* tail = node3;

	node1->deleteattail(head, tail);
	node1->display(head);
}