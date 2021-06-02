#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
	vector<int> cq;
	int k, head = 0, tail = 0, size = 0;
public:
	MyCircularQueue(int k) {
		cq = vector<int>(k);
		this->k = k;
	}

	bool enQueue(int value) {
		if (isFull()) return false;
		tail = tail % k;
		if (size < k)
			cq[tail++] = value;
		size++;
		return true;
	}

	bool deQueue() {
		if (isEmpty()) return false;
		head = (head + 1) % k;
		size--;
		return true;
	}

	int Front() {
		return isEmpty() ? -1 : cq[head];
	}

	int Rear() {
		return isEmpty() ? -1 : cq[tail - 1];
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == k;
	}
};

int main()
{
	MyCircularQueue cq(2);
	cq.enQueue(1);
	cq.enQueue(2);
	cq.deQueue();
	cq.enQueue(3);
	cq.deQueue();
	cq.enQueue(3);
	cq.deQueue();
	cq.enQueue(3);
	cq.deQueue();
	cout << cq.Front();
	return 0;
}