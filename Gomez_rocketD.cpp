// Nancy Gomez
// Mavey Ma
// Israel Andrade
// Nicholas Rosas

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main(){

	ifstream fin;
	ofstream fout;
	string time, altitude, velocity, acceleration;
	double times, alts, vels, accels;
	
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.setf(ios::right);
	fout.precision(4);
	
	fin.open("data.txt");
	fout.open("decel.txt");
	
	
	// Eat up the headers
	fin >> time >> altitude >> velocity >> acceleration;

	fout << "Times where the acceleration is within\n"
		 << "65% of -9.8 [-3.4, -16.17]:\n" << endl;
	while (fin >> times >> alts >> vels >> accels){
	
		if ((accels <= -3.4) && (accels >= -16.17)){
			fout << setw(10) << times << endl;
		}
	}
	
	fin.close();
	fout.close();

	return 0;
}
