#include "../includes/StoryMap.hpp"

/**
 * @brief base constructor 
 * @details no more details 
 */
StoryMap::StoryMap()
{

}

/**
 * @brief storyMap constructor with simple file path which defined the story's flow 
 * @details used this constructor to load a storyMap based on a file 
 * 
 * @param filePath the file path of the file which defined the flow 
 */
StoryMap::StoryMap(std::string filePath)
{
	this->loadStoryMapFile(filePath);
}

StoryMap::~StoryMap()
{

}

/**
 * @brief create a storyMap from a storyFile 
 * @details create a storyMap from a storyFile
 * 
 * @param filePath the file path of the file which defined the flow
 */
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
      		this->orderMap[order] = value;
    	}
    	myfile.close();
  	}
  	else std::cout << "Unable to open file" << std::endl; 
}

/**
 * @brief only used for debug 
 * @details print the map order of the storyMap
 * 
 * @param mapElement map contening orders 
 */
void StoryMap::print(std::map<std::string, std::string>* mapElement)
{
	for(auto& t : *mapElement)
	{
		std::cout << t.first << ": ";
		std::cout << t.second << std::endl; 
	}
}