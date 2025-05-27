#pragma once

class Ground : public RectCollider
{

private:
	const float WALL_Y = 100.0f;
	const int MAX_FRAME = 4;
	//const float FRAME_TIME = 0.1f;
	const float MOVE_X = 150.0f;
public:
	Ground();
	~Ground();

	void Update();
	void Render();
	void BirdCollision(Bird* bird);

private:
	void CreateFrames();
	void Move(Quad* frame);
private:

	vector<Quad*> frames;
};