#include <iostream>
#include <string>
using namespace std;

template <typename T, size_t n>
class Array{
public:
	Array(const T& valeur);
	friend ostream& operator<<(ostream& os, const Array<T, n> a){
		os << '[';
		for(int i = 0; i < n; ++i){
			os << a.tab[i];
			if(i != n - 1){
				os << ',';
			}
		}
		os << ']';
		return os;

	};

private:
	T tab[n];
};
template <typename T, size_t n>
Array<T, n>::Array(const T& valeur){
	for(int i = 0; i < n; ++i){
		tab[i] = valeur;
	}
}


int main() {
	Array<int, 3> a1(1);
	cout << a1 << endl;

	Array<double, 4> a2(1.5);
	cout << a2 << endl;
	return EXIT_SUCCESS; }

//see generic issue for ostream (only works inline) :
// https://stackoverflow.com/questions/41686397/generic-ostream-issue-in-c