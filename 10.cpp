#include <iostream>
#include <vector>
#include <list>
#include "Collection.h"
using namespace std;

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
