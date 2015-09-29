#include "Dashboard.h"
#include "FWApplication.h"
#include "Arena.h"
#include "ProbabilityDistribution.h"

std::string Dashboard::applicationInformation;
std::string Dashboard::shortestPathLabel;
std::string Dashboard::cowStateLabel;
std::string Dashboard::rabbitStateLabel;

std::string Dashboard::comment1;
std::string Dashboard::comment2;
std::string Dashboard::comment3;
std::string Dashboard::comment4;
std::string Dashboard::comment5;
std::string Dashboard::comment6;
std::string Dashboard::comment7;
std::string Dashboard::comment8;
std::string Dashboard::comment9;
std::string Dashboard::comment10;
std::string Dashboard::comment11;
std::string Dashboard::comment12;
std::string Dashboard::comment13;


std::string Dashboard::choice1Probability;
std::string Dashboard::choice2Probability;
std::string Dashboard::choice3Probability;

std::string Dashboard::cowSleepingTurns;
using namespace std;

Dashboard::Dashboard()
{
	ApplicationInformation("Andrew Servania - KMINT Week 4");

	comment1 = "";
	comment2 = "";
	comment3 = "";

	comment4 = "";
	comment5 = "";
	comment6 = "";
	comment7 = "";
	comment8 = "";
	comment9 = "";

	comment10 = "";
	comment11 = "";
	comment12 = "";
	comment13 = "";


  //comment6 = "-------------------------------------------------------------------------------------------";
	//ShortestPathLabel("");

	SetChoice1Probablity(ProbabilityDistribution::Instance()->GetChoice1Probability());
	SetChoice2Probablity(ProbabilityDistribution::Instance()->GetChoice2Probability());
	SetChoice3Probablity(ProbabilityDistribution::Instance()->GetChoice3Probability());

	cowSleepingTurns = "Cow Sleeping Turns: 0";
}

Dashboard::~Dashboard()
{
}

void Dashboard::Update()
{
	// Application information
	FWApplication::GetInstance()->DrawText(applicationInformation, 300, 50);

	// KMINT Week 3 Description
	FWApplication::GetInstance()->DrawText(comment1, 300, 100);
	FWApplication::GetInstance()->DrawText(comment2, 300, 120);
	FWApplication::GetInstance()->DrawText(comment3, 300, 140);
	FWApplication::GetInstance()->DrawText(comment4, 300, 180);
	FWApplication::GetInstance()->DrawText(comment5, 300, 200);
	FWApplication::GetInstance()->DrawText(comment6, 300, 220);
	FWApplication::GetInstance()->DrawText(comment7, 300, 240);
	FWApplication::GetInstance()->DrawText(comment8, 300, 260);
	FWApplication::GetInstance()->DrawText(comment9, 300, 280);
	FWApplication::GetInstance()->DrawText(comment10, 300, 320);
	FWApplication::GetInstance()->DrawText(comment11, 300, 340);
	FWApplication::GetInstance()->DrawText(comment12, 300, 360);
	FWApplication::GetInstance()->DrawText(comment13, 300, 380);

	// Cow state label
	CowStateLabel(Arena::cow->GetCurrentState());
	FWApplication::GetInstance()->DrawText(cowStateLabel, 300, 420);


	// Rabbit state label
	RabbitStateLabel(Arena::rabbit->GetCurrentState());
	FWApplication::GetInstance()->DrawText(rabbitStateLabel, 300, 460);

	// Shortest path label
	FWApplication::GetInstance()->DrawText(shortestPathLabel, 300, 500);

	// Probabilities
	//FWApplication::GetInstance()->DrawText(choice1Probability, 300, 540);
	//FWApplication::GetInstance()->DrawText(choice2Probability, 300, 560);
	//FWApplication::GetInstance()->DrawText(choice3Probability, 300, 580);

}