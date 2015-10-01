#include "Arena.h"
#include "Parameters.h"
Cow* Arena::cow;
Rabbit* Arena::rabbit;
Vehicle* Arena::predator;
Vehicle* Arena::prey;


Arena::Arena()
{
	cow = new Cow(1);
	rabbit = new Rabbit(2);
	mApplication->AddRenderable(this);

	Vector2D spawnPosition1 = Vector2D(300.0, 320.0);
	Vector2D spawnPosition2 = Vector2D(1200.0, 320.0);

	predator = new Vehicle(3,
		spawnPosition1,										//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200, 100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		Parameters::Instance()->SteeringForce * 
		Parameters::Instance()->SteeringForceTweaker,		//max force
		Parameters::Instance()->MaxSpeed,					//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale);				//scale
	
	prey = new Vehicle(4,
		spawnPosition2,										//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(0, 0),										//velocity
		Parameters::Instance()->VehicleMass,				//mass
		(Parameters::Instance()->SteeringForce *
		Parameters::Instance()->SteeringForceTweaker)*2,	//max force
		Parameters::Instance()->MaxSpeed,					//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale);				//scale

	predator->Steering()->PursuitOn(prey);
	predator->SetScale(Vector2D(30, 30));
	
	prey->Steering()->EvadeOn(predator);
	prey->SetScale(Vector2D(10, 10));



}


Arena::~Arena()
{
}

void Arena::Update(float deltaTime)
{

}