#ifndef STORYMAP_HPP
#define STORYMAP_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>

class StoryMap
{
public:
	StoryMap();
	StoryMap(std::string filePath);
	~StoryMap();

	std::map<std::string, std::string>* getOrders(){return &this->orders;}
private:

	std::map<std::string, std::string> orders;
	void loadStoryMapFile(std::string filePath);
	void print(std::map<std::string, std::string>* mapElement);
};

#endif