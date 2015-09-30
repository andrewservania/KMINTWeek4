#pragma once
#include "IGameObject.h"
#include "Vector2D.h"
class BaseGameEntity :
	public IGameObject
{
private:

	int id;										// Every entity has a unique identifying number

	static int nextValidID;						// This is the next valid ID. Each time a BaseGameEntity is instantiated
	// this value is updated
	void SetID(int val);

protected:

	// The entity's location within the arena
	Vector2D position;
	Vector2D scale;

	//The length of this object's bounding radius
	double boundingRadius;
public:
	BaseGameEntity(int id);
	virtual ~BaseGameEntity();
	virtual void Update(float deltaTime) = 0;
	int ID() const{ return id; }
};
