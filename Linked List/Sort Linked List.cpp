#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};


// Selection Sort, O(n^2)
Node* selectionSort(Node* head) {
	for (auto p = head; p; p = p->next) {
		Node* mi = p;
		for (auto q = p->next; q; q = q->next) {
			if (q->data < mi->data)
				mi = q;
		}
		swap(mi->data, p->data);
	}
	return head;
}


// insertion sort, O(n^2)
Node* insertionSort(Node* head) {
	Node* dummy = new Node(0);
	Node* cur = head, *pre = dummy;

	while (cur != NULL) {
		Node* next = cur->next;
		while (pre->next && pre->next->data < cur->data) {
			pre = pre->next;
		}
		cur->next = pre->next;
		pre->next = cur;
		cur = next;
		pre = dummy;
	}
	return dummy->next;
}


// merge sort, O(nlog n)
Node* merge(Node* l, Node* r) {
	Node* dummy = new Node(0), *prev = dummy;
	while (l && r) {
		if (l->data < r->data) {
			prev->next = l;
			l = l->next;
		}
		else {
			prev->next = r;
			r = r->next;
		}
		prev = prev->next;
	}
	prev->next = l ? l : r;
	return dummy->next;
}

Node* mergeSort(Node* head) {
	if (head == NULL || head->next == NULL)
		return head;
	Node* slow = head, *fast = head->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	Node* r = mergeSort(slow->next);
	slow->next = NULL;
	Node* l = mergeSort(head);
	return merge(l, r);
}

void printList(Node* head) {
	for (Node* p = head; p; p = p->next)
		cout << p->data << " ";
}

int main() {
	Node* head = new Node(4);
	head->next = new Node(2);
	head->next->next = new Node(1);
	head->next->next->next = new Node(3);

	cout << "List before sorting: ";
	printList(head);

	head = mergeSort(head);

	cout << "\nList after sorting: ";
	printList(head);
	return 0;
}