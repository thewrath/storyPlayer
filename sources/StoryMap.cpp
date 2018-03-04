#include "../includes/StoryMap.hpp"

StoryMap::StoryMap()
{

}

StoryMap::StoryMap(std::string filePath)
{
	this->loadStoryMapFile(filePath);
}

StoryMap::~StoryMap()
{

}

void StoryMap::loadStoryMapFile(std::string filePath)
{
	std::string line;
  	std::ifstream myfile (filePath);

  	if (myfile.is_open())
  	{
    	while ( std::getline (myfile,line) )
    	{
    		std::string order;
    		std::string value;
    		bool isAnOrder = true;
      		for(char & c : line)
      		{
      			if(c == ':')
      				isAnOrder = false;
      			if(isAnOrder)
      			{
      				order += c;
      			}
      			else if(c != ':' && c != ' ')
      			{
      				value += c;
      			}	

      		}
      		this->orders[order] = value;
    	}
    	this->print(&this->orders);
    	myfile.close();
  	}
  	else std::cout << "Unable to open file" << std::endl; 
}

void StoryMap::print(std::map<std::string, std::string>* mapElement)
{
	for(auto& t : *mapElement)
	{
		std::cout << t.first << ": ";
		std::cout << t.second << std::endl; 
	}
}