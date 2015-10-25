#include "Cow.h"
#include <string>
#include <memory>
#include <assert.h>
#include "CowPursuitState.h"
#include "Parameters.h"

using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
/// Create a cow by providing an identifier, a position a, rotation value, a velocity value,
/// a mass, a maximum force, a maximum speed, a maximum turn rate, a scale value and an enemy,
/// in this case a rabbit.
///
/// The cow is created by
/// 1) being added to items that need to in the Arena,
/// 2) setting its score to 0
/// 3) loading a cow picture
/// 4) giving it a steering behavior
/// 5) setting a heading smoother
/// 6) giving it a set of random percentage values on the chances for its choices (Probability distribution)
/// 7) give it a state machine
/// 8) set the state machine to an initial global state
/// 9) set the cow's color to "nothing"
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
/// <param name="_enemy">		 	[in,out] If non-null, the enemy. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

Cow::Cow(int id,
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
	//smoothedHeading = Vector2D(0, 0);
	//smoothingOn = false ;
	//timeElapsed = 0.0;

	//Load the picture corresponding to the cow
	mTexture = mApplication->LoadTexture("cow-1.png");

	// set the location of the cow on the screen
	mX = static_cast<uint32_t>(position.x);
	mY = static_cast<uint32_t>(position.y);

	// set up the steering behavior class
	steering = new SteeringBehavior(this);

	//set up the smoother
	headingSmoother = new Smoother<Vector2D>(Parameters::Instance()->NumSamplesForSmoothing, Vector2D(0.0, 0.0));

	//add cow to renderable objects

	// Add sample code here that is responsible for updating the cow
	// Set up the state machine
	stateMachine = new StateMachine<Cow>(this);
	stateMachine->SetCurrentState(CowPursuitState::Instance());
	//stateMachine->SetGlobalState()
	mApplication->AddRenderable(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the cow with a given deltaTime. </summary>
///
/// 1) The current state of the cow is updated.
/// 2) The force-driven speed of the cow is calculated and regulated
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="deltaTime">	The delta time. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::Update(float deltaTime)
{
	stateMachine->Update();

	timeElapsed = static_cast<double>(deltaTime);

	// calculate the combined force from each steering behavior in the vehicle's list
	Vector2D SteeringForce = steering->Calculate();

	// Accelaration = Force/Mass
	Vector2D acceleration = SteeringForce / mass;

	// update velocity
	velocity += acceleration * timeElapsed;

	// make sure vehicle does not exceed maximum velocity
	velocity.Truncate(maxSpeed);

	// update the position
	position += velocity * timeElapsed;

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
/// <summary>	Destructor. </summary>
///
///  The state machine is deleted.
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Cow::~Cow()
{
	delete stateMachine;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draws the picture of the cow on screen. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Cow::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 100, 100);
}