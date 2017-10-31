#include<iostream>
#include<string>

using namespace std;

bool judge(string content);

int main(){
	string s;
	getline(cin, s);
	if (judge(s))
		cout << "True";
	else
		cout << "False";
}

bool judge(string content){
	string tag_name1, tag_name2;
	int count1 = 1, count2 = content.length() - 2;
		while (count1 < content.length() && content.at(count1) != '>'){
			if (content.at(count1) < 65 || content.at(count1) > 90){
				return false;
			}
			count1++;
		}
		tag_name1 = content.substr(1, count1 - 1);
		if (tag_name1.length() < 1 || tag_name1.length() > 9){
			return false;
		}
		while (count2 >= 0 && content.at(count2) != '/')
			count2--;
		tag_name2 = content.substr(count2 + 1, content.length() - 2 - count2);
		if (tag_name1.compare(tag_name2) != 0){
			return false;
		}


	if (count2 - count1 - 2 <= 0)
		return true;
	string con = content.substr(count1 + 1, count2 - count1 - 2);
	for (int i = 0; i < con.length(); i++){
		int start = 0, end = 0;
		if (i<con.length() - 3 && con.substr(i, 4).compare("<!--") == 0){
			start = i;
			while (i < con.length() - 3 && con.substr(i + 1, 3).compare("-->") != 0){
				i++;
			}
			if (i == con.length() - 3){
				return false;
			}
			end = i + 4;
			string t = con.substr(end);
			con = con.substr(0, start);
			con = con + t;
		}
	}                                                    //delete all the <!- ->;

	for (int i = 0; i < con.length(); i++){
		if (con.at(i) == '('){
			while (i < con.length() && con.at(i) != ')')
				i++;
			if (i == con.length()){
				return false;
			}
		}
	}

	for (int i = 0; i < con.length(); i++){
		int start = 0, end = 0;
		if (con.at(i) == '<'){
			start = i;
			while (i < con.length() && con.at(i) != '>')
				i++;
			if (i == con.length()){
				return 0;
			}
			while (i<con.length() - 2 && con.substr(i + 1, 2) != "</")
				i++;
			if (i == con.length() - 1)
				return 0;
			while (i<con.length() - 1 && con.at(i + 1) != '>')
				i++;
			if (i == con.length() - 1)
				return 0;
			end = i + 1;
		}
		if (end - start + 1 <= 0)
			return true;
		string sub = con.substr(start, end - start + 1);
		return judge(sub);
	}
	return true;
}