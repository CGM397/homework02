#include<iostream>
#include<string>
using namespace std;

string node1, node2;
int count_step = 0, sign = 0;
struct Node{
	string value = "NULL";
	Node * left = NULL;
	Node * right = NULL;
};

Node node_one, node_two;

void search(Node root, string target){
	if (root.value == target){
		if (target == node1)
			node_one = root;
		if (target == node2)
			node_two = root;
	}
	if (root.left != NULL)
		search(*root.left, target);
	if (root.right != NULL)
		search(*root.right, target);
}

void inOrder(Node root, string target){
	if (sign == 1)
		return;
	if (root.value == target){
		sign = 1;
		return;
	}
	else if (root.left != NULL){
		if (sign == 1)
			return;
		count_step++;
		inOrder(*root.left, target);
		if (sign == 1)
			return;
		count_step--;
	}
	if (sign == 1)
		return;
	else if (root.right != NULL){
		if (sign == 1)
			return;
		count_step++;
		inOrder(*root.right, target);
		if (sign == 1)
			return;
		count_step--;
	}
	if (sign == 1)
		return;
}

int main(){
	int m;
	cin >> m;
	Node * node = new Node[1000];
	for (int i = 0; i < m; i++){
		cin >> node[i].value;
	}
	for (int i = 0; i < m; i++){
		if (node[i].value != "NULL"){
			if ((2 * i + 1 < m) && (node[2 * i + 1].value != "NULL"))
				node[i].left = &node[2 * i + 1];
			if ((2 * i + 2 < m) && (node[2 * i + 2].value != "NULL"))
				node[i].right = &node[2 * i + 2];
		}
	}
	cin >> node1 >> node2;
	search(node[0], node1);
	search(node[0], node2);
	inOrder(node_one, node2);
	if (sign == 0)
		count_step = 0;
	else{
		cout << count_step;
		return 0;
	}
	inOrder(node_two, node1);
	if (sign == 0)
		cout << "-1";
	else{
		cout << count_step;
		return 0;
	}

}