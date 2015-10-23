#pragma once
#include <string>

class Dashboard
{
private:
	static std::string applicationInformation;
	static std::string cowStateLabel;
	static std::string rabbitStateLabel;
	static std::string cowSleepingTurns;

public:

	Dashboard();
	~Dashboard();
	void Update();

	// Accessors
	std::string ApplicationInformation() const { return applicationInformation; }
	std::string CowStateLabel() const { return cowStateLabel; }
	std::string RabbitStateLabel() const { return rabbitStateLabel; }

	void ApplicationInformation(std::string val) { applicationInformation = val; }
	void CowStateLabel(std::string val) { cowStateLabel = "Cow State: " + val; }
	void RabbitStateLabel(std::string val) { rabbitStateLabel = "Rabbit state: " + val; }
	void SetCowSleepingTurns(int val) { cowSleepingTurns = "Cow Sleeping Turns: " + std::to_string(val); }

	static Dashboard* Instance()
	{
		static Dashboard instance;
		return &instance;
	}
};
