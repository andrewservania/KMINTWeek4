#pragma once

#include "Cow.h"
#include "Rabbit.h"
#include "Vehicle.h"
#include "CellSpacePartition.h"

class Arena 
{
private:
	int agentID;
	void InitializeAgent(Cow* cow);

	Cow*cow0;
	Cow*cow1;
	Cow*cow2;
	Cow*cow3;
	Cow*cow4;
	Cow*cow5;
	Cow*cow6;
	Cow*cow7;
	Cow*cow8;
	Cow*cow9;
public:
	  //static Cow*cow;
	  static Rabbit*rabbit;
	  static std::vector<Vehicle*> aBunchOfCows;
	  static CellSpacePartition<Vehicle*>*  cellSpace;

	  static std::vector<Vehicle*>& Agents() { return aBunchOfCows; }
	  static CellSpacePartition<Vehicle*>* CellSpace() { return cellSpace; }
	Arena();
	~Arena();


	static Arena* Instance()
	{
		static Arena instance;

		return &instance;
	}
};

