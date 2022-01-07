#include <iostream>
using namespace std;
template <typename T = int> class A {};
template <typename T, typename U, int n> class B {};
int main(){
	//B<int, double, 1> b;
	///correct
	//const int N = 1; B<int, int, N> b;
	///inc const int à int pas possible
	//int n = 1;
	//B<int, double, n> b;
	///incorrect ??
	//B<int, double, 'A'> b;
	///correct, promotion char -> int
	//B<int, double, 'A' + 'B'> b;
	///correct
	//B<int, double, 1.0> b;
	///incorrect double -> int pas possible
	//B<int, int*, 1> b;
	///correct
	//B<A<>, double, 1> b;
	///T = class A<int>
	//B<double, A, 1> b;
	///incorrect A n'a pas de type
	//B<A<double>, double, true> b;
	///correct


}
