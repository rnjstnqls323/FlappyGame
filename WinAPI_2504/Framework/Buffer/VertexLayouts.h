#pragma once

struct Vertex//���� : 3���� ���������� �� ��
{
    float x, y, z;
	float u, v; // Texture coordinates

    Vertex(float x = 0, float y = 0, float u = 0, float v = 0)
		: x(x), y(y), z(0), u(u), v(v)
    {
    }
};