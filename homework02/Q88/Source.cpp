#include<iostream>
#include<string>
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	string store[10000];
	for (int i = 0; i < n; i++){
		getline(cin, store[i]);
	}
	string temp;
	for (int m = 0; m < n - 1; m++){
		for (int i = 0; i < n - 1; i++){
			if (store[i].length() > store[i + 1].length()){
				temp = store[i];
				store[i] = store[i + 1];
				store[i + 1] = temp;
			}
			if (store[i].length() == store[i + 1].length()){
				for (int j = 0; j < store[i].length(); j++){
					if (store[i].at(j) <= 'Z'&&store[i + 1].at(j) <= 'Z'&&store[i + 1].at(j) - store[i].at(j) < 0){
						temp = store[i];
						store[i] = store[i + 1];
						store[i + 1] = temp;
						break;
					}
					else if (store[i].at(j) <= 'Z'&&store[i + 1].at(j) <= 'Z'&&store[i + 1].at(j) - store[i].at(j) > 0)
						break;
					else if (store[i].at(j) <= 'Z'&&store[i + 1].at(j) <= 'Z'&&store[i + 1].at(j) - store[i].at(j) == 0)
						continue;
					else if (store[i].at(j) >= 'a'&&store[i + 1].at(j) >= 'a'&&store[i + 1].at(j) - store[i].at(j) < 0){
						temp = store[i];
						store[i] = store[i + 1];
						store[i + 1] = temp;
						break;
					}
					else if (store[i].at(j) >= 'a'&&store[i + 1].at(j) >= 'a'&&store[i + 1].at(j) - store[i].at(j) > 0)
						break;
					else if (store[i].at(j) >= 'a'&&store[i + 1].at(j) >= 'a'&&store[i + 1].at(j) - store[i].at(j) == 0)
						continue;
					else if (store[i].at(j) <= 'Z'&&store[i + 1].at(j) >= 'a'&&store[i + 1].at(j) - store[i].at(j) - 32 <= 0){
						temp = store[i];
						store[i] = store[i + 1];
						store[i + 1] = temp;
						break;
					}
					else if (store[i].at(j) <= 'Z'&&store[i + 1].at(j) >= 'a'&&store[i + 1].at(j) - store[i].at(j) - 32 > 0)
						break;
					else if (store[i].at(j) >= 'a'&&store[i + 1].at(j) <= 'Z'&&store[i + 1].at(j) + 32 - store[i].at(j) < 0){
						temp = store[i];
						store[i] = store[i + 1];
						store[i + 1] = temp;
						break;
					}
					else if (store[i].at(j) >= 'a'&&store[i + 1].at(j) <= 'Z'&&store[i + 1].at(j) + 32 - store[i].at(j) >= 0)
						break;
				}
			}
	    }
	}
	for (int i = 0; i < n - 1; i++){
		cout << store[i];
		cout << endl;
	}
	cout << store[n - 1];
}