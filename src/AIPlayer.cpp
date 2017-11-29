//
// Created by Shlomy and Omer
//

#include "../include/AIPlayer.h"
#include "../include/DeafultLogic.h"

AIPlayer::AIPlayer(GameLogic *l, Board *board) : Player(l) {
    this->canPlay = true;
    this->type = 2;
    this->board = board;
}

void AIPlayer::playOneTurn(bool blacksTurn) {
    // boolean flag to indicate the first time copying the board
    bool flagFirstTime2 = true;
    // the minimum score that the rival can get after 2 moves
    int bestScore;
    // the best score that the rival can get after the AI's turn. defaults to the current score
    int potentialScore;// = board->getWTiles() - board->getBTiles();
    for (int i = 0; i < board->getBoardSize(); i++)
        for (int j = 0; j < board->getBoardSize(); j++)
            if (board->getPosCell(i, j)) {
                // boolean flag to indicate the first time checking a possible score for the rival
                bool flagFirstTime1 = true;
                // creating a copy of the original board so we can put the AI's move
                Board AIPossible = *board;
                // creating a logic to affect the copy of the original board
                GameLogic *AILogic = NULL;
                if (logic->getType() == "DefaultLogic") {
                    DefaultLogic ai = DefaultLogic(&AIPossible);
                    AILogic = &ai;
                }
                // making the change in the first copy of the board
                AILogic->move(blacksTurn, i, j);
                // check what the all possible moves of the human player
                if (AILogic->possibleMoves(!blacksTurn, 2)) {
                    for (int k = 0; k < board->getBoardSize(); k++)
                        for (int l = 0; l < board->getBoardSize(); l++)
                            if (AIPossible.getPosCell(k, l)) {
                                // creating a copy of the board after the potential move of the ai
                                Board humanAIPossible = AIPossible;
                                // creating a logic to affect the humanPossible board
                                GameLogic *AIHumanLogic = NULL;
                                if (logic->getType() == "DefaultLogic") {
                                    DefaultLogic ai2 = DefaultLogic(&humanAIPossible);
                                    AIHumanLogic = &ai2;
                                }
                                // making the change in the humanPossible board
                                AIHumanLogic->move(!blacksTurn, k, l);
                                // put the score after the moves in a new integer
                                int checkScore = humanAIPossible.getWTiles() - humanAIPossible.getBTiles();
                                // in the first time checking the possible move for the human, puts the current score
                                // in potential score and puts the flagFirstTime1 false
                                if (flagFirstTime1) {
                                    flagFirstTime1 = false;
                                    potentialScore = checkScore;
                                    // if the current score is better than the best score until now, updates the
                                    // potential score to the current score
                                } else if (potentialScore < checkScore)
                                    potentialScore = checkScore;
                            }
                }
                if (flagFirstTime2) {
                    bestScore = potentialScore;
                    flagFirstTime2 = false;
                    lastMove.first = i;
                    lastMove.second = j;
                } else if (bestScore < potentialScore) {
                    bestScore = potentialScore;
                    lastMove.first = i;
                    lastMove.second = j;
                }

            }
    logic->move(blacksTurn, lastMove.first, lastMove.second);


}
