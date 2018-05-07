#ifndef ADTO_TARGIL1_GAME_H
#define ADTO_TARGIL1_GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include "Player.h"
#include "BoardImpl.h"
#include "PlayerAlgorithm.h"
//class PlayerAlgorithm;
class Joker;

#define OUTPUT_FILE_NAME "rps.output"
#define NUM_OF_PLAYERS 2
#define FLAGS_CAPTURED "All flags of the opponent are captured"
#define PIECES_EATEN "All moving PIECEs of the opponent are eaten"
#define TIE_NO_WINNER "A tie - both Moves input files done without a winner"
#define TIE_FLAGS_EATEN "A tie - all flags are eaten by both players in the position files"
//ask
//#define TIE_NO_MOVING_PIECES "A tie - all moving are eaten by both players in the position files"
#define BAD_POS_PLAYER "Bad Positioning input file for player %d - line %d"
#define BAD_POS_BOTH_PLAYERS "Bad Moves input file for both players - player 1: line %d, player 2: line %d"
#define BAD_MOVE_PLAYER "Bad Moves input file for player %d - line %d"
#define MESSAGE_MAX_LEN 150
#define INPUT_FILE_NAME_MAX_LEN 100

class Game
{
private:
	//PlayerAlgorithm& mPlayer1Algorithm;
	//PlayerAlgorithm& mPlayer2Algorithm;
	BoardImpl mGameBoard;

	//enum class Winner { Tie = 0, Player1 = 1, Player2 = 2, None = 3 };

	Player* mPlayers[NUM_OF_PLAYERS];
	//PlayerAlgorithm* mAlgorithms[NUM_OF_PLAYERS];
	//std::string mGameOverMessage = "";
	//Winner mWinner = Winner::None;
	//int mProblematicLineOfPlayer[NUM_OF_PLAYERS] = { -1, -1 };
	//bool isInputFileCannotBeOpened = false;

	//friend class Parser;
	//friend class ParserInitFile;
	//friend class ParserMoveFile;

	//// Handles the parsing and execution of the positioning files,
	//// while setting the winner (and relevant message) if any.
	//// Returns false in case input file is missing or cannot be opened 
	//bool ParseInitFiles();

	//// If input file(s) doesn't exist - print usage
	//static void PrintUsageMessage();

	//// When one of the input files (position file or move file) has bad format,
	//// update message and winner.
	//bool SetBadInputFileMessageWithWinner(int loserNum, Winner winner, int lineNum, const char* templateBadFormatMessage);

	//// When both of the position files has bad format,
	//// update message and winner.
	//bool HandleBadPositionFilesMessageWithWinner(int lineNum1, int lineNum2);

	//// When game is over, prints the relevant output file.
	//void MakeOutputFile();

public:
	//enum Reason {PLAYER1_FLAGS_CAPTURED, PLAYER2_FLAGS_CAPTURED, 
	//	PLAYER1_PIECES_EATEN, PLAYER2_PIECES_EATEN,
	//	TIE_NO_WINNING_MOVE, TIE_ALL_FLAGS_EATEN_IN_POSITIONS_FILES,
	//	BAD_POS_INPUT_FILE_PLAYER1, BAD_POS_INPUT_FILE_PLAYER2,
	//	BAD_POS_INPUT_FILES, BAD_MOVE_INPUT_FILE_PLAYER1, BAD_MOVE_INPUT_FILE_PLAYER2, NO_WINNER};

	Game(PlayerAlgorithm* player1Algorithm, PlayerAlgorithm* player2Algorithm);

	virtual ~Game();

	// Put a non joker piece in given position.  
	// Get detailed about positioning from the given tokens, and checks for tokens validity.
	bool PutNonJokerOnBoard(Player& player, std::unique_ptr<PiecePosition>& piecePos, BoardImpl& board);

	// Changes the joker actual type to the one represented by the given character.
	bool ChangeJokerActualType(Joker* joker, char cJokerRepresantation);

	// Initializes the joker with it's owner and actual type represented by the given character.
	bool InitJokerOwnerAndActualType(Joker* joker, char cJokerRepresantation, Player* owner);

	// Put a joker piece in given position. 
	// Get detailed about positioning from the given tokens, and checks for tokens validity.
	bool PutJokerOnBoard(Player& player, std::unique_ptr<PiecePosition>& piecePos, BoardImpl& board);

	bool PutPlayerPiecesOnBoard(Player& player, std::vector<unique_ptr<PiecePosition>>& playerPiecePositions, BoardImpl& board);

	bool MakeMove(const Player& player, unique_ptr<Move>& move, FightInfo* toFill);

	void RunGame();

	//// Init the Game by positioning the pieces on it's board, 
	//// according to the init files.
	//bool InitGame();

	//// Read The move files and play the game by making the moves, each player at a time. 
	//void Play();

	//// Checks whether one of the players wins the game, i.e
	//// captured all the flags of the opponent (one flag in Ex1)
	//Winner CheckGameOverAfterMove();

	//// Get the winner object according to loser player's number.
	//Winner GetWinner(int loserNum) const;

	//// Get the winner object according to loser player's number.
	//Winner GetWinnerAfterInitBoard();
};
#endif //ADTO_TARGIL1_GAME_H
