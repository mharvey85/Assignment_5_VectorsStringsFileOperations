#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include "pixel.h"

int main(){
    //vector to store all pixels from pixel.dat
    std::vector<Pixel> pixel_list;

    //pixel object
    Pixel p;
   
    //reading pixel.dat file
    std::ifstream input;   
    input.open("pixels.dat", std::ios::in);

    //single string from pixel.dat file
    std::string pixel;
    
    //substring from pixel string 
    std::string substringPixel;

    //while loop that goes through file lines of 'pixel.dat'
    while(std::getline(input, pixel)){
        int start = 0;
        int end;

        //for loop that brakes up pixel line and saves substring to respective data type
        for(int count = 0; count < 5; count++){
            end = pixel.find(",", start);
            substringPixel = pixel.substr(start, end-start);

            switch (count){
                case 0:
                    p.x = std::stoi(substringPixel);
                    break;
                case 1:
                    p.y = std::stoi(substringPixel);
                    break;
                case 2:
                    p.r = std::stof(substringPixel);
                    break;
                case 3:
                    p.g = std::stof(substringPixel);
                    break;
                case 4:
                    p.b = std::stof(substringPixel);
                    break;   
            }
            start = end + 1;
        }
        pixel_list.push_back(p);
    }
    std::cout << "Successfully loaded " << pixel_list.size() << " pixels.\n";
    return 0;
}