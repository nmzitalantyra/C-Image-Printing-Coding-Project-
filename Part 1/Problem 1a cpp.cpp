#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
    int width = 100;
    int height = 100; // setting the sides of the box

    int side_length = 50; // setting the side of the inner box 
    ofstream fout;  // create a output file stream to put the image in 
    fout.open("Prob1a.pgm");

    // file headers 
    fout << "P2" << endl; // indication of a pgm file 
    fout << width << " " << height << endl;
    fout << 255 << endl; // the max pixel intensity 

    for( int i = 0 ; i < height ; i++ )
    {
        for( int j = 0 ; j < width ; j++)
        {
            int x = j - (width/2);
            int y = i - (height/2);
            if((x > (-side_length)/2) && (x <(side_length)/2) && (y > (-side_length)/2) && (y < (side_length)/2 )) 
            // coordinates with limit the square would be somthing like -
            // -25 < --------> 25 for the x and y axis , making the limit for the shaded square in the middle 
            {
                fout << 0  << " "; // output the black part
            }
            else
            {
                fout << 225 << " "; // output the white background 
            }
            
        }
        fout << endl;
    }
    fout.close();

}

