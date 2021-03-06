/**
 * @file main.c
 * @author Atlanswer (atlanswer@gmail.com)
 * @brief Main logic.
 * @version 1.0
 * @date 2020-12-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

// Standard headers
#include <stdio.h>
#include <stdlib.h>
// Custom headers
#include "customwingdi.h"
// Image filepath constant
const char OIMGPATH[] = "../res/lena512.bmp";
const char XIMGPATH[] = "../res/output.bmp";

int main(void) {
    /// Start CPU cycle counter.
    TSCL = 1;

    /// Read the original image.
    BITMAP oimg = bmRead(OIMGPATH);
    printf("[main] Read image completed.\n");

    /// Process images.
    BITMAP ximg = StretchBlt(&oimg, 1.5);
    printf("[main] Image interpolation completed.\n");

    /// Save the image.
    bmSave(&ximg, XIMGPATH);
    printf("[main] The image was saved.\n");

    /// Destory the image.
    bmDel(&oimg);
    bmDel(&ximg);

    printf("[main] Program exited.\n");
	return EXIT_SUCCESS;
}
