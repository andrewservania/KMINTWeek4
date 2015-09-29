#pragma once
#include "BaseGameEntity.h"
class MovingEntity :
	public BaseGameEntity
{
public:
	MovingEntity(int id);
	~MovingEntity();
	void Update(float deltaTime);
};

