/* Homework 7
 * Read in file
 * convert to grayscale
 * convert to ascii
 * read out ascii
 * Jon Genetti
 * 4/18/2021
 * CS 201
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
#include <cmath>
#include <vector>
using std::vector;


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
    if (line.size() < 2 or (line.at(0) != 'P' and line.at(1) != '3')) {
        cout << "Cannot find P3 magic number" << endl;
        exit(2);
    } else{
        cout << "PMM (text)" << endl;
    }

    //Ignore Comments
    getline(fin,line);
    if (!fin){
        cout << "Error reading file" << endl;
        exit(3);
    }
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
    //Print resolution values
    cout << "Image Size: " << resx << "x" << resy << endl;
    cout << "Maximum Value: " << maxval << endl;

    //RGB loop by resx * resy
    int rval, gval, bval, inty, div_inty;
    double y;
    //char ascii_char[] = "$@#%&HO?!*^;:,. ";
    //characters to choose from
    string ascii_char = "$@#%&HO?!*^;:,. ";
    vector<int> image;


    //loop resx * resy
    for (int i = 1; i <= (resx * resy); i++) {
        fin >> rval >> gval >> bval;
        if (!fin) {
            cout << "Error reading " << infile << endl;
            if (fin.eof()) {
                cout << "Reached end of file" << endl;
            }
            exit(4);
        }
        //save rbg values to vector - change to struct pixel / class pixel
        image.push_back(rval);
        image.push_back(gval);
        image.push_back(bval);
        // Y = 0.2126R + 0.7152G + 0.0722B from HW7
        y = 0.2126*rval + 0.7152*gval + 0.0722*bval;
        //test if y is in bounds
        if (y < 0 or y > 255){
            cout << "Error, y value out of bounds" << endl;
            exit(5);
        }
        // convert y into integer
        inty = (int) round(y);
        if (inty < 0 or inty > 255){
            cout << "Error, y value out of bounds" << endl;
            exit(5);
        }
        // divide by 16
        div_inty = inty / 16;
        if (div_inty < 0 or div_inty > 15){
            cout << "Error, y value out of bounds" << endl;
            exit(5);
        }
        //Print raw data
        //cout << rval << " " << gval << " " << bval << " = " << y << " = " << inty;
        //cout << " = " << div_inty << endl;
        cout << ascii_char[div_inty];
        if (i % resx == 0) cout << endl;
    }


    cout << "Program Finished" << endl;
    return 0;
}
