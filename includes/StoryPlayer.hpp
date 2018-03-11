#ifndef STORYPLAYER_HPP
#define STORYPLAYER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <map>

#include <typeinfo>

//SFML include 
#include <SFML/Graphics.hpp>

namespace sp {

	class StoryMap
	{
		public:
			StoryMap();
			StoryMap(std::string filePath);
			~StoryMap();
			//std::regex getCommandTemplate() { return this->commandTemplate; }
			//void setCommandTemplate(std::regex commandTemplate) { this->commandTemplate = commandTemplate; }
			std::vector<std::vector<std::string>> getOrders() { return this->orders; }

		private:
			//std::regex commandTemplate("[^@:]+");
			std::vector<std::vector<std::string>> orders;
			void loadStoryFile(std::string filePath);
	};

	typedef void (*orderFunction) (std::vector<std::string>);
	class StoryPlayer
	{
		public:
			StoryPlayer();
			StoryPlayer(StoryMap storyMap);
			~StoryPlayer();
			void update();
			void addStoryMap(StoryMap storyMap) { this->storyMaps.push_back(storyMap); }
			void addOrderFunction(std::string order, orderFunction) { this->orderFunctionMap[order]; }
		private:
			std::vector<StoryMap> storyMaps;
			std::map<std::string, orderFunction> orderFunctionMap;
			
			static void testOrder(std::vector<std::string> parameters) { std::cout << parameters[1] << std::endl; }
			static void playSoundOrder(std::vector<std::string> parameters) { std::cout << "i play sound : " << parameters[1] << " with duration " << parameters[2] << std::endl; }
	};
};
#endif