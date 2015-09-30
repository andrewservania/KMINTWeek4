#pragma once
#include "BaseGameEntity.h"
#include "Vector2D.h"
class MovingEntity : public BaseGameEntity
{
protected:

	Vector2D velocity;

	// a normalized vector pointin the direction the entity is heading.
	Vector2D heading;

	// a vector perpendicular to the heading vector
	Vector2D side;

	double mass;

	// the maximum speed this entity may travel at.
	double maxSpeed;

	// the maximum force the entity can produce to power itself
	// (think rockets and thrust)
	double maxForce;

	// the maximum rate (radians per second) this vehicle can rotate
	double maxTurnRate;




public:
	MovingEntity(int id);
	~MovingEntity();
	virtual void Update(float deltaTime) = 0;
};

