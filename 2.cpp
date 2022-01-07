#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Time{
public:
	string convertTime(int h = 0, int m = 0){
		stringstream ss;
		ss << setfill('0') << setw(2) << h << ':';
		ss << setfill('0') << setw(2) << m;
		return timeStr = ss.str();
	};
private:
	string timeStr;
};

template <typename T> int nbOcc(vector<T> v, T element){
	int count = 0;
	auto i = v.begin();

	while(i != v.end()) {
		auto it = find(i, v.end(), element);
		if(it != v.end()) {
			++count;
			i = it + 1;
		}else{
			++i;
		}

	}
	return count;
}

int main(){
	vector<int> v1 {0, 1, 0};
	int el = 0;
	cout << el << " found " << nbOcc<int>(v1, el) << " times" << endl;
	Time t;
	string str1 = t.convertTime(12, 00);
	vector<string> v2 {"07:45", "09:20", "12:00", "21:30"};
	cout << str1 << " found " << nbOcc(v2, str1) << " times" << endl;
	string str2 = "Paul";
	vector<string> v3 {"Paul", "Jacques", "Paul", "Jean", "Paul"};
	cout << str2 << " found "<< nbOcc(v3, str2)<< " times" << endl;
	vector<const char*> v4 {"Paul", "Jacques", "Paul", "Jean", "Paul"};
	const char* char1 = "Paul";
	cout << char1 << " found "<< nbOcc(v4, char1)<< " times" << endl;

}