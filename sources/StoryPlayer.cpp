#include "../includes/StoryPlayerTest.hpp"


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
				while(std::regex_search(line,m,e))
				{
					this->orders.push_back(m[0]);
					std::cout << this->orders[this->orders.size()-1] << " ";
					line = m.suffix().str();
				}
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
			auto iter = this->orderFunctionMap.find(storyMap.getOrders()[0]);
			if ( iter == this->orderFunctionMap.end() )
			{
				//not found 
			}
			else
			{
				(*iter->second)(storyMap.getOrders());
			}
		}
	}

	
};