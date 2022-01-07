#include <iostream>
#include <cstdlib>
using namespace std;
template <typename T>
class C;

template <typename T>
class C {
public:
	C(T t) : t(t) {};

	void afficher() const;
private: T t;
};
template <typename T> void C<T>::afficher() const { cout << t; }

template<typename T>
class C<T*> {
public:
	C(T* t) : t(*t) {};
	void afficher() const;
private: T t;
};
template <typename T> void C<T*>::afficher() const { cout << t;}
template<>
class C<const char*> {
public:
	C(const char* t) : t(t) {};
	void afficher() const;
private:
	const char* t;
};
void C<const char*>::afficher() const { cout << t; }

int main ()
{
	int n = 1; C<int> c1(n); c1.afficher();cout << endl; // 1
	C<int*> c2(&n); c2.afficher(); cout << endl; //pointeur de int 1
	C<const char*> c3("Hello"); c3.afficher(); cout << endl; //Hello
	return EXIT_SUCCESS; }
	// https://stackoverflow.com/questions/37521890/template-class-partial-specialization-syntax
