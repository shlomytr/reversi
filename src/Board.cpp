//
// Created by Shlomy and Omer
//
#include <iostream>

using namespace std;

#include "../include/Board.h"


Board::Board() {
    wTiles=bTiles=2;
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++)
            array[i][j] = ' ';
    const int mid = boardSize/2;
    array[mid][mid] = array[mid-1][mid-1] = 'o';
    array[mid-1][mid] = array[mid][mid-1] = 'x';
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
    for (int i = 1; i < boardSize + 1; i++)
        cout << i << " | ";
    cout << "\n----------------------------------\n";
    for (int i = 0; i < boardSize; i++, row++) {
        cout << row << "| ";
        for (int j = 0; j < boardSize; j++)
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
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++)
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

int Board::getBoardSize() {
    return boardSize;
}