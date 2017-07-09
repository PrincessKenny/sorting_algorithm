#include <iostream>
#include "pop_sort1.h"
#include "generic.h"
using namespace std;
int main() {
	Mergesort msort;
	Data rf_file;
	rf_file.read_data("pop_density.txt");
	//cout << rf_file.c_tracts[2].pop_density;
	msort(rf_file);
	int x;
	cin >> x;
}