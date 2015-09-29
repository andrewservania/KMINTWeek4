#pragma once
#include "IGameObject.h"
#include "Cow.h"
#include "Rabbit.h"

class Arena : public IGameObject
{
private:

public:
	 static Cow*cow;
	 static Rabbit*rabbit;
	Arena();
	~Arena();

	void Update(float deltaTime) override;
};

