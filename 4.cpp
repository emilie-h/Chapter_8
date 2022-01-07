#include <iostream>
using namespace std;
template <typename T, typename U> void f(T, U, int){cout << "1 ";}//fonction 1
template <typename T> void f(T, T, short){cout << "2 ";}; // fonction 2
template <typename T> void f(T, int, int){cout << "3 ";}; // fonction 3
void f(int, int, int){cout << "4 ";}; // fonction 4
char c = 'A'; short s = 1; int i = 2, j = 3; float x = 4.f;
int main(){
	f(i, j, c);
	///i: 1 T = int		2 T = int		3 T = int 			4 T = int type exact
	///j: 1 U = int		2 T = int		3 int = int TE 	4 int = int type exact
	///j: 1 char -> int	2 char -> short	3 char -> int  4 char -> int
	/// R1 n R2 n R3 1 2 3 4 n 1 2 3 4 n 1 3 4 = 4 car plus fort

	f(i, j, s);
	///i: 1 T = int		2 T = int		3 T = int 			4 T = int type exact
	///j: 1 U = int		2 T = int		3 int = int TE 	4 int = int type exact
	///j: 1 short -> int	2 short -> short	3 short -> int  4 short -> int
	/// R1 n R2 n R3 1 2 3 4 n 1 2 3 4 n 2(le seul avec type exact) = 2

	f(i, j, x);
	///i: 1 T = int		2 T = int		3 T = int 			4 T = int type exact
	///j: 1 U = int		2 T = int		3 int = int TE 	4 int = int type exact
	///j: 1 float -> int	2 float -> short	3 float -> int  4 float -> int
	/// R1 n R2 n R3 1 2 3 4 n 1 2 3 4 n 1 2 3 4 = 4 car plus fort

}