#pragma once

#include <GL\glew.h>

class Mesh
{
public:
	Mesh();

	GLuint GetVAO() const { return VAO; }

	void CreateMesh(GLfloat *vertices, unsigned int *indices, unsigned int numOfVertices, unsigned int numOfIndices);
	void Mesh::CreateCircleMesh(float radius, unsigned int segments, float offsetY, float offsetX);
	void RenderMesh();
	void ClearMesh();

	~Mesh();

private:
	GLuint VAO, VBO, IBO;
	GLsizei indexCount;
};

