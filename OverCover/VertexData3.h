#pragma once
#include "vertexdata.h"
#include "Color.h"
#include "UV.h"
struct VertexData3 :public VertexData
{
	Color color;
	UV uv;
};

