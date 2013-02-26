#include "FileInOut.h"

#include <Windows.h>
#include <direct.h>

int main()
{
	_chdir("J:\\project\\fileIO\\test");

	string fn;
	vector<int> vint;
	vector<double> vdouble;
	vector<vector<double> > vs;

	vector<string> vww;

	fn="int.txt";

	vint=fileIOclass::InVectorInt(fn);
	fileIOclass::OutVectorInt("tem.txt",vint);
	
	vdouble=fileIOclass::InVectorDouble("double.txt");
	fileIOclass::OutVectorDouble("temd.txt",vdouble);

	vs=fileIOclass::InVectorSDouble("ds.txt",32);
	fileIOclass::OutVectorSDouble("dstem.txt",vs,false);
	fileIOclass::OutVectorSDouble("dstem1.txt",vs,true);
	vs=fileIOclass::InVectorSDouble("dstem1.txt",32);

	vww=fileIOclass::InVectorString("ss.txt");
	fileIOclass::OutVectorString("sstem.txt",vww);
	getchar();
	return 0;
}