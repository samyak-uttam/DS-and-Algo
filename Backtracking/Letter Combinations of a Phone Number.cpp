#include<bits/stdc++.h>
using namespace std;

void letterCombinations(string digits)
{
	map<string, string> mp;
	mp["2"] = "abc";
	mp["3"] = "def";
	mp["4"] = "ghi";
	mp["5"] = "jkl";
	mp["6"] = "mno";
	mp["7"] = "pqrs";
	mp["8"] = "tuv";
	mp["9"] = "wxyz";


}

int main()
{
	string digits = "23";
	letterCombinations(digits);
	return 0;
}