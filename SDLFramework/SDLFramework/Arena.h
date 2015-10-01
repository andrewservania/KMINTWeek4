#pragma once
#include "IGameObject.h"
#include "Cow.h"
#include "Rabbit.h"
#include "Vehicle.h"

class Arena : public IGameObject
{
private:

public:
	 static Cow*cow;
	 static Rabbit*rabbit;

	 static Vehicle*predator;
	 static Vehicle*prey;

	Arena();
	~Arena();
	void Update(float deltaTime) override;

};

