// Nancy Gomez
// Mavey Ma
// Israel Andrade
// Nicholas Rosas

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //exit()
#include <cmath> //pow()
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    string time, alt, vel, accel;
    double timeN, altN, velN, accelN;
    double maxAlt = 0, maxTime = 0;
    
    //OPEN SESAME, FILES!
    fin.open("data.txt");
    fout.open("apex.txt");
    
    //IN CASE FILE DOESN'T OPEN PROPERLY
    if (fin.fail())
    {
        cout << "ERROR OPENING INPUT FILE.\n";
        exit(1);
    }
    if (fout.fail())
    {
        cout << "ERROR OPENING INPUT FILE.\n";
        exit(1);
    }
    
    //EATS THE FIRST LINE OF WORDS
    fin >> time >> alt >> vel >> accel;
    //NOW, FOCUS ON THE NUMBERS
    while (fin >> timeN >> altN >> velN >> accelN)
    {
        //NOW WE CAN FIND THE TIME (SECONDS) AT WHICH THE ROCKET FALLS BACK TO EARTH
        if (altN > maxAlt)
        {
            maxAlt = altN;
            maxTime = timeN;
        }
    }//END WHILE
    
    fout << "RocketA falls back to Earth at " << maxTime << " seconds.\n";
    
    //DONE, CLOSE FILES.
    fin.close();
    fout.close();
    return 0;
}//END MAIN
