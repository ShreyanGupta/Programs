#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;


bool q1_unique_char(string str){
	unordered_set<char> s;
	for(auto i : str){
		if(s.find(i) == s.end()){
			s.insert(i);
		}else return false;
	}
	return true;
}

bool q1_unique_char_2(string str){
	sort(str.begin(), str.end());
	for(int i=0; i<str.length()-1; ++i){
		if(str[i] == str[i+1]) return false;
	}
	return true;
}

void q2_reverse_string(string &s){
	int n = s.length();
	for(int i=0; i<= n/2; ++i){
		char temp = s[i];
		s[i] = s[n-i-1];
		s[n-i-1] = temp;
	}
}

void q3_remove_duplicate(char *str){
	char *read_ptr = str;
	char *write_ptr =str;
	set<char> s;
	while(*read_ptr != '\0'){
		if(s.find(*read_ptr) == s.end()){
			*write_ptr = *read_ptr;
			++write_ptr;
			s.insert(*read_ptr);
		}
		++read_ptr;
	}
	*write_ptr = '\0';
}

bool q4_anagrams(string s1, string s2){
	unordered_map<char, int> m;
	for(auto i : s1){
		++m[i];
	}
	for(auto i : s2){
		--m[i];
	}
	for(auto &i : m){
		if(i.second != 0) return false;
	}
	return true;
}

void q5_replace_spaces(char *&str){
	int spaces = 0;
	int places = 0;
	char *ptr = str;
	while(*ptr != '\0'){
		++places;
		if(*ptr == ' ') ++spaces;
		++ptr;
	}
	char *temp_str = new char[places + 1 + 2*spaces];
	ptr = str;
	char *temp_ptr = temp_str;
	while(*ptr != '\0'){
		if(*ptr == ' '){
			*temp_ptr = '%'; ++temp_ptr;
			*temp_ptr = '2'; ++temp_ptr;
			*temp_ptr = '0'; ++temp_ptr;
		}else{
			*temp_ptr = *ptr;
			++temp_ptr;
		}
		++ptr;
	}
	*temp_ptr = '\0';
	// delete[] str;
	str = temp_str;
}

void q6_rotate(vector< vector<char> > &m){
	for(auto &i : m){
		for(auto &j : i) cout << j << " ";
		cout << endl;
	}

	int n = m.size()-1;
	for(int i=0; i<=n/2; ++i){
		for(int j=0; j<=n/2; ++j){
			char temp = m[j][n-i];
			m[j][n-i] = m[n-j][n-i];
			m[n-j][n-i] = m[n-j][i];
			m[n-j][i] = m[i][j];
			m[i][j] = temp;
		}
	}

	cout << endl;
	for(auto &i : m){
		for(auto &j : i) cout << j << " ";
		cout << endl;
	}
	cout << endl;
}

void q7_zero_in_matrix(vector< vector<int> > &matrix){
	for(auto &i : matrix){
		for(auto &j : i) cout << j << " ";
		cout << endl;
	}

	int m = matrix.size();
	if(m==0) return;
	int n = matrix[0].size();
	set<int> zero_row;
	set<int> zero_col;
	// for(int i=0; i<n; ++i) non_zero_col.insert(i);

	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			if(matrix[i][j] == 0){
				zero_row.insert(i);
				zero_col.insert(j);
				// non_zero_col.remove(j);
			}
		}
	}
	for(auto &i : zero_row){
		for(int j=0; j<n; ++j) matrix[i][j] = 0;
	}
	for(auto &j : zero_col){
		for(int i=0; i<m; ++i) matrix[i][j] = 0;
	}

	cout << endl;
	for(auto &i : matrix){
		for(auto &j : i) cout << j << " ";
		cout << endl;
	}
	cout << endl;
}

// bool q8_is_rotation(string s1, string s2){
// 	s2 = s2+s2;
// 	return (s2.is_substring(s1));
// }

void q1_test(){
	cout << "testing q1" << endl;
	string temp;
	temp = "abcdefghij";
	cout << "\t" << temp << "  " << q1_unique_char(temp) << q1_unique_char_2(temp) << endl;
	temp = "";
	cout << "\t" << temp << "  " << q1_unique_char(temp) << q1_unique_char_2(temp) << endl;
	temp = "abcdefghijklmnab";
	cout << "\t" << temp << "  " << q1_unique_char(temp) << q1_unique_char_2(temp) << endl;
}
void q2_test(){
	cout << "testing q2" << endl;
	string temp;
	temp = "abcdefghi";
	cout << "\t" << temp << " ";
	q2_reverse_string(temp);
	cout << temp << endl;

	temp = "";
	cout << "\t" << temp << " ";
	q2_reverse_string(temp);
	cout << temp << endl;

	temp = "bla bla bla 999";
	cout << "\t" << temp << " ";
	q2_reverse_string(temp);
	cout << temp << endl;
}
void q3_test(){
	cout << "testing q3" << endl;
	char test1[] = "redundant chars redundant chars 111";
	cout << "\t" << test1 << " ";
	q3_remove_duplicate(test1);
	cout << test1 << endl;

	char test2[] = "";
	cout << "\t" << test2 << " ";
	q3_remove_duplicate(test2);
	cout << test2 << endl;

	char test3[] = "aaaaaaaa      aaaaaaaa bbbbbb bbbbbb cccccccc ccc c c c dddddddddd";
	cout << "\t" << test3 << " ";
	q3_remove_duplicate(test3);
	cout << test3 << endl;
}
void q4_test(){
	cout << "testing q4" << endl;
	string t1, t2;
	t1 = "abcdefff"; t2 = "abcfedff";
	cout << "\t" << t1 << " " << t2 << " " << q4_anagrams(t1, t2) << endl;

	t1 = "abcd"; t2 = "abcf";
	cout << "\t" << t1 << " " << t2 << " " << q4_anagrams(t1, t2) << endl;

	t1 = ""; t2 = "";
	cout << "\t" << t1 << " " << t2 << " " << q4_anagrams(t1, t2) << endl;
}
void q5_test(){
	cout << "testing q5" << endl;
	char *ptr;
	char test1[] = "replacing all spaces";
	cout << "\t" << test1 << " ";
	ptr = test1; 
	q5_replace_spaces(ptr);
	cout << ptr << endl;

	char test2[] = "a";
	cout << "\t" << test2 << " ";
	ptr = test2; 
	q5_replace_spaces(ptr);
	cout << ptr << endl;

	char test3[] = "spaces     spaces   ";
	cout << "\t" << test3 << " ";
	ptr = test3; 
	q5_replace_spaces(ptr);
	cout << ptr << endl;
}
void q6_test(){
	cout << "testing q6" << endl;
	vector< vector<char> > t1(1, vector<char>(1, 'a'));
	q6_rotate(t1);

	vector< vector<char> > t2(2, vector<char>(2));
	t2[0][0] = 'x'; t2[0][1] = 'y'; t2[1][0] = 'z'; t2[1][1] = 'w';
	q6_rotate(t2);

	vector< vector<char> > t3(3, vector<char>(3));
	t3[0][0] = 'x'; t3[0][1] = 'y'; t3[0][2] = 'z'; 
	t3[1][0] = 'a'; t3[1][1] = 'b'; t3[1][2] = 'c'; 
	t3[2][0] = 'p'; t3[2][1] = 'q'; t3[2][2] = 'r'; 
	q6_rotate(t3);

}
void q7_test(){
	cout << "testing q7" << endl;
	vector< vector<int> > t1(1, vector<int>(1, 1));
	q7_zero_in_matrix(t1);

	vector< vector<int> > t2(2, vector<int>(2));
	t2[0][0] = 1; t2[0][1] = 1; t2[1][0] = 1; t2[1][1] = 0;
	q7_zero_in_matrix(t2);

	vector< vector<int> > t3(3, vector<int>(3));
	t3[0][0] = 0; t3[0][1] = 0; t3[0][2] = 1; 
	t3[1][0] = 1; t3[1][1] = 0; t3[1][2] = 1; 
	t3[2][0] = 1; t3[2][1] = 1; t3[2][2] = 1;
	q7_zero_in_matrix(t3);
}


int main(int argc, char const *argv[])
{
	q1_test();
	q2_test();
	q3_test();
	q4_test();
	q5_test();
	q6_test();
	q7_test();
	return 0;
}