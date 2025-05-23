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
	void runFromCursor(float cursorX, float cursorY);

	float targetPos = 0.0f;
	bool isMoving = false;
	float speed = 0.0006f;
	float tolerance = 0.01f;
	float runRange = 0.1f;
};

#endif