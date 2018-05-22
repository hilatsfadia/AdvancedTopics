#include "stdafx.h"
#include "RPSPiece.h"

Piece::WinningPiece RPSPiece::FightWithOtherPieceType(Piece & enemy)
{
	PieceFactory::PieceType enemyPieceType = enemy.GetPieceType();

	switch (enemyPieceType)
	{
		case (PieceFactory::PieceType::Bomb):
		{
			BothPiecesLosers(enemy);
			return WinningPiece::Tie;
			break;
		}
		case (PieceFactory::PieceType::Joker):
		{
			if (enemy.Fight(*this) == WinningPiece::OtherObject)
			{
				return WinningPiece::CallingObject;
			}
			else if (enemy.Fight(*this) == WinningPiece::CallingObject)
			{
				return WinningPiece::OtherObject;
			}
			else
			{
				return WinningPiece::Tie;
			}
			break;
		}
		case (PieceFactory::PieceType::Flag):
		{
			enemy.LoseToPiece();
			return WinningPiece::CallingObject;
			break;
		}
		default:
		{
			return WinningPiece::Tie;
		}
	}
}
