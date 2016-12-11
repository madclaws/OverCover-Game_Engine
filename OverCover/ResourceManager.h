#pragma once
//Resource Manager is Singleton class ie only one copy of its object will be in entire program
class ResourceManager
{
	//Constructor should be private preventing from creating instant from other classes
	ResourceManager(void);
	~ResourceManager(void);
		
public:
	//The fact we declare the variable as pointer because it is not pre-declared in anywhere
	//members should be static for singleton
	static ResourceManager* Instance;
	static ResourceManager*	 GetInstance();
};

