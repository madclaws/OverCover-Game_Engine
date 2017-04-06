#pragma once
#ifndef SPRITEBATCHRENDERER_H
#define SPRITEBATCHRENDERER_H

#include <GL\glew.h>
#include<vector>
#include<algorithm>
#include"Sprite.h"
#include<Windows.h>
#include"VertexData3.h"
namespace OverCover2D {
	//enum class SortType;
	enum class  SortType {
		TEXTURES,
		FRONT_TO_BACK,
		BACK_TO_FRONT
	};
	class RenderBatch;
	class SpriteBatchRenderer
	{
		GLuint VAO, VBO, EBO;
		std::vector<Sprite*> SpriteArray;
		SortType Sort_Type;
		std::vector<RenderBatch> Batches;
		std::vector<GLuint> ElementIndices;
		std::vector<VertexData3> vertices;
		void CreateVertexArrayObj();
		void SortSprites();
		void GenerateBatches();
		//void TraverseSceneGraph(GameObject*);
		void CalculateVertex();
		std::vector<GameObject*> ObjArray;
	public:
		GLint index_0, index_1, index_2, index_3, index_4, index_5;
		static GLboolean SortMemory, GenerateMemory;

		void Init();
		void Begin(SortType _sortype = SortType::TEXTURES);
		void CreateSpriteArray(Sprite*);
		void End();
		static GLboolean sortfunc(Sprite*, Sprite*);
		void Renderer();
		void RenderScene();
		SpriteBatchRenderer(void);
		~SpriteBatchRenderer(void);
	};

	class RenderBatch {
	public:
		GLint offset;
		GLint numofvert;
		GLuint textureid;
		RenderBatch(GLint _offset, GLint _numvert, GLuint _textureid)
		{
			offset = _offset;
			numofvert = _numvert;
			textureid = _textureid;
		}
	};
}
#endif