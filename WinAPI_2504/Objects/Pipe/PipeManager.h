#pragma once

class PipeManager : public Singleton<PipeManager>
{
	friend class Singleton;

private:
	const int SPACE_AREA = 250;
	const int PIPE_POOL_SIZE = 10;
	const float SPEED = 100.0f;

private:
	PipeManager();
	~PipeManager();

	bool IsOut(Pipe* pipe);
	void Move(Pipe* pipe);

public:

	void BirdCollision(Bird* bird);
	void SetPipe();

	void Update();
	void Render();

private:
	bool isMove = true;
	vector<UpPipe*> upPipes;
	vector<DownPipe*> downPipes;
};