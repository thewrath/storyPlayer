#ifndef STORYPLAYER_HPP
#define STORYPLAYER_HPP

#include "../includes/StoryMap.hpp"

//SFML include 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <vector>
#include <string>

typedef struct GameComponents
{
	
	sf::RenderWindow* window;
	sf::Music* soundBuffer;

} 
GameComponents; 

typedef void (*orderFunction)(std::string, GameComponents*);
typedef std::map<std::string, orderFunction> orderFunction_map;

class StoryPlayer
{
public:
	StoryPlayer();
	StoryPlayer(StoryMap storyMap);
	~StoryPlayer();
	void update(GameComponents* gameComponents);
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
	static void testOrder(std::string value, GameComponents* gameComponents){ std::cout << "i am a realy great fonction and i say :"<< value << std::endl;};
	static void otherOrder(std::string value, GameComponents* gameComponents){ std::cout << "i am another really great function and i say :" << value << std::endl; };
	static void playSoundOrder(std::string value, GameComponents* gameComponents){ std::cout << "playing sound : " << value << std::endl; gameComponents->soundBuffer->openFromFile(value); gameComponents->soundBuffer->play(); }
};

#endif