// Nancy Gomez
// Mavey Ma
// Israel Andrade
// Nicholas Rosas

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

ifstream fin;
	ofstream fout;
	string time, alt, vel, accel;
	int stage = 0;
	double t, a, v, acc, prevV = 0, nextV = 0, t2, a2, v2, acc2;

	fin.open("data.txt");
	fout.open("firing.txt");

	if(fin.fail())
	{
		cout << "Error, input file failed\n";
		exit(1);
	}
	if(fout.fail())
	{
		cout << "Error, output file failed\n";
		exit(1);
	}

	fin >> time >> alt >> vel >> accel;

	while(!fin.eof())
	{
		while(fin >> t >> a >> v >> acc)
		{

			if( (prevV < v))
			{
				stage++;
				prevV = v;
				break;
			}
			prevV = v;

		}
		if(!fin.eof())
			fout << "Stage " << stage << "'s firing point is at " << t << " seconds" << endl;

		while(fin >> t >> a >> v >> acc)
		{
			if(prevV > v)
			{
				prevV = v;
				break;
			}
			prevV = v;
		}
	}

	fin.close();
	fout.close();

	return 0;
}
