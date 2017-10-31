#include<iostream>
#include<string>
using namespace std;

struct Node{
	string value;
	Node * next;
	Node(string x){
		this->value = x;
		this->next = NULL;
	}
};

int main() {
	int n;
	cin >> n;
	string t;
	getline(cin, t);
	string s;
	Node * head = new Node("start");
	Node * op;
	op = head;
	for (int i = 0; i < n; i++){
		getline(cin, s);
		if (s.length() > 3 && s.substr(0, 3).compare("ADD") == 0){
			if (op->value.compare("start") == 0){
				op->value = s.substr(4);
			}
			else{
				op->next = new Node(s.substr(4));
				op = op->next;
			}
		}
		else if (s.compare("SIZE") == 0){
			if (head->value.compare("start") == 0){
				cout << 0;
				if (i != n - 1)
					cout << endl;
			}
			else{
				int count = 0;
				Node * t_head = head;
				while (t_head != NULL){
					count++;
					t_head = t_head->next;
				}
				cout << count;
				if (i != n - 1)
					cout << endl;
			}
		}
		else if (s.compare("PRINT") == 0){
			Node * t = head;
			if (t->value.compare("start") == 0){
				cout << "NULL";
				if (i != n - 1)
					cout << endl;
			}
			else{
				while (t->next != NULL){
					cout << t->value << " ";
					t = t->next;
				}
				cout << t->value;
				if (i != n - 1)
					cout << endl;
			}
		}
		else if (s.length() > 3 && s.substr(0, 3).compare("DEL") == 0){
			Node * t = head;
			while (t->next != NULL && t->value.compare(s.substr(4)) == 0){
				head = t->next;
				t = head;
			}
			if (t->next == NULL){
				if (t->value.compare(s.substr(4)) == 0)
					t->value = "start";
			}
			while (t->next != NULL){
				if (t->next->value.compare(s.substr(4)) == 0){
					t->next = t->next->next;
				}
				else{
					t = t->next;
				}
			}
		}
		else if (s.length() > 12 && s.substr(0, 12).compare("REMOVEREPEAT") == 0){
			Node * t = head;
			int count_repeat = 0;
			while (t != NULL){
				if (t->value.compare(s.substr(13)) == 0){
					count_repeat++;
				}
				t = t->next;
			}
			t = head;
			while (t->value.compare(s.substr(13)) == 0 && count_repeat > 1){
				count_repeat--;
				head = t->next;
				t = head;
			}
			while (t->next != NULL){
				if (t->next->value.compare(s.substr(13)) == 0 && count_repeat > 1){
					t->next = t->next->next;
					count_repeat--;
				}
				else{
					t = t->next;
				}
			}
		}
		else if (s.compare("REVERSE") == 0){
			string store[100];
			Node * t = head;
			int a = 0;
			while (t != NULL){
				store[a] = t->value;
				t = t->next;
				a++;
			}
			t = head;
			while (t != NULL){
				t->value = store[a - 1];
				a--;
				t = t->next;
			}
		}
	}
}