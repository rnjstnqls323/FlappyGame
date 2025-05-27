#include "Framework.h"

PipeManager::PipeManager()
{
	upPipes.resize(PIPE_POOL_SIZE);
	downPipes.resize(PIPE_POOL_SIZE);

	for (UpPipe*& pipe : upPipes)
	{
		pipe = new UpPipe();
		pipe->SetActive(false);
	}
	for (DownPipe*& pipe : downPipes)
	{
		pipe = new DownPipe();
		pipe->SetActive(false);
	}
}

PipeManager::~PipeManager()
{
	for (UpPipe*& pipe : upPipes)
	{
		delete pipe;
	}
	for (DownPipe*& pipe : downPipes)
	{
		delete pipe;
	}
}

bool PipeManager::IsOut(Pipe* pipe)
{
	float x = pipe->GetLocalPosition().x + pipe->Size().x*0.5f;
	if (x < 0)
		return true;
	return false;
}

void PipeManager::Move(Pipe* pipe)
{
	Vector2 pos = pipe->GetLocalPosition();
	pos.x -= SPEED * DELTA;
	pipe->SetLocalPosition(pos);
}

void PipeManager::BirdCollision(Bird* bird)
{
	for (UpPipe*& pipe : upPipes)
	{
		if (!pipe->IsActive())
			continue;
		if (pipe->IsRectCollision(bird, nullptr))
		{
			bird->BirdDie();
			isMove = false;
		}
	}
	for (DownPipe*& pipe : downPipes)
	{
		if (!pipe->IsActive())
			continue;
		if (pipe->IsRectCollision(bird, nullptr))
		{
			bird->BirdDie();
			isMove = false;
		}
	}
}

void PipeManager::SetPipe()
{
	int randNum = rand() % (SCREEN_WIDTH - SPACE_AREA);

	if (randNum < 200) randNum += 200;

	for (UpPipe*& pipe : upPipes)
	{
		if (pipe->IsActive())
			continue;
		pipe->SetActive(true);
		pipe->SetLocalPosition({ SCREEN_WIDTH,(float)randNum });
		break;
	}
	for (DownPipe*& pipe : downPipes)
	{
		if (pipe->IsActive())
			continue;
		pipe->SetActive(true);
		float pipeSizeY = pipe->Size().y;
		pipe->SetLocalPosition({ SCREEN_WIDTH,(float)randNum+SPACE_AREA+ pipeSizeY });
		break;
	}
}

void PipeManager::Update()
{
	for (UpPipe*& pipe : upPipes)
	{
		if (!pipe->IsActive())
			continue;
		if (IsOut(pipe))
		{
			pipe->SetActive(false);
			continue;
		}
		if (!isMove)
			continue;
		Move(pipe);
		pipe->Update();
	}
	for (DownPipe*& pipe : downPipes)
	{
		if (!pipe->IsActive())
			continue;
		if (IsOut(pipe))
		{
			pipe->SetActive(false);
			continue;
		}
		if (!isMove)
			continue;
		Move(pipe);
		pipe->Update();
	}
}

void PipeManager::Render()
{
	for (UpPipe*& pipe : upPipes)
	{
		if (!pipe->IsActive())
			continue;
		pipe->Render();
	}
	for (DownPipe*& pipe : downPipes)
	{
		if (!pipe->IsActive())
			continue;
		pipe->Render();
	}
}
