#ifndef STORYPLAYER_HPP
#define STORYPLAYER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <map>

//SFML include 
#include <SFML/Graphics.hpp>

namespace sp {

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
			std::vector<std::string>* getOrders(){return &this->orderMap;}
		private:
			std::regex commandTemplate; 
			// std::string name; the story map name ( catch from file title or param in consctructor )
			std::vector<std::string> orderMap;
			void loadStoryMapFile(std::string filePath);
	};

	typedef void (*orderFunction)(&std::vector<std::string>);
	typedef std::map<std::string, orderFunction> orderFunction_map;

	class StoryPlayer
	{
	public:
		StoryPlayer();
		StoryPlayer(StoryMap storyMap);
		~StoryPlayer();
		void update(); 
		void addStoryMap(StoryMap storyMap){ this->storyMapList.push_back(storyMap); }
		//std::vector getStoryMapList(){ //return list of storyMap name }
		void addOrderFunction(std::string order, orderFunction){ this->orderFunctionMap[order]; }

	private:
		StoryMap storyMap;
		orderFunction_map orderFunctionMap;	
		std::vector<StoryMap> storyMapList;

		//list of order function 
		static void testOrder(std::vector<std::string> &parameters){ std::cout << "i am a realy great fonction and i say :"<< parameters[0] << std::endl;};
		static void otherOrder(std::vector<std::string> &parameters){ std::cout << "i am another really great function and i say :" << parameters[0] << std::endl; };
		static void playSoundOrder(std::vector<std::string> &parameters){ std::cout << "playing sound : " << parameters[0] << std::endl; }
	};
};
#endif