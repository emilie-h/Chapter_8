#include <iostream>
using namespace std;
template <typename T, typename U> void f(T, U) {cout << "I " ;} // fonction I
template <typename T, typename U> void f(T*, U) {cout << "II ";} // fonction II
template <typename T> void f(T, T) {cout << "III ";} // fonction III
template <typename T> void f(T, int) {cout << "IV ";} // fonction IV
void f(int, int) {cout << "V ";} // fonction V
void f(int*, float) {cout << "VI ";} // fonction VI

int main() {
	char c = 'A';
	int i = 1, j = 2;
	float x = 3.f, y = 4.f;
	double z = 5.0;
	//f(i, j);
	///1 : <T,U> = <int,?>					1 : <T,U> = <?,int>
	///2 : pas de déduction possible		2 : <T*,U> = <?,int>
	///3 : <T> = <int>						3 : <T,T> = <int,int>
	///4 : <T> = <int>						4 : <T, int> = type exact
	///5 : type exact							5 : type exact
	///6 : pas de conversion				6 : ajust float -> int
	/// R1 n R2 = 1 3 4 5 =>5 est plus specialisee
	f(c, i);
	///1 : <T,U> = <char,?>					1 : <T,U> = <?,int>
	///2 : pas de déduction possible		2 : <T*,U> = <?,int>
	///3 : <T> = <char>						3 : <T> = <int>
	///4 : <T> = <char>						4 : <T, int> = type exact
	///5 : ajust char -> int				5 : type exact
	///6 : pas de conversion				6 : pas de conversion
	/// R1 n R2 = 1 4 => 4 plus fort

	f(x, y);
	///1 : <T,U> = <float,?>				1 : <T,U> = <?,float>
	///2 : pas de déduction possible		2 : <T*,U> = <?,float>
	///3 : <T> = <float>						3 : <T> = <int>
	///4 : <T> = <float>						4 : <T, int> = ajust float -> int
	///5 : ajust float -> int				5 : ajust float -> int
	///6 : pas de conversion				6 : type exact
	/// R1 n R2 = 1 3  =>  3 est plus fort

	f(i, z);
	///1 : <T,U> = <int,?>					1 : <T,U> = <?,double>
	///2 : pas de déduction possible		2 : <T*,U> = <?,double>
	///3 : <T> = <int>						3 : <T> = <double>
	///4 : <T> = <int>						4 : <T, int> = ajust double -> int
	///5 : type exact							5 : ajust double -> int
	///6 : pas de conversion				6 : ajust double -> float
	/// R1 n R2 = 1  =>  1 est plus fort
	//f(&i, j);
	///1 : pas de déduction possible		1 : <T,U> = <?,int>
	///2 : <*T> = int&						2 : <T*,U> = <?,int>
	///3 : pas de déduction possible		3 : <T> = <int>
	///4 : pas de déduction possible		4 : <T, int> = type exact
	///5 : pas de déduction possible		5 : type exact
	///6 : <int*> = int&						6 : ajust int -> float
	/// R1 n R2 = 2 6 n 2 6 =>  ambigu??
	f(&i, x);
	///1 : pas de déduction possible		1 : <T,U> = <?,float>
	///2 : <*T> = int&						2 : <T*,U> = <?,float>
	///3 : pas de déduction possible		3 : <T> = <float>
	///4 : pas de déduction possible		4 : <T, int> = float -> int
	///5 : pas de déduction possible		5 : ajust float -> int
	///6 : <int*> = int&						6 : type exact
	/// R1 n R2 = 2 6 -> 6 est plus specialise
	f(&i, z);
	///1 : pas de déduction possible		1 : <T,U> = <?,double>
	///2 : <*T> = int&						2 : <T*,U> = <?,double>
	///3 : pas de déduction possible		3 : <T> = <double>
	///4 : pas de déduction possible		4 : <T, int> = double -> int
	///5 : pas de déduction possible		5 : ajust double -> int
	///6 : <int*> = int&						6 : ajust double -> float
	/// R1 n R2 = 2 6 n 2 -> 2
	return 0;
}

