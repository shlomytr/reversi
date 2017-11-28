//
// Created by Shlomy Trajber
// ID - 305626962
//
#include <iostream>

using namespace std;

#include "Board.h"


Board::Board() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            array[i][j] = ' ';
    array[3][3] = array[4][4] = 'o';
    array[3][4] = array[4][3] = 'x';
}

Board::Board(const Board &other) {
    this->bTiles=other.bTiles;
    this->wTiles=other.wTiles;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++){
            array[i][j]=other.getCell(i,j);
            posArray[i][j] = other.getPosCell(i,j);
        }

}

void Board::printBoard() {
    int row = 1;
    cout << " | ";
    for (int i = 1; i < 9; i++)
        cout << i << " | ";
    cout << "\n----------------------------------\n";
    for (int i = 0; i < 8; i++, row++) {
        cout << row << "| ";
        for (int j = 0; j < 8; j++)
            cout << array[i][j] << " | ";
        cout << "\n----------------------------------\n";
    }

}

int Board::getBTiles() {
    return bTiles;
}

int Board::getWTiles() {
    return wTiles;
}

void Board::addToBTiles(int i) {
    bTiles += i;
}

void Board::addToWTiles(int i) {
    wTiles += i;
}

bool Board::isFull() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (array[i][j] == ' ')
                return false;
    return true;
}


char Board::getCell(int i, int j)const {
    return array[i][j];
}

bool Board::getPosCell(int i, int j)const {
    return posArray[i][j];
}

void Board::setPosCell(int i, int j, bool value) {
    posArray[i][j] = value;
}

void Board::setCell(int i, int j, char value) {
    array[i][j] = value;
}

















