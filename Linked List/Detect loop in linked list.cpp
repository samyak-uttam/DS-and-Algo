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


// Detect if there is a loop in the linked list
// Using hashing
bool detectLoop(Node* head) {
	Node *temp = head;
	unordered_set<Node*> s;
	while (temp != NULL) {
		if (s.find(temp) != s.end())
			return true;
		s.insert(temp);
		temp = temp->next;
	}
	return false;
}

// mark the visited nodes
bool detectLoop2(Node* head) {
	Node *temp = head;
	while (temp != NULL) {
		if (temp->data > 0)
			temp->data *= -1;
		else
			return true;
		temp = temp->next;
	}
	return false;
}

// most efficient approach
// Using floyd's Cycle algorithm
bool detectLoop3(Node* head) {
	Node *fast = head, *slow = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow)
			return true;
	}
	return false;
}



// detect the cycle and return the node where the cycle
// begins, and return null if there is no cycle.
Node* detectCycle(Node* head) {
	Node* slow = head, *fast = head, *entry = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			while (entry != slow) {
				slow = slow->next;
				entry = entry->next;
			}
			return entry;
		}
	}
	return NULL;
}

int main()
{
	Node *head = new Node(3);
	head->next = new Node(2);
	head->next->next = new Node(0);
	head->next->next->next = new Node(-1);

	// create loop
	head->next->next->next->next = head->next;

	cout << detectLoop3(head);

	Node* node = detectCycle(head);
	if (node == NULL)
		cout << "\nNo Loop";
	else
		cout << "\nLoop is present and the starting element is: " << node->data;

	return 0;
}