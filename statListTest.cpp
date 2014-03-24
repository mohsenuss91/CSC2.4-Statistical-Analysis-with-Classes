//statListTest.cpp
//
//Created by Hunter Holder

#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string>

#include "statListImp.cpp"

using namespace std;

int main ( int argc, char *argv[] )
{
    statList *tvPtr;
    string inFileName, outFileName;
    ofstream outFile;
    ifstream inFile;
    
    tvPtr = new statList(50);
    
    //Prompt for and accept athe names of the infile and outfile.
    cout << "Enter the name of the file to be read in and the file to write to separated by a space: ";
    cin >> inFileName >> outFileName;
    cout << endl;
    //Use c_str() to convert inFileName to a C string and open it
    //as an infile stream.
    inFile.open(inFileName);
    
    //If the outfile is in use by another application, cease the program.
    if(outFile.is_open()) //test to be certain outfile is NOT open
        cout << "Error: The output file already exists and is currently in use." << endl;
    else
        if (inFile.is_open())
        {
            outFile.open(outFileName);
            cout << "****************************************************************************************************" << endl;
            //read in the infile contents to the list in sorted order
            while (inFileName != "exit"){
                //Send the infile stream to be opened and have its
                //values read into the array.
                tvPtr->insertInOrder(inFile);
                inFile.close();
                //Prompt for and read in the next infifle name.
                cout << "Enter the next inFile name. Enter 'exit' after"
                << " the last file name to exit.\n";
                cin >> inFileName;
                if (inFileName != "exit") inFile.open(inFileName);
            }
            //print the list to stdout
            tvPtr->printList(cout);
            cout << "****************************************************************************************************" << endl;
            //Call a function that will print the list in tabular form
            //and print its statistics to stdout. Author that function
            //elsewhere in this file.
            //Write the same report to the outfile.
            tvPtr->printList(outFile);
            //close both files
            outFile.close();
            std::cout<< "\n\nTask complete. Press 'return' to exit program.";
            cin.ignore();
        }
    
        else {
            cout << "Infile " << inFileName << " does not exist.\n";
            std::cout<< "\n\nPress 'return' to exit program.";
            cin.ignore();
        }
    
    cin.ignore();
    return 0;
}



