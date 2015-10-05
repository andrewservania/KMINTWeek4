#include "Arena.h"
#include "Parameters.h"




//Cow* Arena::cow;
Rabbit* Arena::rabbit;
CellSpacePartition<Vehicle*>*  Arena::cellSpace;
std::vector<Vehicle*> Arena::aBunchOfCows;
Arena::Arena()
{
	agentID = 0;
	cellSpace = new CellSpacePartition<Vehicle*>((double)1300.0, (double)700.0, 
		Parameters::Instance()->NumCellsX, 
		Parameters::Instance()->NumCellsY,
		Parameters::Instance()->NumAgents);

	agentID++;
	rabbit = new Rabbit(agentID,
		Vector2D(rand() % 1300, rand() % 700),				//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200,100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		(Parameters::Instance()->SteeringForce *
		Parameters::Instance()->SteeringForceTweaker),		//max force
		Parameters::Instance()->MaxSpeed,					//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale);				//scale


	InitializeAgent(cow0);
	InitializeAgent(cow1);
	InitializeAgent(cow2);
	InitializeAgent(cow3);
	InitializeAgent(cow4);
	InitializeAgent(cow5);
	InitializeAgent(cow6);
	InitializeAgent(cow7);
	InitializeAgent(cow8);
	InitializeAgent(cow9);

	//cow = new Cow(1,
	//	spawnPosition1,										//initial position
	//	RandFloat()*TwoPi,									//start rotation
	//	Vector2D(200, 100),									//velocity
	//	Parameters::Instance()->VehicleMass,				//mass
	//	Parameters::Instance()->SteeringForce * 
	//	Parameters::Instance()->SteeringForceTweaker,		//max force
	//	Parameters::Instance()->MaxSpeed,					//max velocity
	//	Parameters::Instance()->MaxTurnRate,				//max turn rate
	//	Parameters::Instance()->VehicleScale);				//scale
	

	//cellSpace->AddEntity(cow0);
	//cellSpace->AddEntity(cow1);
	//cellSpace->AddEntity(cow2);
	//cellSpace->AddEntity(cow3);
	//cellSpace->AddEntity(cow4);
	//cellSpace->AddEntity(cow5);
	//cellSpace->AddEntity(cow6);
	//cellSpace->AddEntity(cow7);
	//cellSpace->AddEntity(cow8);
	//cellSpace->AddEntity(cow9);

	cellSpace->AddEntity(rabbit);
	


	//cow0->Steering()->PursuitOn(rabbit);
	//cow1->Steering()->PursuitOn(rabbit);
	//cow2->Steering()->PursuitOn(rabbit);
	//cow3->Steering()->PursuitOn(rabbit);
	//cow4->Steering()->PursuitOn(rabbit);
	//cow5->Steering()->PursuitOn(rabbit);
	//cow6->Steering()->PursuitOn(rabbit);
	//cow7->Steering()->PursuitOn(rabbit);
	//cow8->Steering()->PursuitOn(rabbit);
	//cow9->Steering()->PursuitOn(rabbit);


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

void Arena::InitializeAgent(Cow* cow)
{
	agentID++;
	cow = new Cow(agentID,
		Vector2D(rand() % 1300, rand() % 700),				//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200, 100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		Parameters::Instance()->SteeringForce *
		Parameters::Instance()->SteeringForceTweaker,		//max force
		Parameters::Instance()->MaxSpeed,					//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale);				//scale

	
	aBunchOfCows.push_back(cow);
	cellSpace->AddEntity(cow);
}
