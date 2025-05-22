#ifndef TRANSFORM_CLASS_H
#define TRANSFORM_CLASS_H
#include "Vector.h"

class Transform
{
public:
	Vector3 position;
	Vector3 scale = { 1.0f, 1.0f, 0.0f};
};

#endif