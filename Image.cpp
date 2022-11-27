/*
 *    Deepak Krishnaa Govindarajan
 *    Marcus Naess
 *    Soobin Rho
 *    Fall, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw: A Container class for handling images.
 */

#include <iostream> // Required for cout
#include <string>   // Required for string
#include "Image.h"
#include <fstream>

using namespace std;

// Implement the Image constructor here
Image::Image()
{
    rows = 0;
    cols = 0;
    pixels = vector<int>();
    maxValue = 0;
}

Image::Image(const string &filename)
{
    ifstream file(filename);

    // Check if file exists
    if (!file)
    {
        cout << "File does not exist" << endl;
        // Calling the default constructor to create an empty image
        Image();
        return;
    }

    // Read the file and get the rows, cols, and max value
    string line;

    while (file >> line)
    {
        if (line == "P2")
        {
            file >> cols;
            file >> rows;
            file >> maxValue;
            break;
        }
    }

    // Read the pixels
    int pixel;
    while (file >> pixel)
    {
        pixels.push_back(pixel);
    }

    file.close();
}

Image::Image(const int &valueRGB, const int &rows, const int &cols, const int &maxValue)
{
    this->rows = rows;
    this->cols = cols;
    this->maxValue = maxValue;

    for (int i = 0; i < rows * cols; i++)
    {
        pixels.push_back(valueRGB);
    }
}

Image::Image(const vector<int> pixels, const int &rows, const int &cols)
{
    this->rows =rows;
    this->cols = cols;
    this->pixels = pixels;
    maxValue = 255;
}

Image::Image(const Image &imageCopy)
{
    rows = imageCopy.getRows();
    cols = imageCopy.getCols();
    pixels = imageCopy.getPixels();
    maxValue = imageCopy.getMaxValue();
}

Image::~Image()
{
    // Nothing to do here
}

// Implement the getPixels() method here
vector<int> Image::getPixels() const
{
    return pixels;
}

// Implement the getRows() method here
int Image::getRows() const
{
    return rows;
}

// Implement the getCols() method here
int Image::getCols() const
{
    return cols;
}

// Implement the getMaxValue() method here
int Image::getMaxValue() const
{
    return maxValue;
}

// Implement the setPixels() method here
void Image::setPixels(const vector<int> &pixels)
{
    this->pixels = pixels;
}

// Implement the setRows() method here
void Image::setRows(const int &rows)
{
    this->rows = rows;
}

// Implement the setCols() method here
void Image::setCols(const int &cols)
{
    this->cols = cols;
}

// Implement the setMaxValue() method here
void Image::setMaxValue(const int &maxValue)
{
    this->maxValue = maxValue;
}

// Implement the clone() helper function here
Image clone(const Image &image) 
{
    Image copy;
    copy.setRows(image.getRows());
    copy.setCols(image.getCols());
    copy.setPixels(image.getPixels());
    copy.setMaxValue(image.getMaxValue());
    
    return copy;
}

// Implement the getSubset() helper function here
Image getSubset(const Image &image, int top, int bottom, int left, int right) 
{
    
}

// Implement the getSmoothedSubset() helper function here
Image getSmoothedSubset(const Image &image, const int &smoothValue) 
{
    
}

// Implement the printHistogram() helper function here
void printHistogram(const Image &image)
{
    
}

// Implement the setBrightness() helper function here
void setBrightness(Image &image, const int &gain, const int &bias)
{
    
}