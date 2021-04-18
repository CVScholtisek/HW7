/* Homework 7
 * Read in file
 * convert to grayscale
 * convert to ascii
 * read out ascii
 */

/*
P3
3 2
255
# The part above is the header
# "P3" means this is a RGB color image in ASCII
# "3 2" is the width and height of the image in pixels
# "255" is the maximum value for each color
# The part below is image data: RGB triplets
255 0 0 # red
0 255 0 # green
0 0 255 # blue
255 255 0 # yellow
255 255 255 # white
0 0 0 # black
*/

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;

int main() {
    std::cout << "Convert PPM to Ascii" << std::endl;

    //open file
    string infile = "parrot.ppm";
    ifstream fin(infile);
    if (!fin){
        cout << "Error opening " << infile << endl;
        exit(1);
    }
    cout << infile << " successfully opened" << endl;

    //read "magic number"
    string line;
    getline(fin, line);
    if (line[0] == 'P' and line[1] == '3'){
        cout << "PPM (text)" << endl;
    } else{
        cout << "Cannot find P3 magic number" << endl;
        exit(2);
    }

    //Ignore Comments
    getline(fin,line);
    if (line[0] == '#'){
        cout << "Ignoring comment" << endl;
    }

    //Resolution
    int resx, resy, maxval;
    fin >> resx >> resy >> maxval;
    if (!fin){
        cout << "Error reading " << infile << endl;
        exit(3);
    }
    cout << "Image Size: " << resx << "x" << resy << endl;
    cout << "Maximum Value: " << maxval << endl;

    //RGB loop 80x80
    int rval, gval, bval;
    for (int i = 0; i < (resx * resy); i++) {
        fin >> rval >> gval >> bval;
        if (!fin) {
            cout << "Error reading " << infile << endl;
            exit(4);
        }
        cout << rval << " " << gval << " " << bval << " " << endl;
    }
    cout << "Program Finished" << endl;
    return 0;
}
