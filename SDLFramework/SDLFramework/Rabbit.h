#pragma once

#include "Vehicle.h"
#include "StateMachine.h"
#include "Vector2D.h"
#include "SteeringBehaviors.h"
#include "Smoother.h"

class Rabbit :
	public Vehicle
{
public:
	StateMachine<Rabbit>* stateMachine;

	Rabbit(int id,
		Vector2D _position,
		double _rotation,
		Vector2D _velocity,
		double _mass,
		double _max_force,
		double _max_speed,
		double _max_turn_rate,
		double _scale);

	~Rabbit();
	virtual void Update(float deltaTime) override;
	virtual void Draw()override;
	void OnLeftClick();
	void OnRightClick();
	std::string GetCurrentState() { return stateMachine->CurrentState()->GetStateName(); }
	StateMachine<Rabbit>* GetFSM() { return stateMachine; }
};
