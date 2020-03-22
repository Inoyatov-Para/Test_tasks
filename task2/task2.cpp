
#include <stdio.h> 
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

#define EPSILON    (1.0E-8)

int rotate (int x1, int y1, int x2, int y2, int _x, int _y){
  return (x2-x1)*(_y-y2)-(y2-y1)*(_x-x1);
}


bool isEqual(double a, double b)
{
    return fabs(a - b) < EPSILON;
}

void pointPos(double x[4], double y[4], double _x, double _y)
{

    int rot;
    bool inLine;

  for (int i = 0; i < 4; i++){
        if ( isEqual(x[i], _x) && isEqual(y[i], _y) ) {
            cout << 0 << endl;
            return;
        }

      rot = rotate(x[i], y[i], x[(i+1)%4], y[(i+1)%4], _x, _y);
      
      if  (rot > 0) {
          cout << 3 << endl;
          return ;
      }

    if (rot == 0) {
        inLine = true;
    }
  }

  if (inLine) 
    cout << 1 << endl;
  else
    cout << 2 << endl;
  
}   

int main(int argc,char* argv[]) 
{ 
    double x[4], y[4];
    int i = 0, j;

    ifstream coords (argv[1]);
    string line;

    while ( getline (coords,line) )
    {
        string s;
        j = 0;

        istringstream f(line);

        while (getline(f, s, ' ')) {
            if (j == 0) 
                x[i] = stof(s);
            else
                y[i] = stof(s);
            j++;
        }
        i++;
    }

    coords.close();

    i = 0;

    ifstream points (argv[2]);

    while ( getline (points,line) )
    {
        string s;
        
        j = 0;
        double _x, _y;
        
        istringstream f(line);

        while (getline(f, s, ' ')) {
            if (j == 0) 
                _x = stof(s);
            else
                _y = stof(s);
            j++;
        }

        pointPos(x, y, _x, _y);
    }

    points.close();

    return 0; 
} 
