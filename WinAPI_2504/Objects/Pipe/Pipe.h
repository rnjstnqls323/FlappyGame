#pragma once

class Pipe :public RectCollider
{
public:
	Pipe();
	Pipe(float sizeY);
	~Pipe();

	void Update();
	void Render();


protected:
	void Init() {
		CreatePipe();
	}

private:
	virtual void CreatePipe() = 0;
protected:
	Quad* pipe;
};