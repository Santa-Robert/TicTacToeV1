#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "Window.h"
#include "Mesh.h"
#include "Shader.h"

const float toRadians = 3.14159265f / 180.0f;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;


GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;

// Vertex Shader
static const char* vShader = "Shaders/shader.vert.txt";

// Fragment Shader
static const char* fShader = "Shaders/shader.frag.txt";

void CreateBorder()
{
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 1

	};

	GLfloat vertices[] = {
		0.28f, -0.8f, 0.0f,  // Vertex 1: bottom left
		0.3f, -0.8f, 0.0f,  // Vertex 2: bottom right
		0.28f,  0.8f, 0.0f,   // Vertex 3: top left 
		0.3f,   0.8f, 0.0f  //Vertex 4: top right

	};

	GLfloat vertices2[] = {
		-0.28f, -0.8f, 0.0f,  // Vertex 1: bottom left
		-0.3f, -0.8f, 0.0f,  // Vertex 2: bottom right
		-0.28f,  0.8f, 0.0f,   // Vertex 3: top left 
		-0.3f,   0.8f, 0.0f  //Vertex 4: top right

	};

	GLfloat vertices3[] = {
		-0.9f, 0.25f, 0.0f,  // Vertex 1: bottom left
		0.9f, 0.25f, 0.0f,  // Vertex 2: bottom right
		-0.9f,  0.27f, 0.0f,   // Vertex 3: top left 
		0.9f,   0.27f, 0.0f  //Vertex 4: top right

	};

	GLfloat vertices4[] = {
		-0.9f, -0.25f, 0.0f,  // Vertex 1: bottom left
		0.9f, -0.25f, 0.0f,  // Vertex 2: bottom right
		-0.9f,  -0.27f, 0.0f,   // Vertex 3: top left 
		0.9f,   -0.27f, 0.0f  //Vertex 4: top right

	};

	Mesh *line1 = new Mesh();
	line1->CreateMesh(vertices, indices, 12, 6);
	meshList.push_back(line1);

	Mesh *line2 = new Mesh();
	line2->CreateMesh(vertices2, indices, 12, 6);
	meshList.push_back(line2);

	Mesh *line3 = new Mesh();
	line3->CreateMesh(vertices3, indices, 12, 6);
	meshList.push_back(line3);

	Mesh *line4 = new Mesh();
	line4->CreateMesh(vertices4, indices, 12, 6);
	meshList.push_back(line4);
}


void CreateSquares() {

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 1
	};

	GLfloat vertices[] = {
		-0.88f, 0.77f, 0.0f,  // Vertex 1: bottom left
		-0.34f, 0.77f, 0.0f,  // Vertex 2: bottom right
		-0.88f,  0.3f, 0.0f,   // Vertex 3: top left 
		-0.34f,   0.3f, 0.0f  //Vertex 4: top right
	};

	GLfloat vertices2[] = {
		-0.25f, 0.77f, 0.0f,  // Vertex 1: bottom left
		0.25f, 0.77f, 0.0f,  // Vertex 2: bottom right
		-0.25f,  0.3f, 0.0f,   // Vertex 3: top left 
		0.25f,   0.3f, 0.0f  //Vertex 4: top right
	};

	GLfloat vertices3[] = {
		0.33f, 0.77f, 0.0f,  // Vertex 1: bottom left
		0.88f, 0.77f, 0.0f,  // Vertex 2: bottom right
		0.33f,  0.3f, 0.0f,   // Vertex 3: top left 
		0.88f,   0.3f, 0.0f  //Vertex 4: top right
	};

	GLfloat vertices4[] = {
		-0.88f, 0.22f, 0.0f,  // Vertex 1: bottom left
		-0.34f, 0.22f, 0.0f,  // Vertex 2: bottom right
		-0.88f, -0.22f, 0.0f,   // Vertex 3: top left 
		-0.34f, -0.22f, 0.0f  //Vertex 4: top right
	};

	GLfloat vertices5[] = {
		-0.25f, 0.22f, 0.0f,  // Vertex 1: bottom left
		0.25f, 0.22f, 0.0f,  // Vertex 2: bottom right
		-0.25f, -0.22f, 0.0f,   // Vertex 3: top left 
		0.25f, -0.22f, 0.0f  //Vertex 4: top right
	};

	GLfloat vertices6[] = {
		0.33f, 0.22f, 0.0f,  // Vertex 1: bottom left
		0.88f, 0.22f, 0.0f,  // Vertex 2: bottom right
		0.33f, -0.22f, 0.0f,   // Vertex 3: top left 
		0.88f, -0.22f, 0.0f  //Vertex 4: top right
	};

	GLfloat vertices7[] = {
		-0.88f, -0.77f, 0.0f,  // Vertex 1: bottom left
		-0.34f, -0.77f, 0.0f,  // Vertex 2: bottom right
		-0.88f, -0.3f, 0.0f,   // Vertex 3: top left 
		-0.34f, -0.3f, 0.0f  //Vertex 4: top right
	};

	GLfloat vertices8[] = {
		-0.25f, -0.77f, 0.0f,  // Vertex 1: bottom left
		0.25f, -0.77f, 0.0f,  // Vertex 2: bottom right
		-0.25f, -0.3f, 0.0f,   // Vertex 3: top left 
		0.25f, -0.3f, 0.0f  //Vertex 4: top right
	};

	GLfloat vertices9[] = {
		0.33f, -0.77f, 0.0f,  // Vertex 1: bottom left
		0.88f, -0.77f, 0.0f,  // Vertex 2: bottom right
		0.33f, -0.3f, 0.0f,   // Vertex 3: top left 
		0.88f, -0.3f, 0.0f  //Vertex 4: top right
	};

	Mesh *square = new Mesh();
	square->CreateMesh(vertices, indices, 12, 6);
	meshList.push_back(square);

	Mesh *square2 = new Mesh();
	square2->CreateMesh(vertices2, indices, 12, 6);
	meshList.push_back(square2);

	Mesh *square3 = new Mesh();
	square3->CreateMesh(vertices3, indices, 12, 6);
	meshList.push_back(square3);

	Mesh *square4 = new Mesh();
	square4->CreateMesh(vertices4, indices, 12, 6);
	meshList.push_back(square4);

	Mesh *square5 = new Mesh();
	square5->CreateMesh(vertices5, indices, 12, 6);
	meshList.push_back(square5);

	Mesh *square6 = new Mesh();
	square6->CreateMesh(vertices6, indices, 12, 6);
	meshList.push_back(square6);

	Mesh *square7 = new Mesh();
	square7->CreateMesh(vertices7, indices, 12, 6);
	meshList.push_back(square7);

	Mesh *square8 = new Mesh();
	square8->CreateMesh(vertices8, indices, 12, 6);
	meshList.push_back(square8);

	Mesh *square9 = new Mesh();
	square9->CreateMesh(vertices9, indices, 12, 6);
	meshList.push_back(square9);

}

void CreateCircles() {

	Mesh *circle = new Mesh();
	circle->CreateCircleMesh(0.2f, 50.0f, -0.6f, 0.6f);
	meshList.push_back(circle);

	Mesh *circle2 = new Mesh();
	circle2->CreateCircleMesh(0.2f, 50.0f, -0.6f, 0.0f);
	meshList.push_back(circle2);

	Mesh *circle3 = new Mesh();
	circle3->CreateCircleMesh(0.2f, 50.0f, -0.6f, -0.6f);
	meshList.push_back(circle3);

	Mesh *circle4 = new Mesh();
	circle4->CreateCircleMesh(0.2f, 50.0f, 0.0f, 0.6f);
	meshList.push_back(circle4);

	Mesh *circle5 = new Mesh();
	circle5->CreateCircleMesh(0.2f, 50.0f, 0.0f, 0.0f);
	meshList.push_back(circle5);

	Mesh *circle6 = new Mesh();
	circle6->CreateCircleMesh(0.2f, 50.0f, 0.0f, -0.6f);
	meshList.push_back(circle6);

	Mesh *circle7 = new Mesh();
	circle7->CreateCircleMesh(0.2f, 50.0f, 0.6f, 0.6);
	meshList.push_back(circle7);

	Mesh *circle8 = new Mesh();
	circle8->CreateCircleMesh(0.2f, 50.0f, 0.6f, 0.0f);
	meshList.push_back(circle8);

	Mesh *circle9 = new Mesh();
	circle9->CreateCircleMesh(0.2f, 50.0f, 0.6f, -0.6f);
	meshList.push_back(circle9);


}

void CreateShaders()
{
	Shader *shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}

int checkWin(int p1, int p2, int p3) {
	if (p1 == p2 && p2 == p3 && p1 == 1) {
		return 1;
	}
	else if (p1 == p2 && p2 == p3 && p1 == 2) {
		return 2;
	}
	else {
		return 0;
	}
}

int main()
{
	mainWindow = Window(800, 600);
	mainWindow.Initialise();

	CreateBorder();
	CreateSquares();
	CreateCircles();
	CreateShaders();


	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0;

	bool shouldRenderX[9] = { false };
	bool shouldRenderY[9] = { false };
	int posCheck1 = 0;
	int posCheck2 = 0;
	int posCheck3 = 0;
	int posCheck4 = 0;
	int posCheck5 = 0;
	int posCheck6 = 0;
	int posCheck7 = 0;
	int posCheck8 = 0;
	int posCheck9 = 0;
	int winnerWinnerChickenDinner = 0;
	int xWin = 0;


	// Loop until window closed
	while (!mainWindow.getShouldClose())
	{
		GLfloat now = glfwGetTime(); // SDL_GetPerformanceCounter();
		deltaTime = now - lastTime; // (now - lastTime)*1000/SDL_GetPerformanceFrequency();
		lastTime = now;

		// Get + Handle User Input
		glfwPollEvents();

		// Clear the window
		glClearColor(0.1f, 0.1f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shaderList[0].UseShader();
		uniformModel = shaderList[0].GetModelLocation();
		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();

		glm::mat4 model(1.0f);

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

		meshList[0]->RenderMesh();

		meshList[1]->RenderMesh();

		meshList[2]->RenderMesh();

		meshList[3]->RenderMesh();




		if (mainWindow.leftClick)
		{
			int mx = static_cast<int>(mainWindow.mouseX);
			int my = static_cast<int>(mainWindow.mouseY);


			if (mx >= 40 && mx <= 274 && my <= 210 && my >= 58)
			{
				printf("1x");
				shouldRenderX[0] = true;
				posCheck1 = 1;
			}
			if (mx >= 292 && mx <= 508 && my <= 213 && my >= 62)
			{
				printf("2x");
				shouldRenderX[1] = true;
				posCheck2 = 1;
			}
			if (mx >= 522 && mx <= 749 && my <= 214 && my >= 64)
			{
				printf("3x");
				shouldRenderX[2] = true;
				posCheck3 = 1;
			}
			if (mx >= 41 && mx <= 274 && my <= 370 && my >= 232)
			{
				printf("4x");
				shouldRenderX[3] = true;
				posCheck4 = 1;
			}
			if (mx >= 292 && mx <= 509 && my <= 369 && my >= 228)
			{
				printf("5x");
				shouldRenderX[4] = true;
				posCheck5 = 1;
			}
			if (mx >= 523 && mx <= 755 && my <= 370 && my >= 236)
			{
				printf("6x");
				shouldRenderX[5] = true;
				posCheck6 = 1;
			}
			if (mx >= 45 && mx <= 274 && my <= 540 && my >= 386)
			{
				printf("7x");
				shouldRenderX[6] = true;
				posCheck7 = 1;
			}
			if (mx >= 294 && mx <= 507 && my <= 539 && my >= 386)
			{
				printf("8x");
				shouldRenderX[7] = true;
				posCheck8 = 1;
			}
			if (mx >= 525 && mx <= 754 && my <= 537 && my >= 395)
			{
				printf("9x");
				shouldRenderX[8] = true;
				posCheck9 = 1;
			}
		};

		if (mainWindow.rightClick)
		{
			int mx = static_cast<int>(mainWindow.mouseX);
			int my = static_cast<int>(mainWindow.mouseY);


			if (mx >= 40 && mx <= 274 && my <= 210 && my >= 58)
			{
				printf("1y");
				shouldRenderY[0] = true;
				posCheck1 = 2;
			}
			if (mx >= 292 && mx <= 508 && my <= 213 && my >= 62)
			{
				printf("2y");
				shouldRenderY[1] = true;
				posCheck2 = 2;
			}
			if (mx >= 522 && mx <= 749 && my <= 214 && my >= 64)
			{
				printf("3y");
				shouldRenderY[2] = true;
				posCheck3 = 2;
			}
			if (mx >= 41 && mx <= 274 && my <= 370 && my >= 232)
			{
				printf("4y");
				shouldRenderY[3] = true;
				posCheck4 = 2;
			}
			if (mx >= 292 && mx <= 509 && my <= 369 && my >= 228)
			{
				printf("5y");
				shouldRenderY[4] = true;
				posCheck5 = 2;
			}
			if (mx >= 523 && mx <= 755 && my <= 370 && my >= 236)
			{
				printf("6y");
				shouldRenderY[5] = true;
				posCheck6 = 2;
			}
			if (mx >= 45 && mx <= 274 && my <= 540 && my >= 386)
			{
				printf("7y");
				shouldRenderY[6] = true;
				posCheck7 = 2;
			}
			if (mx >= 294 && mx <= 507 && my <= 539 && my >= 386)
			{
				printf("8y");
				shouldRenderY[7] = true;
				posCheck8 = 2;
			}
			if (mx >= 525 && mx <= 754 && my <= 537 && my >= 395)
			{
				printf("9y");
				shouldRenderY[8] = true;
				posCheck9 = 2;
			}
		};

		for (int i = 0; i < 9; i++) {

			if (shouldRenderX[i]) {
				meshList[i + 4]->RenderMesh();
			}

		}
		for (int i = 0; i < 9; i++) {

			if (shouldRenderY[i]) {
				meshList[i + 13]->RenderMesh();
			}

		}

		if (checkWin(posCheck1, posCheck2, posCheck3) != 0) {
			break;
		}
		if (checkWin(posCheck4, posCheck5, posCheck6) != 0) {
			break;
		}

		if (checkWin(posCheck7, posCheck8, posCheck9) != 0) {
			break;
		}
		if (checkWin(posCheck1, posCheck4, posCheck7) != 0) {
			break;
		}
		if (checkWin(posCheck2, posCheck5, posCheck8) != 0) {
			break;
		}
		if (checkWin(posCheck3, posCheck6, posCheck9) != 0) {
			break;
		}
		if (checkWin(posCheck1, posCheck5, posCheck9) != 0) {
			break;
		}
		if (checkWin(posCheck3, posCheck5, posCheck7) != 0) {
			break;
		}


		glUseProgram(0);

		mainWindow.swapBuffers();
	}




	return 0;
}