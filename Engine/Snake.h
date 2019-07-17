#pragma once
#include "Board.h"

//Put class within class, or I can use polymorphism
class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& loc);
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const
		{
			brd.DrawCell(loc, c);
		}
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd) const;
	
private:
	static constexpr Color headColor = Colors::White;
	static constexpr Color bodyColor = Colors::Blue;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;


};