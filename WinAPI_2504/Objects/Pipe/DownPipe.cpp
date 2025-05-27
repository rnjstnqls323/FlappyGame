#include "Framework.h"

DownPipe::DownPipe():Pipe((SCREEN_HEIGHT - 50) * 0.5f)
{
	Init();
}

DownPipe::~DownPipe()
{
}

void DownPipe::CreatePipe()
{
	pipe = new Quad(L"Resources/Textures/DownPipe.png");
	pipe->SetParent(this);
}
