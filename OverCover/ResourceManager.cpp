#include "ResourceManager.h"

ResourceManager* ResourceManager::Instance;
ResourceManager::ResourceManager(void)
{

}



ResourceManager* ResourceManager::GetInstance()
{
	if(Instance==nullptr)
	{
		Instance=new ResourceManager();
	}
	return Instance;
	
}
ResourceManager::~ResourceManager(void)
{

}