#include "../includes/StoryPlayer.hpp"

StoryPlayer::StoryPlayer()
{

}

StoryPlayer::StoryPlayer(StoryMap* storyMap)
{
	//balance this in a thread and read 
	this->orderFunctionMap["test"] = &testOrder;
	
	for(auto& t : *storyMap->getOrders())
	{	
		auto iter = this->orderFunctionMap.find(t.first);
		if (iter == this->orderFunctionMap.end())
		{
    		// not found
		}
		else{
			(*iter->second)(t.second);	
		}
	}
	

}

StoryPlayer::~StoryPlayer()
{

}