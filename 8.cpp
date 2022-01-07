#include <iostream>
#include <cstdlib>
using namespace std;
template <typename T, size_t n>
class Array {
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
	}


private:
	T tab[n];
};
template <typename T, size_t n>
Array<T, n>::Array(const T& valeur){
	for(int i = 0; i < n; ++i){
		tab[i] = valeur;
	}
}


template <size_t n>
class Array<bool, n> {
public:
	Array(const bool& valeur);
	friend ostream& operator<<(ostream& os, const Array<bool, n> a){
		os << '[';
		for(int i = 0; i < n; ++i){
			if(a.tab[i] == 0){
			os << "faux ";
			}else{
				os << "vrai";
			}
			if(i != n - 1){
				os << ',';
			}
		}
		os << ']';
		return os;
	}

	//std::ostream&
//	operator<<(std::ostream& output, const Array<bool, n >& a);

private:
	bool tab[n];
};

template <size_t n>
Array<bool, n>::Array(const bool& valeur){
	for(int i = 0; i < n; ++i){
		tab[i] = valeur;
	}
}

//template <bool, size_t n>
//
//std::ostream&
//operator<<(std::ostream& output, const Array<bool, n >& a)
//{
//	output << '[';
//	for(int i = 0; i < n; ++i){
//		output << boolalpha << a.tab[i];
//		if(i != n - 1){
//			output << ',';
//		}
//	}
//	output << ']';
//	return output;
//}
int main ()
{
//	Array<int, 3> a1(1);
//	cout << a1 << endl;
//
//	Array<double, 4> a2(1.5);
//	cout << a2 << endl;
	Array<bool, 5> a3(true);
	cout << a3 << endl;

	return EXIT_SUCCESS; }