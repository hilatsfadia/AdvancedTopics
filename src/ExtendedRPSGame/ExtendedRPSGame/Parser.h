#ifndef ADTO_TARGIL1_PARSER_H
#define ADTO_TARGIL1_PARSER_H

//--------------------------
// Parser Interface
//--------------------------

// Handles main helper functions for parsing files.

// @author Hila Tsfadia, Jael Fafner TAU - Advanced Topics in Programming - 2018 Semester B

#include <string>
#include <vector>
#include "Player.h"
#include "PointImpl.h"
#include "PiecePosition.h"
#include <memory>

class Game;
class Joker;

class Parser
{
protected:

	// trim from start (in place)
	static inline void Ltrim(std::string& s);

	// trim from end (in place)
	static inline void Rtrim(std::string& s);

	// trim from both ends (in place)
	static inline void Trim(std::string &s);

	// Removes duplicates of white spaces
	static void RemoveExtraWhitespaces(const std::string &input, std::string &output);

	// Splits the line into tokens, given in the out parameter,
	// ignoring extra white spaces.
	void GetTokensFromLine(const std::string& line, std::vector<std::string>& outTokens) const;

	// Returns true if and only if the state of inFile is not bad. If bad, prints
	// relevant message and updates the problematic line number.
	bool CheckReadOK(const std::ifstream& inFile, const std::string& playerfileName) const;

	// Gets the Point of the position from coordinates strings
	static unique_ptr<PointImpl> GetPositionFromChars(const std::string& posy, const std::string& posx);

public:
	Parser() {}

	virtual ~Parser() {}

	//splits string s to a vector
	static void Split(const std::string& s, char delim, std::vector<std::string>& outElems);

	// Returns true if and only if the file was opened successfully. Otherwise, prints
	// usage message and updates the problematic line number.
	static bool CheckOpenInputFile(const std::ifstream& inFile, const std::string& inFileName);

	// If input file(s) doesn't exist - print usage
	static void PrintUsageMessage(int playerNum);

	// Returns the initialization file name of the given player
	static std::string GetPositionsFileName(int playerNum);

	// Returns the moves file name of the given player
	static std::string GetMovesFileName(int playerNum);
};

#endif //ADTO_TARGIL1_PARSER_H