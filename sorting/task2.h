#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

class Number_Data {
public:
	std::vector<int> nums;
	Number_Data(std::string fname) {
		readnums(fname);
	}
	void readnums(std::string filename) {
		std::ifstream myfile(filename);
		int n;
		while (myfile >> n)
			nums.push_back(n);
		myfile.close();
	}
};


class RadixSort {
	static int getMax(const Number_Data& data) {
		int mx = data.nums[0];
		for (int i = 1; i < data.nums.size(); i++)
			if (data.nums[i] > mx)
				mx = data.nums[i];
		return mx;
	}
	static void countsort(Number_Data& data, int exp) {
		std::vector<int> output; // output array
		std::vector<int> count;
		for (int j = 0; j < 10; j++)
			count.push_back(0);
		for (int j = 0; j < data.nums.size(); j++)
			output.push_back(0);
		int i;

		// Store count of occurrences in count[]
		for (i = 0; i < data.nums.size(); i++)
			count[(data.nums[i] / exp) % 10]++;

		// Change count[i] so that count[i] now contains actual
		//  position of this digit in output[]
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		// Build the output array
		for (i = data.nums.size() - 1; i >= 0; i--) {
			output[count[(data.nums[i] / exp) % 10] - 1] = data.nums[i];
			count[(data.nums[i] / exp) % 10]--;
		}

		// Copy the output array to arr[], so that arr[] now
		// contains sorted numbers according to current digit
		for (i = 0; i < data.nums.size(); i++)
			data.nums[i] = output[i];
	}
	static void radixsort(Number_Data& data) {
		int m = getMax(data);
		for (int exp = 1; m / exp > 0; exp *= 10)
			countsort(data, exp);
	}
public:
	static void rsort(Number_Data& data) {
		radixsort(data);
	}
};