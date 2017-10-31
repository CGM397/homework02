#include<iostream>
#include<string>
#include<sstream>
using namespace std;

bool find_id(string id);
bool find_subject(string sub);

int n;
string store_info[100] = {""};
long long id[100] = {-1};
string subject[100] = { "-1" };
int subject_num = 0;
int student_num = 0;

int main() {
	cin >> n;
	double average_score[100] = {0};
	double total_average_score = 0;
	for (int i = 0; i < n; i++){
		string a, b, c, d;
		cin >> a >> b >> c >> d;
		store_info[i] = store_info[i] + a + " " + b + " " + c + " " + d;
	}

	for (int i = 0; i < n - 1; i++){
		int pos1 = 0, pos2 = 0, pos3 = 0;
		while (store_info[i].at(pos1) != ' ')
			pos1++;
		pos2 = pos1 + 1;
		while (store_info[i].at(pos2) != ' ')
			pos2++;
		pos3 = pos2 + 1;
		while (store_info[i].at(pos3) != ' ')
			pos3++;
		for (int j = i + 1; j < n; j++){
			if (store_info[i].substr(0, pos3) == store_info[j].substr(0, pos3)){
				store_info[i] = store_info[j];
				store_info[j] = "astudent b c d";
			}
		}
	}                                      //update

	for (int i = 0; i < n; i++){
	    if (store_info[i].at(0) != 'a'){
		    int pos1 = 0, pos2 = 0, pos3 = 0;
		    while (store_info[i].at(pos1) != ' ')
			    pos1++;
		    pos2 = pos1 + 1;
		    while (store_info[i].at(pos2) != ' ')
			    pos2++;
		    pos3 = pos2 + 1;
		    while (store_info[i].at(pos3) != ' ')
			    pos3++;

		    if (!find_id(store_info[i].substr(pos1 + 1, pos2 - 1 - pos1))){
			    stringstream ss;
			    ss << store_info[i].substr(pos1 + 1, pos2 - 1 - pos1);
			    ss >> id[student_num];
			    student_num++;
		    }                 //store the id

		    if (!find_subject(store_info[i].substr(pos2 + 1, pos3 - 1 - pos2))){
			    subject[subject_num] = store_info[i].substr(pos2 + 1, pos3 - 1 - pos2);
			    subject_num++;
		    }                 //store the subjects
	    }
	}
	for (int i = 0; i < student_num; i++){
		for (int j = 0; j < n; j++){
			if (store_info[j].at(0) != 'a'){
				int pos = store_info[j].length() - 1;
				while (store_info[j].at(pos) != ' ')
					pos--;
				string score = store_info[j].substr(pos + 1);
				double res = 0;
				stringstream ss;
				ss << score;
				ss >> res;

				string str_id;
				stringstream tt;
				tt << id[i];
				tt >> str_id;
				size_t fi = store_info[j].find(str_id, 0);
				if (fi != store_info[j].npos){
					average_score[i] += res;
					total_average_score += res;
				}
			}
		}
	}
	total_average_score = total_average_score / student_num / subject_num;

	//for (int i = 0; i < student_num; i++)
		//cout << average_score[i] << " ";
	//cout << endl;

	long long res_id[100] = {-1};
	double res_score[100] = {-1};
	int res_count = 0;
	for (int i = 0; i < student_num; i++){
		average_score[i] = average_score[i] / subject_num;
		if (average_score[i] <= total_average_score){
			res_id[res_count] = id[i];
			res_score[res_count] = average_score[i];
			res_count++;
		}
	}                              //figure out the average score and the final selected id

	for (int k = 0; k < res_count; k++){
		for (int i = 1; i < res_count; i++){
			if (res_score[i - 1] < res_score[i]){
				double temp1 = 0;
				long long temp2 = 0;
				temp1 = res_score[i - 1];
				res_score[i - 1] = res_score[i];
				res_score[i] = temp1;

				temp2 = res_id[i - 1];
				res_id[i - 1] = res_id[i];
				res_id[i] = temp2;
			}
			else if (res_score[i - 1] == res_score[i] && res_id[i - 1] < res_id[i]){
				long long temp = 0;
				temp = res_id[i - 1];
				res_id[i - 1] = res_id[i];
				res_id[i] = temp;
			}
		}
	}                                       //sort

	for (int i = 0; i < res_count - 1; i++){
		cout << res_id[i] << endl;
	}
	cout << res_id[res_count - 1];
}

bool find_id(string tid){
	long long r = 0;
	stringstream ss;
	ss << tid;
	ss >> r;
	for (int i = 0; i < student_num; i++){
		if (id[i] == r)
			return true;
	}
	return false;
}

bool find_subject(string sub){
	for (int i = 0; i < subject_num; i++){
		if (subject[i] == sub)
			return true;
	}
	return false;
}