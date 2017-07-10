#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
// This is one census tract
class Census_Tract {
	double area;
	double pop_density;
	int pop_count;
	std::string name;
public:
	Census_Tract(std::string name, double area, int pop_count, double pop_density)
		:name(name), area(area), pop_count(pop_count), pop_density(pop_density) {}
	friend bool operator<=(const Census_Tract& lhs, const Census_Tract& rhs);
};
bool operator<=(const Census_Tract& lhs, const Census_Tract& rhs) {
	if (lhs.pop_density <= rhs.pop_density)
		return true;
	else
		return false;
}

//reads the censuses to a vector
class Data {
	std::ifstream myfile;
	std::vector<Census_Tract> c_tracts;
public:
	Data() {}
	size_t size() {
		return c_tracts.size();
	}
	Census_Tract& operator[](int index) {
		return c_tracts[index];
	}
	Census_Tract operator[](int index) const {
		return c_tracts[index];
	}
	//reading the input
	void read_data(std::string filename) {
		myfile.open(filename);
		if (myfile.is_open()) {
			std::string name;
			double area;
			int pop_count;
			double pop_density;

			for (std::string line; std::getline(myfile, line);) {//gets a string by line, then breaks it down to substrings, and gets the values
				std::string::size_type pos = line.find('|');			//the pos and the pos2 moves, giving you substrings
				name = line.substr(0, pos);
				std::string::size_type pos2 = line.find('|', pos + 1);
				area = stod(line.substr(pos + 1, pos2));
				pos = pos2;
				pos2 = line.find('|', pos + 1);
				pop_count = stoi(line.substr(pos + 1, pos2));
				pos = pos2;
				pop_density = stod(line.substr(pos + 1, line.length() - 1));
				c_tracts.push_back(Census_Tract(name, area, pop_count, pop_density));
			}
		}
		myfile.close();
	}
};

class MergeSort {
	static void merge(Data& data, int l, int m, int r) {
		int i, j, k;
		std::vector<Census_Tract> temp1;
		std::vector<Census_Tract> temp2;
		int n1 = m - l + 1;
		int n2 = r - m;
		for (i = 0; i < n1; i++)
			temp1.push_back(data[l + i]);
		for (j = 0; j < n2; j++)
			temp2.push_back(data[m + 1 + j]);
		i = 0;
		j = 0;
		k = l;
		while (i < n1 && j < n2) {
			if (temp1[i] <= temp2[j]) {
				data[k] = temp1[i];
				i++;
			}
			else {
				data[k] = temp2[j];
				j++;
			}
			k++;
		}
		while (i < n1) {
			data[k] = temp1[i];
			i++;
			k++;
		}
		while (j < n2) {
			data[k] = temp2[j];
			j++;
			k++;
		}
	}
	//normal mergesort algorithm
	static void mergesort(Data& data, int l, int r) {
		if (l < r) {
			int m = l + (r - l) / 2;
			mergesort(data, l, m);
			mergesort(data, m + 1, r);

			merge(data, l, m, r);
		}
	}
public:
	static void merger(Data& data) {
		clock_t t = clock();
		mergesort(data, 0, data.size() - 1);
		t = clock() - t;
		std::cout << t << std::endl;
	}
};

class QuickSort {


	static int partition(Data& data, int l,int h)
	{
		// pivot (Element to be placed at right position)
		Census_Tract pivot = data[h];

		int i = (l - 1);  // Index of smaller element

			for (int j = l; j <= h - 1; j++)
			{
				// If current element is smaller than or
				// equal to pivot
				if (data[j] <= pivot)
				{
					i++;    // increment index of smaller element
					swap(data[i], data[j]);
				}
			}
			swap(data[i + 1], data[h]);
			return (i + 1);
	}
	static void swap(Census_Tract& c1, Census_Tract& c2) {
		Census_Tract tmp = c1;
		c1 = c2;
		c2 = tmp;
	}
	static void quicksort(Data& data, int l, int h)
	{
		if (l < h)
		{
			/* pi is partitioning index, arr[p] is now
			at right place */
			int pi = partition(data, l, h);

			quicksort(data, l, pi - 1);  // Before pi
			quicksort(data, pi + 1, h); // After pi
		}
	}
public:
	static void qsort(Data& data) {
		clock_t t = clock();
		quicksort(data, 0, data.size() - 1);
		t = clock() - t;
		std::cout << t;
	}
};