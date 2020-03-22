
#include <stdio.h> 
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;

double Percentile(double p_Number, vector<int> myVector) {

	sort(myVector.begin(), myVector.end());

	if (myVector.size() == 1) {
		return myVector[0];
	}


	double 	interval = 1.0 / (myVector.size() - 1);
	int leftNum = static_cast<int>((p_Number / 100.0) / interval);

	int rightNum;

	if (leftNum == myVector.size() - 1)
		rightNum = leftNum;
	else
		rightNum = leftNum + 1;



	double percentile = ((((p_Number / 100.0) - interval * leftNum) / interval)) * (myVector[rightNum] - myVector[leftNum]) + myVector[leftNum];


	return percentile;
}

double Average(vector<int> myVector) {

	double average = 0;

	for (int i = 0; i < myVector.size(); ++i)
	{
		average += myVector[i];
	}
	average /= myVector.size();

	return average;
}

double Max_element(vector <int> maxVector)
{
	double max_v = maxVector[0];

	for (int i = 0; i < maxVector.size(); ++i) {
		if (max_v < maxVector[i]) {
			max_v = maxVector[i];

		}
	}
	return max_v;
}

double Min_element(vector <int> minVector)
{
	double min_v = minVector[0];

	for (int i = 0; i < minVector.size(); ++i) {
		if (min_v > minVector[i]) {
			min_v = minVector[i];

		}
	}
	return min_v;
}

int main(int argc, char* argv[]) {

	vector<int> v{};

	ifstream f(argv[1]);
	string line;

	while (getline(f, line))
	{
		v.push_back(stoi(line));
	}
	f.close();
	printf("%.2f\n", Percentile(90,v));
	printf("%.2f\n", Percentile(50, v));
	printf("%.2f\n", Max_element(v));
	printf("%.2f\n", Min_element(v));
	printf("%.2f\n", Average(v));

}