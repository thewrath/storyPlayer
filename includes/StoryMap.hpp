#ifndef STORYMAP_HPP
#define STORYMAP_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <regex>

class StoryMap
{
public:
	StoryMap();
	StoryMap(std::string filePath);
	~StoryMap();
	std::regex getCommandTemplate(){ return this->commandTemplate; }
	void setCommandTemplate(std::regex commandTemplate){ this->commandTemplate = commandTemplate; }
	/**
	 * @brief return orderMap of the storyMap
	 * @details return the orderMap of the storyMap
	 * @return pointer of the storyMap's orderMap
	 */
	std::multimap<std::string, std::string>* getOrders(){return &this->orderMap;}
private:
	std::regex commandTemplate; 
	// std::string name; the story map name ( catch from file title or param in consctructor )
	std::multimap<std::string, std::string> orderMap;
	void loadStoryMapFile(std::string filePath);
	void print(std::multimap<std::string, std::string>* mapElement);
};

#endif