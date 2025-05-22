#ifndef Animation_CLASS_H
#define Animation_CLASS_H
#include <string>

class Object;

class Animation
{
	Object* object;
public:
	Animation(Object* obj) : object(obj) {}
	
	void BackandForth();

	float sPos, ePos;
	bool inAnimation = false;
};

#endif