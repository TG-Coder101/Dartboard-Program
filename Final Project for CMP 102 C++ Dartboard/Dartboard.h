#pragma once
class Dartboard
{
public:
	Dartboard();
	~Dartboard();

	int throw_bull(int);
	int throw_treble(int, int);
	int throw_double(int);
	int throw_single(int);
};
