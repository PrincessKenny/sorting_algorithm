#include <iostream>
#include "task1.h"
#include "task2.h"
using namespace std;
int main() {
	Data cdata;
	cdata.read_data("pop_density.txt");
	MergeSort::merger(cdata);
	Number_Data ndata("integers.txt");
	RadixSort::rsort(ndata);
	for (int i = 0; i < 100; i++)
		cout << ndata.nums[i]<<endl;
	int x;
	cin >> x;
}