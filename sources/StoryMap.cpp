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
  std::regex e("[^@:]+");
  std::smatch m;

  std::string line;
  std::ifstream myFile(filePath);

  if(myFile.is_open())
  {
    while( std::getline(myFile,line) )
    {
      while (std::regex_search (line,m,e)) 
      {
        this->orderMap.insert(std::make_pair(m[0],m[1]));
        line = m.suffix().str(); 
      }   
    }
    this->print(&this->orderMap);
    myFile.close();
  }
	else std::cout << "Unable to open file" << std::endl; 
}

/**
 * @brief only used for debug 
 * @details print the map order of the storyMap
 * 
 * @param mapElement map contening orders 
 */
void StoryMap::print(std::multimap<std::string, std::string>* mapElement)
{
	for(auto& t : *mapElement)
	{
		std::cout << t.first << ": ";
		std::cout << t.second << std::endl; 
	}
}