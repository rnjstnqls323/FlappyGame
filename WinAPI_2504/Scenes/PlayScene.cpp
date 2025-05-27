#include "Framework.h"
#include "PlayScene.h"

PlayScene::PlayScene()
{
	PipeManager::Get();

	bird = new Bird();
	bird->SetLocalPosition(CENTER);
	backGround = new BackGround();
	ground = new Ground();

}

PlayScene::~PlayScene()
{
	PipeManager::Delete();
	
	delete bird;
	delete backGround;
	delete ground;
}

void PlayScene::Update()
{
	PipeOnTime();
	PipeManager::Get()->Update();

	bird->Update();
	backGround->Update();
	ground->Update();

	PipeManager::Get()->BirdCollision(bird);
	ground->BirdCollision(bird);
}

void PlayScene::Render()
{
	backGround->Render();
	PipeManager::Get()->Render();
	ground->Render();



	bird->Render();
}

void PlayScene::PipeOnTime()
{
	pipeOnTimer += DELTA;
	if (pipeOnTimer > PIPE_ON_TIME)
	{
		pipeOnTimer -= PIPE_ON_TIME;
		PipeManager::Get()->SetPipe();
	}
}
