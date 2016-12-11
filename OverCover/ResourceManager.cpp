#include "ResourceManager.h"
//A static member should be declared outside class
ResourceManager* ResourceManager::Instance;


ResourceManager::ResourceManager(void)
{

}



ResourceManager* ResourceManager::GetInstance()
{
	//Always return same object if try to create one OR create one if there is no object previously
	if(Instance==nullptr)
	{
		Instance=new ResourceManager();
	}
	return Instance;
	
}
ResourceManager::~ResourceManager(void)
{

}