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

	float targetPos = 0.0f;
	bool isMoving = false;
};

#endif