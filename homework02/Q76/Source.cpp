#include<iostream>
#include<string>

using namespace std;

int main(){
	int res = 0;
	string s, t;
	int carry = 0;
	int store[1000];
	int c = 0;
	getline(cin, s);
	getline(cin, t);
	int a = s.length() - 6, b = t.length() - 6;
	while (a >= 0 && b >= 0){
		res = s.at(a) - 48 + t.at(b) - 48 + carry;
		if (res >= 10){
			carry = 1;
			store[c] = res - 10;
		}
		else{
			carry = 0;
			store[c] = res;
		}
		a = a - 2;
		b = b - 2;
		c++;
	}
	while (a >= 0){
		store[c] = s.at(a) - 48 + carry;
		if (store[c] >= 10){
			store[c] = store[c] - 10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		a = a - 2;
		c++;
	}
	while (b >= 0){
		store[c] = t.at(b) - 48 + carry;
		if (store[c] >= 10){
			store[c] = store[c] - 10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		b = b - 2;
		c++;
	}

	if (a < 0 && b < 0 && carry == 1){
		store[c] = 1;
		c++;
	}

	while (store[c - 1] == 0){
		c--;
	}
	for (int i = c - 1; i >= 0; i--){
		cout << store[i] << ">";
	}
	cout << "null";
}