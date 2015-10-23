#include "Arena.h"
#include "Parameters.h"




/// <summary>	The cow. </summary>
Cow* Arena::cow;
/// <summary>	The rabbit. </summary>
Rabbit* Arena::rabbit;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. 
/// 			
/// 			Create a cow and a rabbit and put them on a random location in the arena.  
/// </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Arena::Arena()
{
	cow = new Cow(1,
		Vector2D(rand() % 1300, rand() % 700),				//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200, 100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		Parameters::Instance()->SteeringForce * 
		Parameters::Instance()->SteeringForceTweaker,		//max force
		Parameters::Instance()->MaxSpeed,					//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale);				//scale
	
	rabbit = new Rabbit(2,
		Vector2D(rand() % 1300, rand() % 700),				//initial position
		RandFloat()*TwoPi,									//start rotation
		Vector2D(200,100),									//velocity
		Parameters::Instance()->VehicleMass,				//mass
		(Parameters::Instance()->SteeringForce *
		Parameters::Instance()->SteeringForceTweaker),		//max force
		Parameters::Instance()->MaxSpeed,					//max velocity
		Parameters::Instance()->MaxTurnRate,				//max turn rate
		Parameters::Instance()->VehicleScale);				//scale
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Andrew Servania,. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Arena::~Arena()
{

}

