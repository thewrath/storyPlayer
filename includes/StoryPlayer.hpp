#ifndef STORYPLAYER_HPP
#define STORYPLAYER_HPP

#include "../includes/StoryMap.hpp"
#include <map>
#include <vector>
#include <string>

typedef void (*orderFunction)(std::string);
typedef std::map<std::string, orderFunction> orderFunction_map;

class StoryPlayer
{
public:
	StoryPlayer();
	StoryPlayer(StoryMap* storyMap);
	~StoryPlayer();

	/**
	 * @brief add storyMap to storyPlayer
	 * @details add storyMap to the vector storyMapList of the storyMap
	 * 
	 * @param storyMap the storyMap to add 
	 */
	void addStoryMap(StoryMap storyMap){ this->storyMapList.push_back(storyMap); }
	//std::vector getStoryMapList(){ //return list of storyMap name }
	void addOrderFunction(std::string order, orderFunction){ this->orderFunctionMap[order]; }

private:
	StoryMap storyMap;
	orderFunction_map orderFunctionMap;	
	std::vector<StoryMap> storyMapList;

	//list of order function 
	static void testOrder(std::string value){ std::cout << "i'am a realy great fonction and i say :"<< value << std::endl;};
};

#endif