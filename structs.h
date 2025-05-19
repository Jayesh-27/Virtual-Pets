#ifndef STRUCTS_CLASS_H

#define STRUCTS_CLASS_H

struct Vector3
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3(float x, float y)
	{
		this->x = x;
		this->y = y;		
	}
};


#endif // !STRUCTS_CLASS_H
