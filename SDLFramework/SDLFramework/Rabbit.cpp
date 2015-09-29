#include "Rabbit.h"
#include "Graph.h"
#include "RabbitWanderingState.h"
Rabbit::Rabbit(int id) : BaseGameEntity(id)
{
	mTexture = mApplication->LoadTexture("rabbit-3.png");
	setCurrentNode(Graph::graphNodes.at(rand() % 8));					// Put the rabbit on a random node on the screen
	pickedUpPill = false;
	pickedUpWeapon = false;
	mApplication->AddRenderable(this);

	stateMachine = new StateMachine<Rabbit>(this);
	stateMachine->SetCurrentState(RabbitWanderingState::Instance());
}

Rabbit::~Rabbit()
{
}

void Rabbit::Update(float deltaTime)
{
	stateMachine->Update();
}

// Draw the rabbit texture
void Rabbit::Draw()
{
	mApplication->DrawTexture(mTexture, mX, mY, 100, 100);
}

// Execute code if rabbit has been left-clicked upon
void Rabbit::OnLeftClick()
{
	printf("Left-clicked on rabbit!\n");
}

// Execute code if rabbit has been right-clicked upon
void Rabbit::OnRightClick()
{
	printf("Right-clicked on rabbit!\n");
}

void Rabbit::setCurrentNode(Node* node)
{
	currentNode = node;
	mX = node->GetBoundingBox().x;
	mY = node->GetBoundingBox().y;
}