#pragma once
#include "MovingEntity.h"
class Vehicle :
	public MovingEntity
{
public:
	Vehicle(int id);
	~Vehicle();
	void Update(float deltaTime) override;
private:

	
};

