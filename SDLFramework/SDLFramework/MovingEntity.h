#pragma once
#include "BaseGameEntity.h"
class MovingEntity :
	public BaseGameEntity
{
protected:

	



public:
	MovingEntity(int id);
	~MovingEntity();
	void Update(float deltaTime);
};

