#include "Animation.h"
#include "GameObject.h"
#include "Window.h"
#include <random>


float randomNumber(float min, float max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distr(min,max);
    return distr(gen);
}

void Animation::BackandForth()
{
    if (!isMoving || std::abs(object->transform.position.x - targetPos) < tolerance)
    {
        targetPos = randomNumber(-1.0f, 1.0f);
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

void Animation::runFromCursor(float cursorX, float cursorY)
{    
    float objX = object->transform.position.x;

    if (std::abs(objX - cursorX) < runRange)
    {
        if (objX < cursorX) 
            targetPos = randomNumber(-1.0f, std::min(cursorX - runRange, 0.98f));
        else                
            targetPos = randomNumber(std::max(cursorX + runRange, -0.98f), 1.0f);

        isMoving = true;
    }
    else if (!isMoving || std::abs(objX - targetPos) < tolerance)
    {
        targetPos = randomNumber(-0.98f, 0.98f);
        isMoving = true;
    }

    if (objX < targetPos - tolerance)
        object->transform.position.x += speed;
    else if (objX > targetPos + tolerance)
        object->transform.position.x -= speed;
    else
        isMoving = false;

    std::cout << targetPos << std::endl;
}