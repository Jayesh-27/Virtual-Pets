#include "Animation.h"
#include "GameObject.h"

void Animation::BackandForth()
{
    Animation::sPos = 0.0f;
    if (!Animation::inAnimation)
    {
        Animation::ePos = (static_cast<float>(rand()) / RAND_MAX) * 2.0f - 1.0f;    
    }

    if (object->transform.position.x < Animation::ePos)
    {
        object->transform.position.x += 0.001f;
        Animation::inAnimation = true;
    }

    else if (object->transform.position.x > Animation::ePos)
    {
        object->transform.position.x -= 0.001f;
        Animation::inAnimation = true;
    }
}