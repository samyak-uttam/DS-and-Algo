#include<bits/stdc++.h>
using namespace std;

class String {
	char* str;
	int size;
public:
	String();
	String(char* str);
	String(const String & s);
	void push_back(char c);
	void pop_back();
	int length();
	~String() {
		delete str;
	}
};


int main() {
	return 0;
}