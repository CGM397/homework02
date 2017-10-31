#include<iostream>

using namespace std;
int store[100][100];
int pos = 0, m = 0, n = 0;
void search(int start, int row, int col);
int main(){
	cin >> m >> n;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> store[i][j];
		}
	}
	cin >> pos;
	search(0, m, n);
}

void search(int start, int row, int col){
	for (int j = start; j < col + start; j++){
		if (pos == 0){
			cout << store[start][j];
			return;
		}
		else{
			pos--;
		}
	}

	for (int i = start + 1; i < row + start; i++){
		if (pos == 0){
			cout << store[i][col + start - 1];
			return;
		}
		else{
			pos--;
		}
	}

	for (int j = col + start - 2; j >= start; j--){
		if (pos == 0){
			cout << store[row + start - 1][j];
			return;
		}
		else{
			pos--;
		}
	}

	for (int i = row + start - 2; i >= start + 1; i--){
		if (pos == 0){
			cout << store[i][start];
			return;
		}
		else{
			pos--;
		}
	}
	if (row - 2 < 0 || col - 2 < 0){
		return;
	}
	search(start + 1, row - 2, col - 2);
	return;
}