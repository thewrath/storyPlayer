#include "../includes/StoryPlayer.hpp"


namespace sp 
{
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
				std::vector<std::string> tempParameterTab; 
		  		while (std::regex_search (line,m,e)) 
			  	{
			    	this->orderMap.push_back(m[0]);
			    	line = m.suffix().str(); 
			  	}  
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
		//balance this in a thread and read 
		//add corresponding function to order 
		{
			this->orderFunctionMap["test"] = &testOrder;	
			this->orderFunctionMap["other"] = &otherOrder;
			this->orderFunctionMap["playSound"] = &playSoundOrder;
		}
		this->storyMapList.push_back(storyMap);
		

	}

	void StoryPlayer::update()
	{
		//find order and play corresponding function 
		for(auto& storyMap : this->storyMapList)
		{	
			for(auto& t : *storyMap.getOrders())
			{	
				auto iter = this->orderFunctionMap.find("other");
				if (iter == this->orderFunctionMap.end())
				{
	    			// not found
				}
				else{
					(*iter->second)(storyMap.getOrders());	
				}
			}
		}
	}

	StoryPlayer::~StoryPlayer()
	{

	}
};