#ifndef ADTO_TARGIL1_PIECE_STRATEGY_H
#define ADTO_TARGIL1_PIECE_STRATEGY_H

//--------------------------
// StrategyPiece Interface
//--------------------------

//Creates and manages an instance the represents a dummy piece on a dummy 
// board, used to keep all the needed information about the flow of 
// the game by a certain auto player algorithm.

// @author Hila Tsfadia, Jael Fafner TAU - Advanced Topics in Programming - 2018 Semester B

#include "Piece.h"
#include "PieceFactory.h"
#define COVERED_CHAR 'C'

class StrategyPiece :
	public Piece
{
private:
	unique_ptr<Piece> mUncoveredPiece = nullptr;
	bool mIsThreatenedByStronger = false;
	bool mIsThreathening = false;
	bool mIsMovingPiece = false;
	bool mIsDiscovered = false; // Is curr player piece discovered by the opponent
	bool mIsThreatenedBecauseDiscovered = false;

public:
	StrategyPiece(int ownerNum) : Piece(ownerNum) { }

	// Gets this piece type.
	// If this piece is still covered, gets PieceType::Unknown.
	PieceType GetPieceType() const override;
	PieceType GetActualPieceType() const override;

	bool GetIsMovingPiece() const override;

	char GetPieceChar() const override;
	char GetActualPieceChar() const override;

	void SetMovingPiece() { mIsMovingPiece = true; }

	// Uncovers this piece by giving it the actual piece it represents.
	void UncoverPiece(std::unique_ptr<Piece> uncoveredPiece);

	// Uncover this piece by setting it's real piece.
	// If this piece is already uncovered, check if it's indeed the given char. If not, update
	// it to be the relevant joker (with a relevant representation).
	// uncoveredPieceChar should be R, P, S, B or F (but NOT J)
	void UncoverPiece(char uncoveredPieceChar);

	// Returns true iff this piece is threatened by an enemy piece (one or more)
	bool GetIsThreatenedByStronger() const { return mIsThreatenedByStronger; }
	void SetIsThreatenedByStronger(bool isThreatenedByStronger) { mIsThreatenedByStronger = isThreatenedByStronger; }

	// Returns true iff this piece is threatening an enemy piece (one or more)
	bool GetIsThreathening() const { return mIsThreathening; }
	void SetIsThreathening(bool isThreatening) { mIsThreathening = isThreatening; }

	// Returns true iff this piece is the current player piece and discovered by the enemy
	bool GetIsDiscovered() const { return mIsDiscovered; }
	void SetIsDiscovered(bool isDiscovered) { mIsDiscovered = isDiscovered; }

	// Returns true iff this piece is the current player piece and is adjacent to an enemy piece and discovered
	bool GetIsThreatenedBecauseDiscovered() const { return mIsThreatenedBecauseDiscovered; }
	void SetIsThreatenedBecauseDiscovered(bool isThreatenedBecauseDiscovered) { mIsThreatenedBecauseDiscovered = isThreatenedBecauseDiscovered; }

	// Returns true iff this piece is stronger than the other piece given
	virtual bool IsStrongerThan(const StrategyPiece& other) const;

	// TODO: maybe derived class
	void ChangeJokerToStronger(PieceType enemyPieceType);
};

#endif //ADTO_TARGIL1_PIECE_STRATEGY_H
