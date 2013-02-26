#include <vector>
using namespace std;
#include <stdlib.h>
#include <stdio.h>

class fileIOclass
{
public:
	static vector<int> InVectorInt(string s);
	static void OutVectorInt(string s,vector<int> v);

	static vector<double> InVectorDouble(string s);
	static void OutVectorDouble(string s,vector<double> v);

	static vector<string> InVectorString(string s);
	static void OutVectorString(string s,vector<string> v);

	static vector<vector<int> > InVectorSInt(string s);
	static void OutVectorSInt(string s,vector<vector<int> > v, bool secondDim);

	static vector<vector<double> > InVectorSDouble(string s);
	static void OutVectorSDouble(string s,vector<vector<double> > v, bool scondDim);


	static vector<vector<int> > InVectorSInt(string s, int dim);

	static vector<vector<double> > InVectorSDouble(string s,int dim);


};