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
	string sTime, altitude, velocity, acceleration;
	double times, alts, vels, accels, firstTime, lastTime;
	int count = 0;
	
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(2);
	
	fin.open("data.txt");
	fout.open("decel.txt");
	
	
	// Eat up the headers
	fin >> sTime >> altitude >> velocity >> acceleration;

	fout << "Times where the acceleration is within\n"
		 << "65% of -9.8 [-3.4, -16.17]:\n" << endl;
	while (fin >> times >> alts >> vels >> accels){
	
		if ((accels <= -3.4) && (accels >= -16.17)){
			if (count == 0){
				firstTime = times;
			}
			if (times - (count * 10) == firstTime){
				lastTime = times;
				count++;
			}
			else{
				fout << "From " << firstTime << " to " << lastTime << endl;
				count = 1;
				firstTime = times;
			} 
		}
	}
	//if the last number in the file was the "lastTime"
	//then the "else" wont run, so I have this here for that case
	if (lastTime - ((count-1) * 10) == firstTime){ 
		fout << "From " << firstTime << " to " << lastTime << endl; 
	}
	
	fin.close();
	fout.close();

	return 0;
}
