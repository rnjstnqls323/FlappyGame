#include "Framework.h"
#include "BackGround.h"

BackGround::BackGround()//:RectCollider(Vector2(SCREEN_WIDTH,SCREEN_HEIGHT))
{
	//SetLocalPosition(CENTER);
	//UpdateWorld();

	CreateFrames();
	
}

BackGround::~BackGround()
{
	for (Quad*& frame : frames)
	{
		delete frame;
	}
}

void BackGround::Update()
{
	//frameTimmer += DELTA;
	//
	//if (frameTimmer > FRAME_TIME)
	//{
	//	for (Quad*& frame : frames)
	//	{
	//		Move(frame);
	//		frame->UpdateWorld();
	//	}
	//	frameTimmer -= FRAME_TIME;
	//}
	
	for (Quad*& frame : frames)
	{
		Move(frame);
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

void BackGround::Move(Quad* frame)
{
	Vector2 framePos = frame->GetLocalPosition();
	float newX = framePos.x - MOVE_X * DELTA;
	float halfSizeX = frame->GetSize().x *0.5;
	if (newX + halfSizeX < 0)
	{
		float curX = frame->GetLocalPosition().x;
		curX += frame->GetSize().x* MAX_FRAME - halfSizeX;
		frame->SetLocalPosition({ curX ,framePos.y });
	}
	else
		frame->SetLocalPosition({ newX,framePos.y});
}
