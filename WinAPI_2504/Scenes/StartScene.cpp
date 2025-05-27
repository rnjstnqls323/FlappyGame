#include "Framework.h"
#include "StartScene.h"

StartScene::StartScene()
{
	bird = new Bird();
	bird->SetLocalPosition(CENTER);

	backGround = new BackGround();
	ground = new Ground();
	title = new Quad(L"Resources/Textures/FlappyBird.png");
	title->SetLocalPosition({ CENTER_X,CENTER_Y + 300 });
}

StartScene::~StartScene()
{
	delete bird;
	delete backGround;
	delete ground;
	delete title;
}

void StartScene::Update()
{
	bird->StartUpdate();
	ground->Update();
	backGround->Update();
	title->UpdateWorld();

	if (Input::Get()->IsKeyDown(VK_SPACE))
	{
		SceneManager::Get()->ChangeScene("Game");
	}
}

void StartScene::Render()
{
	backGround->Render();
	ground->Render();
	bird->Render();
	title->Render();
}
