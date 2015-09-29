#pragma once
#include "State.h"
#include "Cow.h"
class CowPursuitState :
	public State<Cow>
{
public:
	CowPursuitState();
	~CowPursuitState();

	void Enter(Cow* cow) override;
	void Execute(Cow* cow) override;
	void Exit(Cow* cow) override;
	std::string GetStateName() override { return "Pursuit"; }
	static CowPursuitState* Instance()
	{
		static CowPursuitState instance;
		return &instance;
	}
};

