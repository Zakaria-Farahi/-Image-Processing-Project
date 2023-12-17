# # Image Processing Project

This project is a simple image processing application implemented in C. It provides functionalities to create, initialize, and manipulate RGB images. Users can create an image with a specified width, height, and resolution, initialize it randomly, from user input, or from a file, and extract a specific color component from the original image.

# Getting Started
To use this application, follow the steps below:

Clone the repository:

git clone <repository_url>

Navigate to the project directory:

cd <project_directory>

# Compile the source code:

gcc main.c -o image_processing
Run the executable:
./image_processing

# Usage
Enter the width, height, and resolution of the image when prompted.

Choose a method to initialize the image:

Enter '1' for random initialization.
Enter '2' to input RGB values manually.
Enter '3' to load an image from a file (e.g., "data.ppm").
If you choose the manual input method, provide RGB values for each pixel when prompted.

The program will then extract the specified color component ('r', 'g', or 'b') and display the processed image.

# Functions
 - RGBImage createImage(int width, int height, int resolution)
Creates an RGB image with the specified width, height, and resolution.

 - void initializeRandom(RGBImage *image)
Initializes the image with random RGB values.

 - void initializeFromInput(RGBImage *image)
Allows the user to input RGB values manually for each pixel.

 - void initializeFromFile(RGBImage *image, const char *filename)
Loads an image from a file with the given filename.

 - void extractComponent(RGBImage *input, RGBImage *output, char component)
Extracts a specific color component ('r', 'g', or 'b') from the input image and stores it in the output image.

# Example

Enter width, height, and resolution: 3 3 1
What method do you choose?
1 - Random elements
2 - From Input
3 - From File
1
Extracting the red component...
Processed Image:
255 0 0
0 255 0
0 0 255

# Note

The input file for the 'initializeFromFile' function should be in the PPM format.
The application only supports single-byte resolution (e.g., resolution = 1).
Choose 'r', 'g', or 'b' when extracting a color component.
