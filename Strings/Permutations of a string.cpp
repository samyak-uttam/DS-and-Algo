#include<bits/stdc++.h>
using namespace std;

// Print all permutations of a string
// prints dupicates if there are repeating chars in the string &
// it doesn't print the permutations in lexicographically
void permute(string s, int l, int r)
{
	if (l == r)
	{
		cout << s << " ";
		return;
	}
	for (int i = l; i <= r; i++)
	{
		swap(s[l], s[i]);
		permute(s, l + 1, r);
		swap(s[l], s[i]);
	}
}

// using STL
void permuteSTL(string s)
{
	// for lexicographic order
	sort(begin(s), end(s));
	do
	{
		cout << s << " ";
	} while (next_permutation(begin(s), end(s)));
}

int main()
{
	string s = "ABC";
	int l = s.length();
	permute(s, 0, l - 1);
	cout << "\n";
	permuteSTL(s);
	return 0;
}