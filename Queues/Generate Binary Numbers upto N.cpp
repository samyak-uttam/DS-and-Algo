#include<bits/stdc++.h>
using namespace std;

// Given a number N. Generate all binary numbers with decimal values from 1 to N.

// naive approach, O(nlog n)
vector<string> generate(int N) {
	vector<string> res;
	for (int i = 1; i <= N; i++) {
		int x = i;
		string cur;
		while (x) {
			cur += ((x & 1) + '0');
			x /= 2;
		}
		reverse(cur.begin(), cur.end());
		res.push_back(cur);
	}
	return res;
}

// Efficient approach, O(n)
vector<string> generateEff(int N) {
	vector<string> res;
	queue<string> q;
	q.push("1");
	while (N--) {
		string s1 = q.front();
		q.pop();
		res.push_back(s1);

		string s2 = s1;

		q.push(s1.append("0"));
		q.push(s2.append("1"));
	}
	return res;
}

int main() {
	int N = 10;
	cout << "Binary numbers upto " << N << " are: ";

	vector<string> res = generateEff(N);
	for (int i = 0; i < N; i++)
		cout << res[i] << " ";
	return 0;
}