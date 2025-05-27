#pragma once

class Bird : public RectCollider
{
private:
	const UINT FRAME_SIZE = 3;
	const float FRAME_TIME = 0.1f; // 100ms per frame
	const float ROT_TIME = 1.0f;
	const float GRAVITY = 980.0f; // Gravity force applied to the bird
	const float JUMP_POWER = 500.0f;

public:
	Bird();
	~Bird();

	void Update();
	void Render();
	
	void StartUpdate();

	void BirdDie();

private:
	void FrameUpdate();
	void Gravity();
	void CreateFrames();
	void CheckRotTime();
	void CheckUpDown();
	void ChangeRotation(float rot);

private:	
	UINT curFrame = 1;
	float frameTimer = 0.0f;
	float rotTimer = 0.0f;
	bool isDead = false;

	vector<Quad*> frames;

	Vector2 velocity;
};