#include "Arena.h"


Cow* Arena::cow;
Rabbit* Arena::rabbit;

Arena::Arena()
{
	cow = new Cow(1);
	rabbit = new Rabbit(2);
	mApplication->AddRenderable(this);
}


Arena::~Arena()
{
}

void Arena::Update(float deltaTime)
{

}