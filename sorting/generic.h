#pragma once
#include <vector>
#include <string>
#include <fstream>

// This is one census tract
class Census_Tract {
public:
	double area;
	double pop_density;
	int pop_count;
	std::string name;
	Census_Tract(std::string name, double area, int pop_count, double pop_density)
		:name(name), area(area), pop_count(pop_count), pop_density(pop_density) {}
};

//reads the censuses to a vector
class Data {
	std::ifstream myfile;
public:
	std::vector<Census_Tract> c_tracts;
	Data() {}

	//reading the input
	void read_data(std::string filename) {
		myfile.open(filename);
		if (myfile.is_open()) {
			std::string name;
			double area;
			int pop_count;
			double pop_density;
			for (std::string line; std::getline(myfile, line);) {		//gets a string by line, then breaks it down to substrings, and gets the values
				std::string::size_type pos = line.find('|');			//the pos and the pos2 moves, giving you substrings
				name = line.substr(0, pos);
				std::string::size_type pos2 = line.find('|', pos + 1);
				area = stod(line.substr(pos + 1, pos2));
				pos = pos2;
				pos2 = line.find('|', pos + 1);
				pop_count = stoi(line.substr(pos + 1, pos2));
				pos = pos2;
				pop_density = stod(line.substr(pos + 1, line.length()-1));
				c_tracts.push_back(Census_Tract(name, area, pop_count, pop_density));
			}
		}
		myfile.close();
	}
};

class Mergesort {
public:
	void merge(Data& data,int l,int m,int r) {
		
	}
	void mergesort(Data& data, int l, int r) {
		if (l < r) {
			int m = l + (r - 1) / 2;
			mergesort(data, l, m);
			mergesort(data, m + 1, r);

			merge(data, l, m, r);
		}
	}
	void operator()(Data& data) {
		mergesort(data, 0, data.c_tracts.size()-1);
	}
};