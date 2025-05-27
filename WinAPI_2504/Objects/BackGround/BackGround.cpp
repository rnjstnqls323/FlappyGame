#include "Framework.h"
#include "BackGround.h"

BackGround::BackGround():RectCollider(Vector2(SCREEN_WIDTH,SCREEN_HEIGHT))
{
	SetLocalPosition(CENTER);
	UpdateWorld();

	CreateFrames();
	
}

BackGround::~BackGround()
{
}

void BackGround::Update()
{
	for (Quad*& frame : frames)
	{
		frame->UpdateWorld();
	}
}

void BackGround::Render()
{
	for (Quad*& frame : frames)
	{
		frame->Render();
	}
}

void BackGround::CreateFrames()
{
	frames.resize(MAX_FRAME);
	int count = -1;
	for (Quad*& frame : frames)
	{
		frame = new Quad(L"Resources/Textures/BackGround.png");
		frame->SetLocalPosition({ CENTER.x + (count++ * frame->GetSize().x), CENTER.y });
	}
}
