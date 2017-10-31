#include<iostream>

using namespace std;

int main(){
	int n;
	int store[100][100];
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			cin >> store[i][j];
		}
	}

	for (int i = 1; i < n; i++){
		store[i][0] += store[i - 1][0];
		store[i][i] += store[i - 1][i - 1];
	}

	for (int i = 2; i < n; i++){
		for (int j = 1; j < i; j++){
			if (store[i - 1][j - 1] < store[i - 1][j])
				store[i][j] += store[i - 1][j - 1];
			else
				store[i][j] += store[i - 1][j];
		}
	}

	int res = 10000;
	for (int i = 0; i < n; i++){
		if (store[n - 1][i] < res)
			res = store[n - 1][i];
	}
	cout << res;
}