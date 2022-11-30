/*
 *    Deepak Krishnaa Govindarajan
 *    Marcus Naess
 *    Soobin Rho
 *    Fall, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw: A Container class for handling images.
 */

#include "Image.h"
using namespace std;

int main() {

    // ----------------------------------------------------------------
    // 1. Create a constant image and print a histogram of the image
    // ----------------------------------------------------------------
    const int CONSTANT_COLOR {13};
    Image imageGrey {CONSTANT_COLOR};
    imageGrey.printHistogram();

    // Print a whitespace for better readability
    cout<<'\n';

    // ----------------------------------------------------------------
    // 2. Create a wedge image and print a histogram of the image
    // ----------------------------------------------------------------
    Image imageGradient {};
    imageGradient.printHistogram();

    // ----------------------------------------------------------------
    // 3. Save the example image files
    // ----------------------------------------------------------------
    pgmSaveAsFile(imageGrey,"imageGrey.pgm");
    pgmSaveAsFile(imageGradient,"imageGradient.pgm");

    // ----------------------------------------------------------------
    // 4. Initiate an Image instance using an existing pgm file
    // ----------------------------------------------------------------
    Image imageFromFile {"imageGradient.pgm"};

    // ----------------------------------------------------------------
    // 5. Adjust brightness and then save as a new file
    // ----------------------------------------------------------------
    imageFromFile.setBrightness(1,-5);
    pgmSaveAsFile(imageFromFile,"imageGradientAdjusted.pgm");

    Image test;
    std::ifstream file {"imageGradient.pgm",std::ios_base::binary};
    if (!file) std::cout<<"[ERROR] Can't open the file.\n";

    // Read the color values from the file
    file>>test;

    cout<<test;


    // Return 0 to signal success
    return 0;
}
