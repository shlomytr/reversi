//
// Created by Shlomy and Omer
//

#ifndef EX1_BOARD_H
#define EX1_BOARD_H


#include <iostream>

using namespace std;


class Board {
public:

    enum Color {
        white = 'o', black = 'x', empty = ' '
    };

    /**
     * @name : Board
     * @parameters : size
     * @return : the function creates new instance of Board in size of 'size'
     **/
    Board(int size);
    /**
     * @name : Board
     * @parameters : no parameters
     * @return : The board destructor.
     **/
    ~Board();

    /**
     * @name : Board (copy constructor)
     * @parameters : A board object
     * @return : the function creates new instance of Board and deep copy it from the parameter
     **/

    Board (const Board &other);

    /**
     * @name : addToBTiles
     * @parameters : The amount to add to the number of the black tiles in the board
     * @return : the function adds i to bTiles
     **/

    void addToBTiles(int i);

    /**
     * @name : addToWTiles
     * @parameters : The amount to add to the number of the white tiles in the board
     * @return : the function adds i to wTiles
     **/

    void addToWTiles(int i);

    /**
     * @name : getBTiles
     * @parameters : no parameters
     * @return : the function returns the number of the black tiles in the board
     **/

    int getBTiles();

    /**
     * @name : getWTiles
     * @parameters : no parameters
     * @return : the function returns the number of the white tiles in the board
     **/

    int getWTiles();

    /**
     * @name : isFull
     * @parameters : no parameters
     * @return : the function returns true if the board is full, otherwise returns false
     **/

    bool isFull();

    /**
     * @name : getCell
     * @parameters : the index of the cell that is required
     * @return : the value of the cell in the board ('x' or 'o')
     **/

    char getCell(int i, int j)const;

    /**
     * @name : getPosCell
     * @parameters : the index of the cell that is required
     * @return : the function returns true if a tile could be placed in the cell
     **/

    bool getPosCell(int i, int j)const;

    /**
     * @name : setCell
     * @parameters : the index of the cell and the value that we want to change
     * @return : the function puts the value in the cell
     **/

    void setCell(int i, int j, Color value);

    /**
     * @name : setPosCell
     * @parameters : the index of the cell and the information whether we can put a tile there ot not
     * @return : the function sets true if we can put a tile in the board or false otherwise
     **/

    void setPosCell(int i, int j, bool value);

    /**
     * @name : getBoardSize
     * @parameters : no parameters
     * @return : the function returns the size of the board
     **/

    int getBoardSize() const;

protected:
    int boardSize;
    int bTiles, wTiles ;
    Color** arr;
    bool** posArray;
};


#endif //EX1_BOARD_H
