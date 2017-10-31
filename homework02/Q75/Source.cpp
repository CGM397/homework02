#include<iostream>
#include<string>
using namespace std;

struct Node{
	string value = "null";
	Node * left = NULL;
	Node * right = NULL;
};

void inOrder(Node root){
	if (root.left != NULL)
		inOrder(*root.left);
		cout << root.value << " ";
	if (root.right != NULL)
		inOrder(*root.right);
}

int main(){
	Node * store = new Node[100];
	//string s;
	//getline(cin, s);
	int i = 0;

	/*for (i = 0; i < 100; i++){
		while (count < s.length() && s.at(count) != ' '){
			count++;
		}
		store[i] = new Node(s.substr(0, count));
		if (count >= s.length()){
			break;
		}
		s = s.substr(count + 1);
		count = 0;
	}*/
	while (!cin.eof()){
		cin >> store[i].value;
		//cin >> store[i]->value;
		i++;
	}

	for (int m = 0; m < 100; m++){
		if (((2 * (m + 1)) <= 100) && (store[2 *m + 1].value != "null"))
			store[m].left = &store[2 * m + 1];
		if (((2 * (m + 1) + 1) <= 100) && (store[2 * m + 2].value != "null"))
			store[m].right = &store[2 * m + 2];
	}
	inOrder(store[0]);
}