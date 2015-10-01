#pragma once
#include "MovingEntity.h"
#include "Vector2D.h"
#include "SteeringBehaviors.h"
#include "Smoother.h"

class Vehicle :
	public MovingEntity
{
private:

	//the steering behavior class
	SteeringBehavior* steering;

	//some steering behaviors give a jerky looking movement.
	//The following members are used to smooth the vehicle's heading
	Smoother<Vector2D>* headingSmoother;

	//this vector represents the average of the vehicle's heading
	//vector smoothed over the last few frames
	Vector2D smoothedHeading;

	//when true, smoothing is active
	bool smoothingOn;

	//keeps a track of the most recent update time.
	//some of the steering behvarios make use of this - see Wander)
	double timeElapsed;

	//buffer for the vehicle shape
	//std::vector<Vector2D> vehicleVB;

	//fills the buffer with vertex data


public:
	Vehicle(int id,
		Vector2D _position,
		double _rotation,
		Vector2D _velocity,
		double _mass,
		double _max_force,
		double _max_speed,
		double _max_turn_rate,
		double _scale);

	~Vehicle();
	void Update(float deltaTime) override;
	SteeringBehavior* Steering() const { return steering; }

	Vector2D SmoothingHeading() const { return smoothedHeading; }

	// Accessor methods
	bool isSmoothingOn() const {return smoothingOn;}
	bool SmoothingOn() { smoothingOn = true; }
	bool SmoothingOff() { smoothingOn = false;  }
	bool ToggleSmoothing() { return !smoothingOn; }

	double TimeElapsed() const { return timeElapsed; }
	
};

