#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "pixel.h"

void average_colors(std::vector<Pixel> &pixel_list);
void flip_vertically(std::vector<Pixel> &pixel_list);

int main(int argc, char *argv[]){
    //checking if user input was given
    if (argc < 2){
        printf("Error: Missing file number\n");
        return 1;
    }

    //vector to store all pixels from pixel.dat (pixel object for cleaner look)
    std::vector<Pixel> pixel_list;
    Pixel p;
   
    //reading user input file
    std::ifstream input;   
    input.open(argv[1], std::ios::in);

    //single string from user input file
    std::string pixel;
    
    //substring from pixel string 
    std::string substringPixel;

    //while loop that goes through user input file line by line
    while(std::getline(input, pixel)){
        int start = 0, end = 0;

        //for loop that brakes up pixel line and saves substring to respective data type
        for(int count = 0; count < 5; count++){

            //sets start and end of substring (parsing pixel string)
            end = pixel.find(",", start);
            substringPixel = pixel.substr(start, end-start);

            //assigns substring to respective pixel value
            switch (count){
                case 0: p.x = std::stoi(substringPixel); break;
                case 1: p.y = std::stoi(substringPixel); break;
                case 2: p.r = std::stof(substringPixel); break;
                case 3: p.g = std::stof(substringPixel); break;
                case 4: p.b = std::stof(substringPixel); break;   
            }
            start = end + 1;
        }   
        //pushes pixel values to pixel_list vector
        pixel_list.push_back(p);
    }

    //prints pixel_list size to verify correct assignment
    std::cout << "Successfully loaded " << pixel_list.size() << " pixels.\n";

    //calling functions
    average_colors(pixel_list);
    flip_vertically(pixel_list);

    /*
    for(int i = 130816; i < pixel_list.size(); i++){
        std::cout << "Index [" << i << "] -> "
        << "r-value: " << pixel_list[i].r << "  "
        << "g-value: " << pixel_list[i].g << "  "
        << "b-value: " << pixel_list[i].b << "\n";
    }
    */

    return 0;
}

//average average of the r,g,b values individually
void average_colors(std::vector<Pixel> &pixel_list){
    float sumR = 0, sumG = 0, sumB = 0;    

    //for loop adding all the r, g, b sums
    for(int i = 0; i < pixel_list.size(); i++){
        sumR += pixel_list[i].r;
        sumG += pixel_list[i].g;
        sumB += pixel_list[i].b;
    }

    //divides by list size to calcuate average
    std::cout << "\nAverage R-value: " << sumR/(float)pixel_list.size() << "\n";
    std::cout << "Average G-value: " << sumG/(float)pixel_list.size() << "\n";
    std::cout << "Average B-value: " << sumB/(float)pixel_list.size() << "\n\n";
}

//flips all pixels vertically
void flip_vertically(std::vector<Pixel> &pixel_list){
    int max = 256;
    float tempR, tempG, tempB;

    //double for loop that goes through each x row, one y pixel at a time
    for(int x = 0; x < 512; x++){
        for(int y = 0; y < max/2; y++){
            int top = (x * max) + y;
            int bottom = (x * max) + (max - 1 - y);

            //saves top pixel to temp
            //reassigns top to bottom pixel value
            //reassigns bottom to top pixel value
            //rinse and repeat for r, g ,b

            tempR = pixel_list[top].r;
            pixel_list[top].r = pixel_list[bottom].r;
            pixel_list[bottom].r = tempR;

            tempG = pixel_list[top].g;
            pixel_list[top].g = pixel_list[bottom].g;
            pixel_list[bottom].g = tempG;

            tempB = pixel_list[top].b;
            pixel_list[top].b = pixel_list[bottom].b;
            pixel_list[bottom].b = tempB;
        }
    }

    //creating flipped.dat file
    std::ofstream flippedPixel;
    flippedPixel.open("flipped.dat", std::ios::out);

    //while loop saving modified pixels.dat file to new flipped.dat file
    while(flippedPixel.is_open()){
        for (int i = 0; i < pixel_list.size(); i++) {
            //writing flipped pixel to match original pixel.dat file
            flippedPixel << pixel_list[i].x << "," 
                         << pixel_list[i].y << "," 
                         << pixel_list[i].r << "," 
                         << pixel_list[i].g << "," 
                         << pixel_list[i].b << "\n";
        }
        flippedPixel.close();
        std::cout << "Successfully saved flipped pixels to flipped.dat\n";
    }
}