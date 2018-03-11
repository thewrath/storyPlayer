#include "../includes/StoryPlayer.hpp"


namespace sp 
{
	StoryMap::StoryMap() { }
	
	StoryMap::StoryMap(std::string filePath)
	{
		this->loadStoryFile(filePath);
	}

	StoryMap::~StoryMap() { }

	void StoryMap::loadStoryFile(std::string filePath)
	{
		std::regex e("[^@:]+");
		std::smatch m;
		std::string line;
		std::ifstream myFile(filePath);

		if(myFile.is_open())
		{
			while(std::getline(myFile,line))
			{
				std::vector<std::string> temp;
				while(std::regex_search(line,m,e))
				{
					temp.push_back(m[0]);
					line = m.suffix().str();
				}
				this->orders.push_back(temp);
				std::cout << std::endl;
			}
			myFile.close();
		}
		else std::cout << "Unable to open file" << std::endl;
	}

	StoryPlayer::StoryPlayer()
	{

	}

	StoryPlayer::StoryPlayer(StoryMap storyMap)
	{
		{
			this->orderFunctionMap["test"] = &testOrder;
			this->orderFunctionMap["playSound"] = &playSoundOrder;
		}
		this->storyMaps.push_back(storyMap);
	}

	StoryPlayer::~StoryPlayer()
	{

	}

	void StoryPlayer::update()
	{
		for(auto& storyMap : this->storyMaps)
		{
			for(auto& t : storyMap.getOrders())
			{
				auto iter = this->orderFunctionMap.find(t[0]);
				if ( iter == this->orderFunctionMap.end() )
				{
					//not found 
				}
				else
				{
					(*iter->second)(t);
				}
			}
		}
	}

	
};