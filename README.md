README
Blake Eggemeyer 
i.linwin@gmail.com

Updated 2010-07-26 

This is the jury rigged version.

Tesseract 2.04 must be installed as it will be called via a system call.
You must alter the source code to fit the directory structure I have, it is not good, but its is very basic.

libtiff must be installed before compiling Imagemagick for the different file types to work

This code currently produces the binaries `main`, and `test` with 
	$ make all  
`main` converts the images and runs them through Tesseract, producing the OCRed output
`test` uses an edit distance algorithm to compare the output of main with known text of the same files





