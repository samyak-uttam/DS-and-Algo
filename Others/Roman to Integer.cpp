#include<bits/stdc++.h>
using namespace std;

// Convert Roman Numbers to integers
/*
Symbol        Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

map<char, int> mp;

void define() {
	mp['I'] = 1;
	mp['V'] = 5;
	mp['X'] = 10;
	mp['L'] = 50;
	mp['C'] = 100;
	mp['D'] = 500;
	mp['M'] = 1000;
}

int romanToInt(string s) {
	int ans = 0, cur;
	for (int i = 0; i < s.length(); i++) {
		if (mp[s[i + 1]] > mp[s[i]])
			cur = mp[s[i + 1]] - mp[s[i]], i++;
		else
			cur = mp[s[i]];
		ans += cur;
	}
	return ans;
}


// Convert integer to Roman number
string intToRoman(int n) {
	vector<string> sym = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	vector<int> nums = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

	string res;
	int i = 12;

	while (n) {
		while (n < nums[i])
			i--;
		n -= nums[i];
		res += sym[i];
	}

	return res;
}

int main() {
	string s = "MCMXCIV";

	define();
	cout << romanToInt(s);
	return 0;
}