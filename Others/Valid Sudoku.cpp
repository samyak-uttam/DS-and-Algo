#include<bits/stdc++.h>
using namespace std;
#define n 9

bool validInRow(char arr[][9], int r)
{
	unordered_set<char> s;
	for (int i = 0; i < n; i++)
	{
		char cur = arr[r][i];
		if (cur == '.')
			continue;
		if (s.find(cur) != s.end())
			return false;
		s.insert(cur);
	}
	return true;
}

bool validInCol(char arr[][9], int c)
{
	unordered_set<char> s;
	for (int i = 0; i < n; i++)
	{
		char cur = arr[i][c];
		if (cur == '.')
			continue;
		if (s.find(cur) != s.end())
			return false;
		s.insert(cur);
	}
	return true;
}

bool validInBox(char arr[][9], int r, int c)
{
	unordered_set<char> s;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			char cur = arr[r + i][c + j];
			if (cur == '.')
				continue;
			if (s.find(cur) != s.end())
				return false;
			s.insert(cur);
		}
	}
	return true;
}

bool isValid(char arr[][9], int r, int c)
{
	return validInRow(arr, r) && validInCol(arr, c) &&
	       validInBox(arr, r - r % 3, c - c % 3);
}

bool isValidSudoku(char arr[][9])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!isValid(arr, i, j))
				return false;
		}
	}
	return true;
}

int main()
{
	char board[][9] = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};

	cout << isValidSudoku(board);
	return 0;
}