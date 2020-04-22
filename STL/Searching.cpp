#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> vec = {10, 15, 20, 25, 30, 30, 30, 35};

	// FOR SORTED ARRAYS
	// binary_search
	if (binary_search(begin(vec), end(vec), 15))
		cout << "15 exists.";
	else
		cout << "15 doesn't exist.";

	// lower_bound, returns the position of first occurence of num
	// or the positon of next higher no than num if it doesn't exist
	int index = lower_bound(begin(vec), end(vec), 20) - begin(vec);
	cout << "\nLower bound of 20 is: " << index;


	// upper_bound, returns position of next higher no than num or
	// first position of next higher number than last occurrence of num
	// if have multiple occurences or position of next higher number than num
	// if it doesn't contain it
	index = upper_bound(begin(vec), end(vec), 20) - begin(vec);
	cout << "\nUpper bound of 20 is: " << index;


	// equal_range returns the  initial and final bound of
	// a sub-range within a given range [first, last)
	// that has all the elements equivalent to a given value
	auto ip = equal_range(begin(vec), end(vec), 30);
	cout << "30 is present in the index "
	     << (ip.first - begin(vec)) << " till "
	     << (ip.second - begin(vec));


	// FOR UNSORTED ARRAYS
	// find, returns position of first occurence of num in [first, last)
	index = find(begin(vec), end(vec), 35) - begin(vec);
	cout << "\nIndex of 20 is: " << index;


	// adjacent_find, returns position of first element of two
	// consecutive same elemnts
	vec = {10, 13, 16, 16, 18};
	index = adjacent_find(begin(vec), end(vec)) - begin(vec);
	cout << "\nIndex of adjacent elemnts is: " << index;


	// max_element, return the position of largest value in the range [first, last)
	cout << "\nMaximum element is: " << *max_element(begin(vec), end(vec));


	// min_element, return the position of smallest value in the range [first, last)
	cout << "\nMinimum element is: " << *min_element(begin(vec), end(vec));


	// minmax, returns both min and max
	pair<int, int> mnmx = minmax({53, 23, 1, 96});
	cout << "\nMin is: " << mnmx.first;
	cout << "\nMax is: " << mnmx.second;


	// minmax_element, reutrns position of both min and max
	auto mima = minmax_element(begin(vec), end(vec));
	cout << "\nPosition of Min is: " << mima.first - begin(vec);
	cout << "\nPosition of Max is: " << mima.second - begin(vec);


	// search, searches for the presence of a subsequence
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
	vector<int> v2 = {3, 4, 5};
	index = search(begin(v1), end(v1), begin(v2), end(v2)) - begin(v1);
	if (index != v1.size())
		cout << "\nv2 is present in v1";
	else
		cout << "\nv2 is not present in v1";


	// find_end, just like search but it searches from the end
	v1 = {1, 3, 10, 3, 10, 1, 3, 3, 10, 7, 8, 1, 3, 10};
	v2 = {1, 3, 10};
	index = find_end(begin(v1), end(v1), begin(v2), end(v2)) - begin(v1);
	if (index != v1.size())
		cout << "\nv2 is present in v1";
	else
		cout << "\nv2 is not present in v1";

	return 0;
}