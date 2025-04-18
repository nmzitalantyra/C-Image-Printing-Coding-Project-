#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;
int main()
{
    int width = 100;
    int height = 100; // setting the dimensions of the image
    int radius = 30; // radius  given
    ofstream fout;   // make output file stream called fout 
    fout.open("Prob1b.ppm");

    // file headers 
    fout << "P2" << endl; // P2 means its a pgm -- > no colors 
    fout << width << " " << height << endl;
    fout << 255 << endl; // the max pixel intensity 

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = j - (width/2); // making the coordinate plane 
            int y = i - (height/2); 
            if ( (x * x + y * y) < radius * radius) {  // the formula x^2 + y^2 = r^2
            // using <= so shade everything inside the circle
                fout << 255 <<  " "; // RGB value of white
            } else {
                fout << 0 <<  " "; // RGB value of black
            }
        }
        fout << endl;
    }
    
    fout.close();
    return 0;
}