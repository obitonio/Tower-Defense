#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

// VAR
    #define SCREENX 768
    #define SCREENY 576

    #define BLOCKSIZE 48
    #define MAXTOWER 16

// SFML
    #include <SFML/Graphics.hpp>

//
    #include <iostream>
    #include <sstream>
    #include <string>
    #include <vector>
    #include <fstream>

// PRICE
    #define TCLASSICPRICE 100
    #define TCLASSIC2PRICE 300
    #define TSLOWPRICE 50
    #define DEFAULTGOLD 200

// BLOCK
    #define BLOCKGRASS  1
    #define BLOCKLAND   2
    #define BLOCKWATER  3
    #define BLOCKCASTLETOP  7
    #define BLOCKCASTLEMIDDLE   8
    #define BLOCKCASTLEBOT  9

    #define BLOCKTOWER  10
    #define BLOCKTOWERLVL2  11
    #define BLOCKTOWERSLOW 12

// WAVE EDITOR
    #define NBWAVE 10
    #define NBMOB 5
    #define NBNUMERICBOX NBWAVE*NBMOB

#endif // MAIN_H_INCLUDED
