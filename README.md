C++ program where we will use the string, vector, and fstream classes to read/write files and store data.

# pixel.h header
Created a struct in a header file called pixel.h with the following struct.
```
struct _pixel
{
  float r;
  float g;
  float b;
  int x;
  int y;
};
typedef struct _pixel Pixel;
```
The values r,g,b contain 0.0 to 1.0 values to map into RGB color space.  The values x, y indicate the x and y pixel location on the screen.

# Vector Creation
Create a vector called pixel_list which will store every pixel read in the from the file.
```
std::vector<Pixel> pixel_list;
```

# User Input to read file
Take a string from the command line for the file to read.  The file for input is called pixels.dat and located in this repository.  The format for this file is given as
```
0,0,0.4395700779928904,0.9343941844026555,0.11956329425119616
0,1,0.8524808236654031,0.8812383901083097,0.22561409174532054
0,2,0.2554656078947496,0.6427251273450297,0.7846795291785428
0,3,0.8167976025632453,0.8285117476156731,0.7443373845648841
```
where each value is comma separated.  The first value is the x location, the second value is the y location, third is r value, fourth the g value, and last is the b value.  The x-length for this data is 512 and the y-length is 256.  In total, there are 131072 pixels to be read in. 

# Average color function and Flipped function
The first function will calculate the average of the r,g,b values individually. That is, average all r colors and give a result, all g colors and give a result, and all b colors and give a result.
The definition for this function is
```
void average_colors(std::vector<Pixel> &pixel_list);
```

The second function will flip all pixels vertically. For example, in the x-direction, pixel 512 should become pixel 0 and pixel 0 should become pixel 512. No modification is done to the x and y values; only the rgb values. The function definition is
```
void flip_vertically(std::vector<Pixel> &pixel_list);
```

# Saving modified pixel list to new file
After flipping the image, the new pixel list is saved to a file called flipped.dat. Output the individual x, y, r, g, b values in the same format as the input file. The flipped.dat file looks like this, but with the modified RGB values: 
```
0,0, [sorted R value], [sorted G value], [sorted B value]
0,1, [sorted R value], [sorted G value], [sorted B value]
0,2, [sorted R value], [sorted G value], [sorted B value]
0,3, [sorted R value], [sorted G value], [sorted B value]
```
