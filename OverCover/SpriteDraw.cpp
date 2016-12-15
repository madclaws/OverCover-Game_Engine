#include "SpriteDraw.h"


void SpriteDraw::Draw(GLuint& vao,Texture2D& texture)
{  glActiveTexture(GL_TEXTURE0);
	texture.Bind();
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
	glBindVertexArray(0);

}
