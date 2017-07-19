#include <iostream>
#include "task1.h"
#include "task2.h"
using namespace std;
int main() {
	Data cdata;
	cdata.read_data("pop_density.txt");
	MergeSort::merger(cdata);
	for (int i = 0; i != 1000; i++)
	{
		cout << cdata[i].name<<endl;
		cout << cdata[i].pop_density<<endl;
	}
	Data cdata2;
	cdata2.read_data("pop_density.txt");
	QuickSort::qsort(cdata2);
	for (int i = 0; i != 1000; i++)
	{
		cout << cdata[i].name<<endl;
		cout << cdata[i].pop_density<<endl;
	}
	Number_Data ndata("integers.txt");
	RadixSort::rsort(ndata);
	for (int i = 0; i < 100; i++)
		cout << ndata.nums[i]<<endl;
	int x;
	cin >> x;
}