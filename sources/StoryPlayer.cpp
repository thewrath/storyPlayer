#include "../includes/StoryPlayer.hpp"

StoryPlayer::StoryPlayer()
{

}

StoryPlayer::StoryPlayer(StoryMap* storyMap)
{
	//balance this in a thread and read 
	for(auto& t : *storyMap->getOrders())
	{
		std::cout << t.first << ": ";
		std::cout << t.second << std::endl; 
	}
}

StoryPlayer::~StoryPlayer()
{

}