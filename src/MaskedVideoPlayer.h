#pragma once
#include <ofMain.h>

class MaskedVideoPlayer
{
public:
	MaskedVideoPlayer();
	~MaskedVideoPlayer();

	void draw();
	void update();

private:
	ofVideoPlayer player;
	ofImage imageMask;
};

