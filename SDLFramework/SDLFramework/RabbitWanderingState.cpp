#include "RabbitWanderingState.h"
#include "Arena.h"
#include "RabbitFleeingState.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

RabbitWanderingState::RabbitWanderingState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

RabbitWanderingState::~RabbitWanderingState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right after entering the state.
/// 			Set the rabbit's maximum speed to 150.0 Call the Start() function. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitWanderingState::Enter(Rabbit* rabbit)
{
	rabbit->SetMaxSpeed(150);
	Start(rabbit);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A check is done to determine the rabbit already started wandering around. If not,
/// 			the rabbit will start wondering around.
/// 			If the rabbit comes into threat by the cow. The rabbit's statechanges to a Fleeing
/// 			state.
/// 			 </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitWanderingState::Execute(Rabbit* rabbit)
{
	if (hasStarted = false)
	{
		Start(rabbit);
		hasStarted = true;
	}
	if (IsThreatEminent(rabbit))
		rabbit->GetFSM()->ChangeState(RabbitFleeingState::Instance());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right before exiting the state. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitWanderingState::Exit(Rabbit* rabbit)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Create a path for the rabbit to wander around on. instruct the rabbit's steering
/// 			behavior to start following that path. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitWanderingState::Start(Rabbit* rabbit)
{
	Arena::Instance()->rabbit->Steering()->CreateRandomPath(3, 250, 250, 350, 350);
	Arena::Instance()->rabbit->Steering()->FollowPathOn();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Query if 'rabbit' is threat eminent. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
///
/// <returns>	true if threat eminent, false if not. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool RabbitWanderingState::IsThreatEminent(Rabbit* rabbit)
{
	float distanceBetweenCowAndRabbit = rabbit->DistanceTo(Arena::Instance()->cow);
	if (distanceBetweenCowAndRabbit <= 200)
		return true;
	else
		return false;
}