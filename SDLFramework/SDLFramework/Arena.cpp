#include "Arena.h"
#include "Parameters.h"




Cow* Arena::cow;
Rabbit* Arena::rabbit;

Arena::Arena()
{
	

	mApplication->AddRenderable(this);
	

	Vector2D spawnPosition1 = Vector2D(300.0, 320.0);
	Vector2D spawnPosition2 = Vector2D(1200.0, 320.0);


	cow = new Cow(1,
		spawnPosition1,										//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200, 100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		Parameters::Instance()->SteeringForce * 
		Parameters::Instance()->SteeringForceTweaker,		//max force
		Parameters::Instance()->MaxSpeed,					//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale);				//scale
	
	rabbit = new Rabbit(2,
		spawnPosition2,										//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200,100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		(Parameters::Instance()->SteeringForce *
		Parameters::Instance()->SteeringForceTweaker),	//max force
		Parameters::Instance()->MaxSpeed,				//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale);				//scale

	//predator->Steering()->PursuitOn(prey);
//	cow->SetScale(Vector2D(30, 30));
//	rabbit->SetScale(Vector2D(30, 30));

	//predator->Steering()->CreateRandomPath(3, 100, 200, 300, 400);
	//predator->Steering()->FollowPathOn();
	//cow->Steering()->PursuitOn(prey);
	
	//prey->Steering()->FleeOn();
	//prey->Steering()->WanderOn();
	
	
	//prey->SetScale(Vector2D(10, 10));
	//prey->Steering()->EvadeOn(cow);
	//prey->SetMaxSpeed(70);
	//prey->Steering()->ArriveOn();

}


Arena::~Arena()
{

}

void Arena::Update(float deltaTime)
{
	
}