#include "RabbitFleeingState.h"
#include "Arena.h"
#include "RabbitWanderingState.h"
#include "Dashboard.h"
RabbitFleeingState::RabbitFleeingState()
{
	//Arena::Instance()->rabbit->Steering()->FleeOn();
	//Arena::Instance()->rabbit->Steering()->EvadeOn(Arena::Instance()->cow);
	//Arena::Instance()->rabbit->SetMaxSpeed(70);
}
RabbitFleeingState::~RabbitFleeingState()
{

}

void RabbitFleeingState::Enter(Rabbit* rabbit)
{
	Start(rabbit);
}

void RabbitFleeingState::Execute(Rabbit* rabbit)
{
	if (hasStarted == false)
	{
		Start(rabbit);

		hasStarted = true;
	}
	if (NoThreat(rabbit)) rabbit->GetFSM()->ChangeState(RabbitWanderingState::Instance());
}

void RabbitFleeingState::Exit(Rabbit* rabbit)
{
	rabbit->SetMaxSpeed(150.0);
	hasStarted = false;
	Dashboard::Instance()->ShortestPathLabel("");
}

void RabbitFleeingState::Start(Rabbit* rabbit)
{
	//rabbit->Steering()->FleeOn();
	rabbit->SetMaxSpeed(100000.0);
	for each(Cow* cow in Arena::aBunchOfCows)
	{
		rabbit->steering->EvadeOn(cow);

	}
}

bool RabbitFleeingState::NoThreat(Rabbit* rabbit)
{
	for each(Cow* cow in Arena::aBunchOfCows)
	{
		float distanceBetweenCowAndRabbit = rabbit->DistanceTo(cow);
		if (distanceBetweenCowAndRabbit >= 600.0)
			return true; 
		else 
			return false;

	}
	return false;
}