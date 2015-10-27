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
    
    fin.open("data.txt");
    fout.open("stages.txt");

    string timeTitle, altitudeTitle, velocityTitle, accelerationTitle;
    double timeValue1, altitudeValue1, velocityValue1, accelerationValue1;
    double timeValue2, altitudeValue2, velocityValue2, accelerationValue2;
    double timeValue3, altitudeValue3, velocityValue3, accelerationValue3;
    double newValue1, newValue2, newValue3;
    
    int count = 0;
    
    fin >> timeTitle >> altitudeTitle >> velocityTitle >> accelerationTitle;
    //fout << left << setw(20) << timeTitle << setw(20) << altitudeTitle << setw(20) << velocityTitle << setw(20) << accelerationTitle;
   
    while(fin >> timeValue1 >> altitudeValue1 >> velocityValue1 >> accelerationValue1)
    {

        fin >> timeValue2 >> altitudeValue2 >> velocityValue2 >> accelerationValue2;
        fin >> timeValue3 >> altitudeValue3 >> velocityValue3 >> accelerationValue3;
        
        cout  << velocityValue1 << " > " << velocityValue2 << " && " << velocityValue2 << " > "  <<  velocityValue3 << endl;
        cout << endl;
        
        if((velocityValue1 > velocityValue2 && velocityValue2 > velocityValue3))
        {     
            if(newValue1 < newValue2 && newValue2 < newValue3)
            {
                count++;
            }
            
        }
        //Set these variable to the previous values to chech if the previous values where increasing
        newValue1 = velocityValue1;
        newValue2 = velocityValue2;
        newValue3 = velocityValue3;
        
    }
    fout << "The Number of stages where the velocity increases to a peak and then begins decreasing is: " << setw(2) << count;
    
    fin.close();
    fout.close();
    
	return 0;
}
