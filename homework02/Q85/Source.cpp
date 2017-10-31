#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int store[100];
	for (int i = 0; i < n; i++){
		cin >> store[i];
	}
	int m;
	cin >> m;
	string t;
	getline(cin, t);
	string s;
	for (int i = 0; i < m; i++){
		getline(cin, s);
		if (s.compare("print") == 0){
			for (int i = 0; i < n; i++){
				cout << store[i] << " ";
			}
			cout << endl;
		}
		if (s.length() > 7 && s.substr(0, 7).compare("replace") == 0){
			int a, b;
			int count = 8;
			while (s.at(count) != ' ')
				count++;
			string temp1 = s.substr(8, count - 8);
			string temp2 = s.substr(count + 1);
			stringstream ss;
			ss << temp1;
			ss >> a;
			stringstream ss2;
			ss2 << temp2;
			ss2 >> b;
			for (int i = 0; i < n; i++){
				if (store[i] == a)
					store[i] = b;
			}
		}
		if (s.length() > 4 && s.substr(0, 4).compare("move") == 0){
			int con = 0;
			string temp = s.substr(10);
			stringstream ss;
			ss << temp;
			ss >> con;
			int tempStore[101];
			int count = 0, tc = 0;
			for (int i = 0; i < n; i++){
				if (store[i] != con){
					tempStore[tc] = store[i];
					tc++;
				}
				else
					count++;
			}
			if (s.substr(5, 4).compare("head") == 0){
				for (int i = 0; i < count; i++){
					store[i] = con;
				}
				for (int i = count; i < n; i++){
					store[i] = tempStore[i-count];
				}
			}
			else{
				for (int i = 0; i < tc; i++){
					store[i] = tempStore[i];
				}
				for (int i = tc; i < n; i++){
					store[i] = con;
				}
			}
		}
		if (s.length() > 9 && s.substr(0, 9).compare("translate") == 0){
			int con;
			string temp = s.substr(15);
			stringstream ss;
			ss << temp;
			ss >> con;
			while (con >= n){
				con = con - n;
			}
			int tempStore1[100], tempStore2[100];
			int tc = 0;
			if (s.substr(10, 4).compare("head") == 0){
				for (int i = 0; i < con; i++){
					tempStore1[i] = store[i];
				}
				for (int i = con; i < n; i++){
					tempStore2[tc] = store[i];
					tc++;
				}
				for (int i = 0; i < n - con; i++){
					store[i] = tempStore2[i];
				}
				for (int i = n - con; i < n; i++){
					store[i] = tempStore1[i - n + con];
				}
			}
			else{
				for (int i = 0; i < n - con; i++){
					tempStore1[i] = store[i];
				}
				for (int i = n - con; i < n; i++){
					tempStore2[tc] = store[i];
					tc++;
				}
				for (int i = 0; i < con; i++){
					store[i] = tempStore2[i];
				}
				for (int i = con; i < n; i++){
					store[i] = tempStore1[i - con];
				}
			}
		}
	}
}