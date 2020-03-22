#include <stdio.h> 
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define EPSILON    (1.0E-8)

using namespace std;


int main(int argc,char* argv[]) 
{ 
    
    double intrvlAvgCustomer[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    string path = argv[1];

    for(int i = 0; i < 5; ++i ){
        
        ifstream f (path + "/Cash" + to_string(i+1) + ".txt");
        string line;
        int j = 0;

        while ( getline (f,line) )
        {

            intrvlAvgCustomer[j] += stof(line);
            j++;
        }

        f.close();
    }

    double maxAvgCustomer = intrvlAvgCustomer[0];
    int  maxIntrvl = 1;

    for(int i = 1; i < 16; ++i)
    {   
        //cout<<intrvlAvgCustomer[i]<<endl;
        if (maxAvgCustomer < intrvlAvgCustomer[i]) {
            maxAvgCustomer = intrvlAvgCustomer[i];
            maxIntrvl = i + 1;
        }
    }

    cout<< maxIntrvl<<endl;
    return 0; 
} 
