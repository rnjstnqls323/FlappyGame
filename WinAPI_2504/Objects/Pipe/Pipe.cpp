#include "Framework.h"

Pipe::Pipe():RectCollider({ 90,(SCREEN_HEIGHT - 150) * 0.5f }) //UpPipe충돌위치 맞춘거
{
}

Pipe::Pipe(float sizeY):RectCollider({90,sizeY})
{
}

Pipe::~Pipe()
{
	delete pipe;
}

void Pipe::Update()
{
	UpdateWorld();
	pipe->UpdateWorld();
}

void Pipe::Render()
{
	pipe->Render();
	//RectCollider::Render();
}
