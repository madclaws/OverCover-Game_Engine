#pragma once
class ResourceManager
{
	ResourceManager(void);
	~ResourceManager(void);
		
public:
	static ResourceManager* Instance;
	static ResourceManager*	 GetInstance();
};

