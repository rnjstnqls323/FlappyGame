#pragma once

class BackGround //: public RectCollider
{

private:
	const int MAX_FRAME = 4;
	//const float FRAME_TIME = 0.1f;
	const float MOVE_X = 50.0f ;
public:
	BackGround();
	~BackGround();

	void Update();
	void Render();

private:
	void CreateFrames();
	void Move(Quad* frame);
private:
	//float frameTimmer = 0.0f;
	vector<Quad*> frames;
};