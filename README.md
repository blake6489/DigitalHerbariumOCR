README
Blake Eggemeyer 
i.linwin@gmail.com

Updated 2010-08-27 

This is the jury rigged version.

This project is not meant to be portable. It is meant to run on the TACC Ranger computer (and my home computer for testing).  Good luck compiling it yourself.  

Tesseract 2.04 should be downloaded and compiled from source. Line 35 of the main.cpp should be changed to reflect the location of the binarys, along with the TESSDATA_PREFIX.

Imagemagick needs to be compiled and installed from source, and the paths in main.cpp changed.  libtiff must be installed before compiling Imagemagick for the different file types to work.

This code currently produces the binary `main` for either Ranger, or MY home enviroment based on the target given to the make file, I suggest compiling for Ranger if you ar not me.
	$ make home  
`main` converts the images in their original directory (you must have write permissions) and runs them through Tesseract, producing the OCRed output in the specified directory

run the following command on Ranger to make `main` work correctly (you may need to change the path names)
	$TESSDATA_PREFIX=$HOME/tesseract-2.04/
	





