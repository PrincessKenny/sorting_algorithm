#include <iostream>
#include "pop_sort1.h"
#include "generic.h"
using namespace std;
int main() {
	Reading_From_File rf_file;
	rf_file.read_data("pop_density.txt");
	cout << rf_file.c_tracts[2].pop_density;
	int x;
	cin >> x;
}