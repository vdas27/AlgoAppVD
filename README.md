# Algo take home assesment Vivan Das
I completed question 3 for my submission. I used C for my language, since I am most familiar with C and Python
and I think that this question would most easily be solved in C since you can work with pointers.

# Blit Function
For my blitting function I decided to move through the array of pixels using two for loops, to simulate
the row column layout. If I came across a pixel that matched the color key, I would pass over to the next iteration of the for loop,
thus leaving the pixel value at that point in the dest pixel array at 0. For non color key pixels, I then find the dest coordinates by
adding the offsets into their current coordinates (provided by the for loop values). After checking if the coordinate is still in a valid
position, I added the pixel value into the dest pixel array (calculated by multiplying the column number by the width of the rows, and then 
adding the row number to that value). 

# Testing
Rather than creating tests that only involved the PixelBuffer structs, I decided to test my code visually. I created a main file
which would read an image file, blit it accordingly, and then either create or write over another image file. I added two functions, 
one which would read a P3 PPM and convert it to the src PixelBuffer, and then one which turned the dest PixelBuffer into a P3 PPM
after it had been passed through the blitting function.
For this program the functions assume that a P3 PPM file format is used for the images. The command line function works like this:
./main [source ppm file] [destination ppm file (either exists or to be created)] [Optional: offsetX] [Optional: offsetY];
I put in three images to test which I have included in this repo: simple1.ppm, simple2.ppm, and minion.ppm(a generic green
screen image I found off the internet). I also changed the colorkey value in option3.c in order to match the green of the image
I found online. I created the two simple ppm files manually, simple1 containg a blue square surrounded by green and simple2 
containing a blue and red square surrounded by green and containing a smaller green square within it. For the first simple,

I tested it by trying out the offset parameters to move it to the right by 2 pixels, and up 6 pixels with the following command:
./main simple1.ppm simple1gs.ppm 2 -6
Looking at the result, all of the green was removed, and the image was properly clipped if the offset brought it outside the frame.
For simple2 I tested it without an offset to test if the program could handle when more than one color was outside the color key,
and when the color key pixels were dispersed unconnected throughout the image. I used the following command:
./main simple2.ppm simple2gs.ppm
The results worked as expected. Some of the green did not go away because they did not match the same shade of green as the rest of the
greenscreen.

For the last image, a greenscreen of a minion found online, I tested it without offset of x + 300 and y - 400  to test how the function would 
run on larger sized arrays of pixels. I used the following command:
./main minion.ppm miniongs.ppm 300 -400
Again the results worked as expected.
All of my test images and results are in the repo.
