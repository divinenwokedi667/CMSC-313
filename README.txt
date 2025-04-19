AUTHORING:
Divine Nwokedi,
University of Maryland Baltimore County
4/19/2025

PURPOSE OF SOFTWARE:
This program allows the user to create matrices utilized
in linear algebra in a C++ or C environment and perform
basic matrix operations including addition, multiplication,
and scalar multiplication.

FILES:
MatrixLibrary.cpp: Matrix program in a C++ environment
MatrixLibrary.c: Matrix program in a C environment

BUILD INSTRUCTIONS:
For MatrixLibrary.cpp:
Use the command g++ -o MatrixLibraryPlus.out MatrixLibrary.cpp
Then the command MatrixLibraryPlus.out to run
For MatrixLibrary.c:
Use the command gcc -o MatrixLibraryC.out MatrixLibrary.c
Then the command MatrixLibraryC.out to run

TESTING METHODOLOGY:
To change the matrices you would like to calculate:
The main function of both program files contains the creation of the
matrices. The Matrix constructor takes the row # and column # as parameters,
and you set the number in each position of the matrices using the row, column,
and desired value. Each program also demonstrates how to utilize the matrix
functions, including transpose and matrix multiplication.