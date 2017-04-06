#pragma once
namespace OverCover2D {
	class Component
	{


	public:
		~Component(void);
		virtual void Update() = 0;
	};
}

