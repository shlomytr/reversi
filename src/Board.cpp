//
// Created by Shlomy and Omer
//
#include <iostream>

using namespace std;

#include "../include/Board.h"


Board::Board(int size) {
    boardSize = size;
    wTiles=bTiles=2;
    arr = new Color *[boardSize];
    posArray = new bool *[boardSize];
    for (int i = 0; i < boardSize; i++)
    {
        arr[i] = new Color[boardSize];
        posArray[i] = new bool [boardSize];
    }

    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++)
            arr[i][j] = empty;

    const int mid = boardSize/2;
    arr[mid][mid] = arr[mid-1][mid-1] = white;
    arr[mid-1][mid] = arr[mid][mid-1] = black;
}

Board::~Board(){
    for (int i = 0; i < boardSize; i++) {
        delete[] arr[i];
        delete[] posArray[i];
    }
    delete[] arr;
    delete[] posArray;
}

Board::Board(const Board &other) {
    boardSize = other.getBoardSize();
    arr = new Color *[boardSize];
    posArray = new bool *[boardSize];
    for (int i = 0; i < boardSize; i++)
    {
        arr[i] = new Color[boardSize];
        posArray[i] = new bool [boardSize];
    }
    this->bTiles=other.bTiles;
    this->wTiles=other.wTiles;
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++){
            if(other.getCell(i,j) == white)
                arr[i][j] = white;
            else if(other.getCell(i,j) == black)
                arr[i][j] = black;
            else
                arr[i][j] = empty;
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
            cout << (char)arr[i][j] << " | ";
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
            if (arr[i][j] == empty)
                return false;
    return true;
}


char Board::getCell(int i, int j)const {
    return arr[i][j];
}

bool Board::getPosCell(int i, int j)const {
    return posArray[i][j];
}

void Board::setPosCell(int i, int j, bool value) {
    posArray[i][j] = value;
}

void Board::setCell(int i, int j, Color value) {
    arr[i][j] = value;
}

int Board::getBoardSize() const{
    return boardSize;
}