#include <vector>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <string>

struct TestInt
{
	int elem;
	TestInt()
	{

	};
	static void initOne(FILE* fp,TestInt &t)
	{
		fscanf(fp,"%d",&t.elem);
	};
	static void printOne(FILE* fp, TestInt t)
	{
		fprintf(fp,"%d",t.elem);
	};
};



class fileIOclass
{
public:
	template<typename T>
	static vector<T> InVector(string s)
	{
		vector<T> result;
		FILE* fp;
		fp=fopen(s.c_str(),"r");
		int size;
		fscanf(fp,"%d\n",&size);
		T temt;
		result.resize(size,temt);
		for (int i=0;i<size;i++)
		{
			T::initOne(fp,result[i]);
			fscanf(fp,"\n");
		}

		fclose(fp);

		return result;
	};

	template<typename T>
	static void OutVector(string s,vector<T> v)
	{
		FILE* fp;
		fp=fopen(s.c_str(),"w");
		int size(v.size());
		fprintf(fp,"%d\n",size);

		for (int i=0;i<size;i++)
		{
			T::printOne(fp,v[i]);
			fprintf(fp,"\n");
		}

		fclose(fp);
	}

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

	template<typename T>
	static void CombineFromFileList(string s,string extra,string out)
	{
		vector<string> files;
		vector<T> result;
		result.clear();
		files=InVectorString(s);
		for (int i=0;i<files.size();i++)
		{
			vector<T> temp;
			temp=InVector<T>(files[i]+extra);
			result.insert(result.end(),temp.begin(),temp.end());
		}
		OutVector<T>(out,result);
	};


};