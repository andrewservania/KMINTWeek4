#include "Vehicle.h"
#include "Parameters.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
///  Create a vehicle that will be traveling on the arena.
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="id">			 	The identifier. </param>
/// <param name="_position">	 	The position. </param>
/// <param name="_rotation">	 	The rotation. </param>
/// <param name="_velocity">	 	The velocity. </param>
/// <param name="_mass">		 	The mass. </param>
/// <param name="_max_force">	 	The maximum force. </param>
/// <param name="_max_speed">	 	The maximum speed. </param>
/// <param name="_max_turn_rate">	The maximum turn rate. </param>
/// <param name="_scale">		 	The scale. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

Vehicle::Vehicle(int id,
	Vector2D _position,
	double _rotation,
	Vector2D _velocity,
	double _mass,
	double _max_force,
	double _max_speed,
	double _max_turn_rate,
	double _scale) :
	MovingEntity(id,
	_position,
	_scale,
	_velocity,
	_max_speed,
	Vector2D(sin(_rotation), -cos(_rotation)),
	_mass,
	Vector2D(_scale, _scale),
	_max_turn_rate,
	_max_force),
	smoothedHeading(Vector2D(0, 0)),
	smoothingOn(false),
	timeElapsed(0.0)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Vehicle::~Vehicle()
{
}