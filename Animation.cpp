#include "Animation.h"
#include "GameObject.h"
#include <random>


float randomNumber()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distr(-1.0f, 1.0f);

    float random_float = distr(gen);
    std::cout << random_float << std::endl;
    return random_float;
}

void Animation::BackandForth()
{
    const float speed = 0.0006f;
    const float tolerance = 0.01f;

    if (!isMoving || std::abs(object->transform.position.x - targetPos) < tolerance)
    {
        targetPos = randomNumber();
        isMoving = true;
    }

    if (object->transform.position.x < targetPos - tolerance)
    {
        object->transform.position.x += speed;
    }
    else if (object->transform.position.x > targetPos + tolerance)
    {
        object->transform.position.x -= speed;
    }
    else
    {
        isMoving = false;
    }
}