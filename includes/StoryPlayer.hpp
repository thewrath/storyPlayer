#ifndef STORYPLAYER_HPP
#define STORYPLAYER_HPP

#include "../includes/StoryMap.hpp"

class StoryPlayer
{
public:
	StoryPlayer();
	~StoryPlayer();

	StoryMap* getStoryMap(){return &this->storyMap;}
	void setStoryMap();
	
private:
	StoryMap storyMap;
		
};

#endif