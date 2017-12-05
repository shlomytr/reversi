//
// Created by Shlomy and Omer
//

#include "../include/DeafultLogic.h"

DefaultLogic::DefaultLogic(Board *board) : GameLogic(board) {
}

bool DefaultLogic::possibleMoves(bool blacksTurn, int type, Printer *printer) {
    bool thereArePosMoves = false;
    for (int i = 0; i < board->getBoardSize(); i++)
        for (int j = 0; j < board->getBoardSize(); j++)
            board->setPosCell(i, j, false);
    for (int i = 0; i < board->getBoardSize(); i++) {
        for (int j = 0; j < board->getBoardSize(); j++) {
            if (board->getCell(i, j) == ' ')
                for (int rowDiff = -1; rowDiff < 2; rowDiff++)
                    for (int colDiff = -1; colDiff < 2; colDiff++)
                        if (rowDiff != 0 || colDiff != 0)
                            if (!board->getPosCell(i, j) &&
                                checkAdTile(blacksTurn, i, j, rowDiff, colDiff,
                                            false)) {
                                board->setPosCell(i, j, true);
                                thereArePosMoves = true;
                            }
        }
    }
    if (thereArePosMoves && type == 1)
        printer->printPosMoves(*board);
    return thereArePosMoves;


}


bool DefaultLogic::changeBoard(bool blacksTurn, int i, int j, int rowDif, int colDif, bool foundACandidate) {
    // There are no more tiles to check - The function will return false
    if (i + rowDif > 7 || i + rowDif < 0 || j + colDif > 7 || j + colDif < 0)
        return false;
    if (blacksTurn) {
        // Black's turn - Reached a black tile. All the white tiles will flip
        if (foundACandidate && board->getCell(i + rowDif, j + colDif) == 'x')
            return true;
        // Black's turn - tries to check if the first adjacent tile is white, and if true flips it
        if (!foundACandidate && board->getCell(i + rowDif, j + colDif) == 'o') {
            if (changeBoard(blacksTurn, i + rowDif, j + colDif, rowDif, colDif, true)) {
                flipTile(blacksTurn, i + rowDif, j + colDif);
                return true;
            }
        }
        // Black's turn - tries to check if all the rest of the tiles are white, and if true flips them
        if (foundACandidate && board->getCell(i + rowDif, j + colDif) == 'o') {
            if (changeBoard(blacksTurn, i + rowDif, j + colDif, rowDif, colDif, true)) {
                flipTile(blacksTurn, i + rowDif, j + colDif);
                return true;
            }
        }
    } else {
        // White's turn - Reached a white tile. All the black tiles will flip
        if (foundACandidate && board->getCell(i + rowDif, j + colDif) == 'o')
            return true;
        // White's turn - tries to check if the first adjacent tile is black, and if true flips it
        if (!foundACandidate && board->getCell(i + rowDif, j + colDif) == 'x') {
            if (changeBoard(blacksTurn, i + rowDif, j + colDif, rowDif, colDif, true)) {
                flipTile(blacksTurn, i + rowDif, j + colDif);
                return true;
            }

        }
        // White's turn - Flips the next black tile
        if (foundACandidate && board->getCell(i + rowDif, j + colDif) == 'x') {
            if (changeBoard(blacksTurn, i + rowDif, j + colDif, rowDif, colDif, true)) {
                flipTile(blacksTurn, i + rowDif, j + colDif);
                return true;
            }

        }
    }

    return false;
}

bool DefaultLogic::checkAdTile(bool blacksTurn, int i, int j, int rowDif, int colDif, bool foundACandidate) {
    // There are no more tiles to check - The function will return false
    if (i + rowDif > 7 || i + rowDif < 0 || j + colDif > 7 || j + colDif < 0)
        return false;
    if (blacksTurn) {
        // Black's turn - the function returns true
        if (foundACandidate && board->getCell(i + rowDif, j + colDif) == 'x')
            return true;
        // Black's turn - tries to check if the first adjacent tile is white
        if (!foundACandidate && board->getCell(i + rowDif, j + colDif) == 'o')
            return checkAdTile(blacksTurn, i + rowDif, j + colDif, rowDif, colDif, true);
        // Black's turn - tries to check if the the rest of the tiles are white
        if (foundACandidate && board->getCell(i + rowDif, j + colDif) == 'o')
            return checkAdTile(blacksTurn, i + rowDif, j + colDif, rowDif, colDif, true);
    } else {
        // White's turn - the function returns true
        if (foundACandidate && board->getCell(i + rowDif, j + colDif) == 'o')
            return true;
        // White's turn - tries to check if the first adjacent tile is black
        if (!foundACandidate && board->getCell(i + rowDif, j + colDif) == 'x')
            return checkAdTile(blacksTurn, i + rowDif, j + colDif, rowDif, colDif, true);
        // White's turn - tries to check if the rest of the tiles are black
        if (foundACandidate && board->getCell(i + rowDif, j + colDif) == 'x')
            return checkAdTile(blacksTurn, i + rowDif, j + colDif, rowDif, colDif, true);
    }
    return false;

}

string DefaultLogic::getType() {
    return "DefaultLogic";
}


