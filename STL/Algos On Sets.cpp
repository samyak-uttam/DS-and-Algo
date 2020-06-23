#include<bits/stdc++.h>
using namespace std;

int main()
{
	// set - sorted collections (any container type)


	// set_difference, difference of two sets
	vector<int> v1 = {5, 10, 15, 20, 25};
	vector<int> v2 = {10, 20, 30, 40, 50};
	vector<int> v3(10);
	vector<int>::iterator it, ls;
	cout << "The difference is: ";
	ls = set_difference(begin(v1), end(v1), begin(v2), end(v2), begin(v3));
	for (it = begin(v3); it < ls; it++)
		cout << *it << " ";


	// set_union, union of two sets
	ls = set_union(begin(v1), end(v1), begin(v2), end(v2), begin(v3));
	cout << "\nUnion of v1 and v2: ";
	for (it = begin(v3); it < ls; it++)
		cout << *it << " ";


	// set_intersection, intersection of two sets
	ls = set_intersection(begin(v1), end(v1), begin(v2), end(v2), begin(v3));
	cout << "\nIntersection of v1 and v2: ";
	for (it = begin(v3); it < ls; it++)
		cout << *it << " ";


	// set_symmetric_difference, Union - intersection of two sets
	ls = set_symmetric_difference(begin(v1), end(v1), begin(v2), end(v2), begin(v3));
	cout << "\nSymmetric diff of v1 and v2: ";
	for (it = begin(v3); it < ls; it++)
		cout << *it << " ";


	// includes, whether one array includes another
	v1 = {1, 2, 3, 4, 6};
	v2 = {1, 2, 4};
	if (includes(begin(v1), end(v1), begin(v2), end(v2)))
		cout << "\nv1 contains v2";
	else
		cout << "\nv1 doesn't contains v2";


	// merge(), merges two sets
	v1 = { 1, 2, 3, 4, 6 };
	v2 = { 1, 2, 5, 6, 7 };
	merge(begin(v1), end(v1), begin(v2), end(v2), begin(v3));
	cout << "\nMerged array is: ";
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";

	return 0;
}