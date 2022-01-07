#include <iostream>
#include <vector>
#include <list>
using namespace std;

template< typename T, template<typename, typename> class Container>
class Collection {
public:
	Collection<T, Container>;
	friend ostream& operator<<(ostream& os, const Collection& a){
		os << '[';

		for(auto i = a.v.begin(); i < a.v.end(); ++i){
			os << *i;
			if(i != a.v.end() - 1){
				os << ',';
			}
		}
		os << ']';
		return os;
	}
	void add(const T& element);
	size_t size();
	void clear();
	T get(size_t index);
private:
	std::vector<T> v;
};

template< typename T, template<typename, typename> class Container>
void Collection<T, Container>::add(const T& element) {
	v.push_back(element);
}
template< typename T, template<typename, typename> class Container>
size_t Collection<T, Container>::size(){
	return v.size();
}
template< typename T, template<typename, typename> class Container>
void Collection<T, Container>::clear(){
	v.clear();
}

template< typename T, template<typename, typename> class Container>
T Collection<T, Container>::get(size_t index){
	return v.at(index);
}

template<template<typename, typename> class Container>
class Collection<std::string, Container>{
public:
	Collection<string, Container>;
	friend ostream& operator<<(ostream& os, const Collection& a){
		os << '[';

		for(auto i = a.l.begin(); i != a.l.end(); ++i){
			if(i != a.l.end()){
				os << *i;
				os << ',';
			}
		}
		os << ']';
		return os;
	}
	void add(const string& element);
	size_t size();
	void clear();
	string get(size_t index);
private:
	list<string> l;
};

template<template<typename, typename > class Container>
void Collection<string, Container>::add(const string& element){
	l.push_back(element);
}

template<template<typename, typename> class Container>
size_t Collection<string, Container>::size(){
	return l.size();
}

template< template<typename, typename> class Container>
void Collection<string, Container>::clear(){
	l.clear();
}

template<template<typename, typename> class Container>
string Collection<string, Container>::get(size_t index){
	auto it = l.begin();
	advance(it, index);
	return *it;
}

int main() {
	Collection<int, vector> integers;
	integers.add(1);
	integers.add(2);
	integers.add(3);
	size_t nb_integers = integers.size();
	cout << "integers contient " << nb_integers << " element"
	<< (nb_integers > 1 ? "s" : "") << " : ";
	cout << integers << endl;

	size_t index_integer = 2;
	cout << "L'element d'indice " << index_integer << " de integers vaut : "
	<< integers.get(index_integer) << endl;
	integers.clear();
	nb_integers = integers.size();
	cout << "integers contient " << nb_integers << " element"
	<< (nb_integers > 1 ? "s" : "") << " : ";
	cout << integers << endl;

	Collection<string, list> strings;
	strings.add("un");
	strings.add("deux");
	strings.add("trois");
	strings.add("quatre");
	size_t nb_strings = strings.size();
	cout << "strings contient " << nb_strings
		<< " element" << (nb_strings > 1 ? "s" : "") << " : ";
	cout << strings << endl;
	size_t index_string = 2;
	cout << "L'element d'indice " << index_string << " de integers vaut : "
		<< strings.get(index_string) << endl;
	strings.clear(); nb_strings = strings.size();
	cout << "strings contient " << nb_strings << " element"
	<< (nb_strings > 1 ? "s" : "") << " : ";
	cout << strings << endl;
	return EXIT_SUCCESS;

}
