#include<bits/stdc++.h>
using namespace std;

// Find the next Lexicographical greater word(next permutation of the word)

// using stl function
bool nextPermutation(string &s)
{
	return next_permutation(begin(s), end(s));
}

// without using stl
int search(string s, int l, int r, char key)
{
	int ind = -1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (s[mid] > key)
		{
			l = mid + 1;
			ind = mid;
		}
		else
			r = mid - 1;
	}
	return ind;
}

bool nextPermutation2(string &s)
{
	int l = s.length(), i = l - 2;
	while (i >= 0 && s[i] > s[i + 1])
		i--;
	if (i < 0)
		return false;
	int ind = search(s, i + 1, l - 1, s[i]);
	swap(s[ind], s[i]);
	reverse(s.begin() + i + 1, s.end());
	return true;
}

int main()
{
	string s = "abmha";
	bool ans = nextPermutation2(s);

	if (ans == false)
		cout << "No word possible";
	else
		cout << s;
	return 0;
}