// Name: Sarah Villegas 
// October 22,2015
// FileIO B 

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std; 


int main(){

    ifstream fin;
    ofstream fout; 
    char fileName [12]; 
    string firstName, lastName, winner;
    double score1, score2, score3, score4, score5, score6;  
    double bestavg = 0, avg = 0; 
    
    cout << "Please enter the file name you want to open: ";
    cin >> fileName;
    
    fin.open(fileName);
    
    if(fin.fail()){
    
    cout << "File failed to open " << endl;
    exit(1);
    
    }
    fout.open("results.txt");
    
    while (fin >> firstName >> lastName >> score1 >> score2 >> score3   >> score4 >> score5 >> score6){
    
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(2);
        fout.setf(ios::left);
        
        avg = (score1 + score2 + score3 + score4 + score5 + score6) / 6.0;
    
        if(bestavg < avg ){
            bestavg = avg; 
            winner = firstName + " " + lastName;
        }
        fout << setw(12) << firstName << setw(12) << lastName << setw(12) << score1 << setw(8) << score2 << setw(8) << score3 << setw(8) << score4 << setw(8) << score5 << setw(8) << score6 << setw(8) << endl;
    }
    
    
    
    fout << "Highest Score: " << winner << endl; 

    fin.close();
    fout.close();

    return 0;
}






