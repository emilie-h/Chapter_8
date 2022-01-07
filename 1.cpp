#include <iostream>

using namespace std;
template <typename T, typename U> T f(T x, U y, T z) {
	return x + y + z;
}
int main() {
	int i = 1, j = 2, k = 3;
	double x = 4.5, y = 5.5;
	//f(i, x, j);
	// // 1: T et U non spécifiés
	//// 2: T -> int et U -> double ok
	///3: 1 + 4.5 + 3 = 7.5 (retourne en int) = 7

	//cout << f<>(x, i, y);
	///1: T et U non spécifiés
	///2: T -> double, U -> int
	///3: 4.5 + 1.0 + 5.5 (retourne en double) = 11

	//cout << f(i, j, k);
	///1: T et U non spécifiés
	///2: T -> int, U -> int
	///3: 1 + 2 + 3 (retourne en int) = 6

	//cout << f(i, j, x);
	///1: T et U non spécifiés
	///2: T -> int ou double , U -> int :(
	///3: error

	//cout << f((double)i, j, x);
	///1: T et U non spécifiés
	///2: T -> double, U -> int
	///3: 1.0 + 2.0 + 4.5 (retourne en double) = 7.5

	//cout << f<int, double>(i, j, x);
	///1: T -> int, U -> double
	///2: x converti en int, j converti en double
	///3: 1.0 + 2.0 + 4.0 (retourne en int) = 7

	//cout << f<int>(i, x, x);
	///1: T -> int, U non spécifié
	///2: U -> double et dernier x converti en int
	///3: 1 + 4.5 + 4.0 (retourne en int) = 9

	//cout << f<double>(i, x, x);
	///1: T -> double, U non spécifié
	///2: U -> double
	///3: 1.0 + 4.5 + 4.5 (retourne en double) = 10
	return 0;
}
