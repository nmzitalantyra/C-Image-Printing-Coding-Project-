#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;
int main()
{
    int width = 100;
    int height = 100; // setting the dimensions of the image
    int radius = 30; // radius of the circle
    ofstream fout;   // make output file stream called fout 
    fout.open("Prob1c.ppm");

    // file headers 
    fout << "P3" << endl; // indicate that this file has color
    fout << width << " " << height << endl;
    fout << 255 << endl; // the max pixel intensity 

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = j - (width/2); // making the coordinate plane 
            int y = i - (height/2); 
            if ( (x * x + y * y) <= radius * radius) {  // the formula x^2 + y^2 = r^2
            // using <= so shade everything inside the circle
                fout << 255 << " " << 255 << " " << 0 << " "; // RGB values of yellow
            } else {
                fout << 255 << " " << 0 << " " << 0 << " "; // RGB values of red
            }
        }
        fout << endl;
    }
    
    fout.close();
    return 0;
}