#include<bits/stdc++.h>
using namespace std;

// Given length and sum of digits, find the max and min no posssible
// without leading zeros
void maxMin(int m, int s)
{
	if (s == 0 && m == 1)
	{
		cout << "0 0";
		return;
	}
	if (s > 9 * m || s == 0)
	{
		cout << "-1 -1";
		return;
	}
	string maxi = "";
	for (int i = 0; i < m; i++)
	{
		int d = min(9, s);
		maxi += '0' + d;
		s -= d;
	}
	string mini = maxi;
	reverse(begin(mini), end(mini));
	int i = 0;
	while (mini[i] == '0')
		i++;
	mini[0]++;
	mini[i]--;
	cout << mini << " " << maxi;
}

int main()
{
	int m = 2, s = 15;
	maxMin(m, s);
	return 0;
}