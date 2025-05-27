#include "Framework.h"

UpPipe::UpPipe()
{
	Init();
}

UpPipe::~UpPipe()
{
	delete pipe;
}

void UpPipe::CreatePipe()
{
	pipe = new Quad(L"Resources/Textures/UpPipe.png");
	pipe->SetParent(this);
}
