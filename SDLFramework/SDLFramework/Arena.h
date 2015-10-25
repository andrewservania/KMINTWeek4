#pragma once
#include "Cow.h"
#include "Rabbit.h"
#include "Vehicle.h"
#include "CellSpacePartition.h"

class Arena
{
public:
	static Cow*cow;
	static Rabbit*rabbit;

	Arena();
	~Arena();

	static Arena* Instance()
	{
		static Arena instance;

		return &instance;
	}
};
