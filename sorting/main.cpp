#include <iostream>
#include "pop_sort1.h"
#include "generic.h"
using namespace std;
int main() {
	Data rf_file;
	rf_file.read_data("pop_density.txt");
	Mergesort::merger(rf_file);
/*	for (int i = 70000; i >= 69000; i--) {
		cout << rf_file.c_tracts[i].name << endl;
		cout << rf_file.c_tracts[i].pop_density << endl;
	}*/
	int x;
	cin >> x;
}