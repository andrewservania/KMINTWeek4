#include "Rabbit.h"
#include "RabbitWanderingState.h"
#include "Parameters.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. Create a rabbit by providing the an ID, a position vector, a rotation
/// 			value, a velocity vector, a mass value, a maximum force, a maximum speed, a maximum
/// 			turn rate and a scale.
///
/// 			During the instantiation of rabbit the following actions will be taken:
/// 			2) the rabbit will be given a steering behavior
/// 			3) the heading smoother will be instantiated
/// 			4) the rabbit will be added to items that must be shown on screen
/// 			5) the rabbit will be given a state machine
/// 			6) the rabbit's state will be set to a Wandering state
/// 		     </summary>
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

Rabbit::Rabbit(int id,
	Vector2D _position,
	double _rotation,
	Vector2D _velocity,
	double _mass,
	double _max_force,
	double _max_speed,
	double _max_turn_rate,
	double _scale) : Vehicle(id,
	_position,
	_rotation,
	_velocity,
	_mass,
	_max_force,
	_max_speed,
	_max_turn_rate,
	_scale)
{
	mTexture = mApplication->LoadTexture("rabbit-3.png");

	// set the location of the cow on the screen
	mX = static_cast<uint32_t>(position.x);
	mY = static_cast<uint32_t>(position.y);

	// set up the steering behavior class
	steering = new SteeringBehavior(this);

	//set up the smoother
	headingSmoother = new Smoother<Vector2D>(Parameters::Instance()->NumSamplesForSmoothing, Vector2D(0.0, 0.0));

	//add cow to renderable objects
	mApplication->AddRenderable(this);

	// Add sample code here that is responsible for updating the cow
	// Set up the state machine
	stateMachine = new StateMachine<Rabbit>(this);
	stateMachine->SetCurrentState(RabbitWanderingState::Instance());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Rabbit::~Rabbit()
{
}
////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	The rabbit will be updated
///
/// 			1) The state of the rabbit will be updated.
/// 			2) The force-driven movement of the rabbit will be calculated, regulated and updated
/// 			3) The arena will be treated as toroid, therefore the movement of the rabbit will be
/// 		       regulated to move accordingly. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="deltaTime">	The delta time. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::Update(float deltaTime)
{
	stateMachine->Update();

	double elapsedTime = static_cast<double>(deltaTime);

	// calculate the combined force from each steering behavior in the vehicle's list
	Vector2D SteeringForce = steering->Calculate();

	// Accelaration = Force/Mass
	Vector2D acceleration = SteeringForce / mass;

	// update velocity
	velocity += acceleration * elapsedTime;

	// make sure vehicle does not exceed maximum velocity
	velocity.Truncate(maxSpeed);

	// update the position
	position += velocity * elapsedTime;

	// set the actual location of the vehicle in the arena
	mX = static_cast<uint32_t>(position.x);
	mY = static_cast<uint32_t>(position.y);

	//update the heading if the cow has a velocity greater than a very smal
	//value
	if (velocity.LengthSq() > 0.00000001)
	{
		heading = Vec2DNormalize(velocity);

		side = heading.Perp();
	}

	// treat the screen as a toroid. Current window resolution is 1300x700
	WrapAround(position, 1300, 700);

	if (isSmoothingOn()) smoothedHeading = headingSmoother->Update(Heading());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draw the rabbit texture. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////
void Rabbit::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 100, 100);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> NOT IN USE Trigger an action if the rabbit is left-clicked on.
/// 		  Print in console window
/// 		  </summary>
///
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::OnLeftClick()
{
	printf("Left-clicked on rabbit!\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> NOT IN USE Trigger an action if the rabbit is right-clicked on.
/// 		  Print in console window
/// 		  </summary>
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Rabbit::OnRightClick()
{
	printf("Right-clicked on rabbit!\n");
}