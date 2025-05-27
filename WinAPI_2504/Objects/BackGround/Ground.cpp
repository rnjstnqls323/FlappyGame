#include "Framework.h"

Ground::Ground():RectCollider({SCREEN_WIDTH,200})
{
	SetLocalPosition({ CENTER.x,WALL_Y });
	UpdateWorld();

	CreateFrames();
}

Ground::~Ground()
{
	for (Quad*& frame : frames)
	{
		delete frame;
	}
}

void Ground::Update()
{
	for (Quad*& frame : frames)
	{
		Move(frame);
		frame->UpdateWorld();
	}
}

void Ground::Render()
{
	for (Quad*& frame : frames)
	{
		frame->Render();
	}
	RectCollider::Render();
}

void Ground::BirdCollision(Bird* bird)
{
	if (IsRectCollision(bird, nullptr))
	{
		bird->BirdDie();
	}
}

void Ground::CreateFrames()
{
	frames.resize(MAX_FRAME);
	int count = -1;
	for (Quad*& frame : frames)
	{
		frame = new Quad(L"Resources/Textures/Ground.png");
		frame->SetLocalPosition({ CENTER.x + (count++ * frame->GetSize().x), WALL_Y });
	}
}

void Ground::Move(Quad* frame)
{
	Vector2 framePos = frame->GetLocalPosition();
	float newX = framePos.x - MOVE_X * DELTA;
	float halfSizeX = frame->GetSize().x * 0.5;
	if (newX + halfSizeX < 0)
	{
		float curX = frame->GetLocalPosition().x;
		curX += frame->GetSize().x * MAX_FRAME - halfSizeX;
		frame->SetLocalPosition({ curX ,framePos.y });
	}
	else
		frame->SetLocalPosition({ newX,framePos.y });
}
