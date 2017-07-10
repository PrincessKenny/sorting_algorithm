#include <iostream>
#include "task1.h"
using namespace std;
int main() {
	Data rf_file;
	rf_file.read_data("pop_density.txt");
	//Mergesort::merger(rf_file);
	Quicksort::qsort(rf_file);
	for (int i = 0; i <=1000; i++) {
		cout << rf_file.c_tracts[i].name << endl;
		cout << rf_file.c_tracts[i].pop_density << endl;
	}
	int x;
	cin >> x;
}