//
// Created by shlomy on 29/11/17.
//

#include "../include/AIPlayer.h"
#include "../include/DeafultLogic.h"

AIPlayer::AIPlayer(GameLogic *l, Board *board) : Player(l) {
        this->canPlay = true;
        this->type = 2;
        this->board = board;
}

void AIPlayer::playOneTurn(bool myTurn) {
    // Finds every possible move for the AI
    bool flagFirstTime = true;
    int bestScore;
    int potentialScore = board->getWTiles() - board->getBTiles();
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board->getPosCell(i, j)) {
                // creating a copy of the original board so we can put the AI's move
                Board AIPossible = *board;
                GameLogic *AILogic = NULL;
                if (logic->getType() == "DefaultLogic") {
                    DefaultLogic ai = DefaultLogic(&AIPossible);
                    AILogic = &ai;
                }
                //making the change in the first copy of the board
                AILogic->move(myTurn, i, j);
                if (AILogic->possibleMoves(!myTurn, 2)) {
                    for (int k = 0; k < 8; k++)
                        for (int l = 0; l < 8; l++)
                            if (AIPossible.getPosCell(k, l)) {
                                Board humanAIPossible = AIPossible;
                                GameLogic *AIHumanLogic = NULL;
                                if (logic->getType() == "DefaultLogic") {
                                    DefaultLogic ai2 = DefaultLogic(&humanAIPossible);
                                    AIHumanLogic = &ai2;
                                }
                                AIHumanLogic->move(!myTurn, k, l);
                                int checkScore = humanAIPossible.getWTiles() - humanAIPossible.getBTiles();
                                //cout<< "The check score is: "<<checkScore<<". The potential score is: "<<potentialScore<<endl;
                                if (potentialScore < checkScore)
                                {
                                    //cout<<"before the change the score is "<<potentialScore<<".\n";
                                    potentialScore = checkScore;
                                    //cout<<"now, after potential is "<<potentialScore<<".\n";
                                }
                            }
                }
                if (flagFirstTime) {
                    bestScore = potentialScore;
                    flagFirstTime = false;
                    lastMove.first = i;
                    lastMove.second = j;
                } else if (bestScore < potentialScore) {
                    bestScore = potentialScore;
                    lastMove.first = i;
                    lastMove.second = j;
                }

            }
    logic->move(myTurn, lastMove.first, lastMove.second);


}
