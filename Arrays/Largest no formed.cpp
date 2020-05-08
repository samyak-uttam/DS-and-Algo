#include<bits/stdc++.h>
using namespace std;

// find the largest number formed from an array
bool compare(string a, string b)
{
	string s1 = a.append(b);
	string s2 = b.append(a);
	return s1.compare(s2) > 0 ? 1 : 0;
}

void largestNo(int arr[], int n)
{
	vector<string> vec(n);
	for (int i = 0; i < n; i++)
		vec[i] = to_string(arr[i]);
	sort(begin(vec), end(vec), compare);
	for (int i = 0; i < n; i++)
		cout << vec[i];
}

int main()
{
	int arr[] = {3, 30, 34, 5, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	largestNo(arr, n);
	return 0;
}