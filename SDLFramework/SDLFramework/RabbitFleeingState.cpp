#include "RabbitFleeingState.h"
#include "Arena.h"
#include "RabbitWanderingState.h"
#include "Dashboard.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

RabbitFleeingState::RabbitFleeingState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

RabbitFleeingState::~RabbitFleeingState()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right after entering the state.
/// 			The start() function will be called. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitFleeingState::Enter(Rabbit* rabbit)
{
	Start(rabbit);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Upon calling this function, a check will be done to determine whether
/// 			the rabbit is still under threat by the cow. If there's no threat anymore
/// 			the rabbit will go back to a Wandering state. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitFleeingState::Execute(Rabbit* rabbit)
{
	if (hasStarted == false)
	{
		Start(rabbit);

		hasStarted = true;
	}
	if (NoThreat(rabbit)) rabbit->GetFSM()->ChangeState(RabbitWanderingState::Instance());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take action right after exiting the state.
/// 			The rabbit's maximum speed will be set to its default 150.0.
/// 			The hasStarted flag will be set to false. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitFleeingState::Exit(Rabbit* rabbit)
{
	rabbit->SetMaxSpeed(150.0);
	hasStarted = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Upon calling this function, the rabbit's maximum speed will be set to
/// 			100000.0 and the rabbbit will start evading the cow. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void RabbitFleeingState::Start(Rabbit* rabbit)
{
	//rabbit->Steering()->FleeOn();
	rabbit->SetMaxSpeed(100000.0);
	rabbit->Steering()->EvadeOn(Arena::Instance()->cow);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	No threat. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
///
/// <param name="rabbit">	[in,out] If non-null, the rabbit. </param>
///
/// <returns>	true if it succeeds, false if it fails. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool RabbitFleeingState::NoThreat(Rabbit* rabbit)
{
	float distanceBetweenCowAndRabbit = rabbit->DistanceTo(Arena::Instance()->cow);
	if (distanceBetweenCowAndRabbit >= 600.0)
		return true;
	else
		return false;
}