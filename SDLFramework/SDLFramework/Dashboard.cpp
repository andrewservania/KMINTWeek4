#include "Dashboard.h"
#include "FWApplication.h"
#include "Arena.h"

/// <summary>	Information describing the dashboard application. </summary>
std::string Dashboard::applicationInformation;
/// <summary>	The dashboard cow state label. </summary>
std::string Dashboard::cowStateLabel;
/// <summary>	The dashboard rabbit state label. </summary>
std::string Dashboard::rabbitStateLabel;
/// <summary>	The dashboard cow sleeping turns. </summary>
std::string Dashboard::cowSleepingTurns;

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Dashboard::Dashboard()
{
	ApplicationInformation("Andrew Servania - KMINT Week 4");

	cowSleepingTurns = "Cow Sleeping Turns: 0";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Dashboard::~Dashboard()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the statistics on screen </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Dashboard::Update()
{
	// Application information
	FWApplication::GetInstance()->DrawTextOnScreen(applicationInformation, 650, 50);

	// Cow state label
	CowStateLabel(Arena::cow->GetCurrentState());
	FWApplication::GetInstance()->DrawTextOnScreen(cowStateLabel, 650, 90);

	// Rabbit state label
	RabbitStateLabel(Arena::rabbit->GetCurrentState());
	FWApplication::GetInstance()->DrawTextOnScreen(rabbitStateLabel, 650, 110);
}