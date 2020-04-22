#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> vec, int n)
{
	for (int i = 0; i < n; i++)
		cout << vec[i] << " ";
	cout << "\n";
}

bool comp(int a, int b)
{
	return (a > b);
}

int main()
{
	// sort
	vector<int> vec = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
	int n = vec.size();
	// in ascending order
	sort(begin(vec), end(vec));
	cout << "Sorting in ascending order: ";
	printVec(vec, n);
	// in descending order
	// sort(begin(vec), end(vec), greater<int>());
	sort(begin(vec), end(vec), comp);
	cout << "Sorting in descending order: ";
	printVec(vec, n);


	// partial_sort (considers the whole array while sorting)
	vec = {10, 45, 60, 78, 23, 21, 3};
	n = vec.size();
	cout << "Partial Sorting: ";
	partial_sort(begin(vec), begin(vec) + 3, vec.end());
	printVec(vec, n);


	// nth_element (sort the n-th element)
	vec = { 3, 2, 10, 45, 33, 56, 23, 47 };
	n = vec.size();
	cout << "Sorting the n-th element: ";
	nth_element(begin(vec), begin(vec) + 4, end(vec));
	printVec(vec, n);


	// inplace_merge, merge two sorted arrays into another array
	vector<int> vec1 = {1, 3, 4, 5, 20, 30};
	vector<int> vec2 = {1, 5, 6, 7, 25, 30};
	n = vec.size() + vec2.size();
	vector<int> vec3(n);
	auto it = copy(begin(vec1), end(vec1), begin(vec3));
	copy(begin(vec2), end(vec2), it);
	inplace_merge(begin(vec3), it, end(vec3));
	cout << "Sorted array after merging: ";
	printVec(vec3, n);

	return 0;
}