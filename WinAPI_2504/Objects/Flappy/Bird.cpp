#include "Framework.h"

Bird::Bird() : RectCollider(Vector2(50, 50))
{	
	CreateFrames();
}

Bird::~Bird()
{
	for (Quad* frame : frames)
	{
		delete frame;
	}	
}

void Bird::Update()
{
	Gravity();
	FrameUpdate();	

	UpdateWorld();
	frames[curFrame]->UpdateWorld();

	CheckUpDown();
	CheckRotTime();
}

void Bird::Render()
{	
	frames[curFrame]->Render();
	//Collider::Render();
}

void Bird::StartUpdate()
{
	FrameUpdate();

	UpdateWorld();
	frames[curFrame]->UpdateWorld();
}

void Bird::BirdDie()
{
	if (isDead)
		return;
	//각도 돌리기
	for (Quad* frame : frames)
	{
		frame->SetRotationZ(PI);
		//frame->SetScale({1, -1}); => 이거하면 잘 뒤집히긴하는데, 안타깝게도 뒷면은 구현 안해놔서 출력아예없다.
	}
	isDead = true;
}

void Bird::FrameUpdate()
{
	frameTimer += DELTA;

	if (frameTimer >= FRAME_TIME)
	{
		frameTimer -= FRAME_TIME;

		curFrame = ++curFrame % FRAME_SIZE;
	}
}

void Bird::Gravity()
{
	if (Input::Get()->IsKeyDown(VK_SPACE) && !isDead)
	{
		velocity.y = JUMP_POWER;
		ChangeRotation(PI * 0.1f);
		rotTimer = 0.0f;
	}
	
	velocity.y -= GRAVITY * DELTA;
	localPosition.y += velocity.y * DELTA;	
}

void Bird::CreateFrames()
{
	for (int i = 0; i < FRAME_SIZE; i++)
	{
		Quad* frame = new Quad(L"Resources/Textures/Bird.png", Vector2(i / 3.0f, 0.0f), Vector2((i + 1.0f) / 3.0f, 1.0f));
		frame->SetParent(this);
		frames.push_back(frame);
	}
}

void Bird::CheckRotTime()
{
	if (isDead)
		return;
	rotTimer += DELTA;
	if (rotTimer > ROT_TIME)
	{
		rotTimer -= ROT_TIME;
		ChangeRotation(PI * -0.1f);
	}
	else if (rotTimer > 0.4f)
	{
		ChangeRotation(0);
	}
}

void Bird::CheckUpDown()
{
	Vector2 pos = GetGlobalPosition();
	if (pos.y < 0)
	{
		SceneManager::Get()->ChangeScene("GameOver");
	}
	if (pos.y > SCREEN_WIDTH+200) // 이렇게 줘야 하늘 닿는 위치랑 같다.
	{
		BirdDie();
	}
}

void Bird::ChangeRotation(float rot)
{
	for (Quad* frame : frames)
	{
		frame->SetRotationZ(rot);
	}
}
