//
// Created by shlomy on 05/12/17.
//

#include "../include/ConsolePrinter.h"

ConsolePrinter::ConsolePrinter() = default;

void ConsolePrinter::printNextTurn(bool blacksTurn) {
    if (blacksTurn)
        cout << "The next move - Player x:\n\n";
    else
        cout << "The next move - Player o:\n\n";
}

void ConsolePrinter::printNoMoves() {
    cout << "No possible moves, the turn goes to the next player. Press a key and then enter to continue\n";
    char k;
    cin >> k;
}

void ConsolePrinter::printLastMove(bool blacksTurn, int i, int j) {
    if (!blacksTurn)
        cout << "The last move of player x was: (" << i + 1 << "," << j + 1 << ")\n";
    else
        cout << "The last move of player o was: (" << i + 1 << "," << j + 1 << ")\n";

}

void ConsolePrinter::printBoard(Board &b, bool onlyPrintBoard) {
    if (!onlyPrintBoard)
        cout << "The current board:\n";
    int row = 1;
    string tmp(4*b.getBoardSize(),'-');
    cout << " | ";
    for (int i = 1; i < b.getBoardSize() + 1; i++)
        cout << i << " | ";
    cout << "\n"<<tmp<<"--"<<"\n";
    for (int i = 0; i < b.getBoardSize(); i++, row++) {
        cout << row << "| ";
        for (int j = 0; j < b.getBoardSize(); j++)
            cout << b.getCell(i,j) << " | ";
        cout << "\n"<<tmp<<"--"<<"\n";
    }
    if (!onlyPrintBoard)
        cout << "The score is: Black = " << b.getBTiles() << "\tWhite = " << b.getWTiles() << endl;
}

void ConsolePrinter::printsWhoWon(Board &b) {
    cout << "The final board:\n";
    printBoard(b,true);
    cout << "The game is finished! The final score is: Black = " << b.getBTiles() << "\tWhite = "
         << b.getWTiles() << endl;
    cout << "The winner is ";
    if (b.getBTiles() > b.getWTiles())
        cout << "Black!\n";
    else if (b.getBTiles() < b.getWTiles())
        cout << "White!\n";
    else
        cout << "no one! The game ended as a draw!\n";
}

void ConsolePrinter::printEnterNextTurn() {
    cout << "Please enter your next move: row,col\n";
}

void ConsolePrinter::PrintInvalidMove() {
    cout << "Invalid move, please enter a legal move: row,col\n";
}

void ConsolePrinter::printPosMoves(Board &b) {
    cout << "Your possible moves are: ";
    for (int i = 0; i < b.getBoardSize(); i++)
        for (int j = 0; j < b.getBoardSize(); j++)
            if (b.getPosCell(i, j))
                cout << "(" << i + 1 << "," << j + 1 << ") ";
    cout<<endl;
}
