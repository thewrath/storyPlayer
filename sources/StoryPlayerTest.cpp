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


	
};