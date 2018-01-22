#include "Common.h"
#include "My_glut.h"
#include "Shader.h"
#include "Camera.h"
#include "Color.h"
#include "PerlinNoise.h"
#include "Clipmap.h"
#include "Texture.h"
#include "bitmap_image.h"
#include "cubeMap.h"

using namespace std;

/* Buffers and program */
GLuint bufferMap0, bufferMap1, bufferMap2, bufferMap3, bufferMap4, bufferMap5, bufferMap6, bufferMap7, skyboxBuffer, cubeBuffer;
GLuint cubeProgram, textureProgram, skyboxProgram;

/* Shaders */
Shader* cubeShader, *textureShader, *skyboxShader;

/* Texture */
GLuint textures[7], cubeMapTexture;

/* Clipmap */
Clipmap clipmap0, clipmap1, clipmap2, clipmap3, clipmap4, clipmap5, clipmap6, clipmap7, clipmap8;

/* Projection transformation parameters */
GLfloat fovy = 45.0;										// Field-of-view in Y direction angle (in degrees)
GLfloat aspect = (GLfloat)WIDTH / (GLfloat)HEIGHT;			// Viewport aspect ratio
GLfloat zNear = 0.001, zFar = 100.0;
GLfloat angle = 0.0;										// rotation angle in degrees

/* Camera */
Camera camera;

int a = N_COORD * N_COORD * N_TRIANG * 2 * N_TRIANG;		// 3 * 3 * 32 * 2 * 32;
int b =  2 *N_COORD  * N_TRIANG * 2 * N_TRIANG;

void init() 
{
	/* Clear window */
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);			// 0.529f, 0.807f, 0.92f, 0.0f

	/* Init Shaders */
	cubeShader = new Shader("shaders/cube_vshader.glsl", "shaders/cube_fshader.glsl");
	cubeProgram = cubeShader->use_program();

	textureShader = new Shader("shaders/texture_vshader.glsl", "shaders/texture_fshader.glsl");
	textureProgram = textureShader->use_program();

	skyboxShader = new Shader("shaders/skybox_vshader.glsl", "shaders/skybox_fshader.glsl");
	skyboxProgram = skyboxShader->use_program();

	camera.initialize();

	/* Initialize 8 clipmaps ( L = {0, 1, .. , 7 } */
	clipmap0.start(0);
	clipmap1.start(1);
	clipmap2.start(2);
	clipmap3.start(3);
	clipmap4.start(4);
	clipmap5.start(5);
	clipmap6.start(6);
	clipmap7.start(7);

	/* Buffers */
	glGenBuffers(1, &bufferMap0);
	glBindBuffer(GL_ARRAY_BUFFER, bufferMap0);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * a + sizeof(float)* b, NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * a, clipmap0.triangulationCoord);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(float) * a, sizeof(float)* b, coordinatesToTexture(clipmap0.triangulationCoord));

	glGenBuffers(1, &bufferMap1);
	glBindBuffer(GL_ARRAY_BUFFER, bufferMap1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* a + sizeof(float)* b, NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)* a, clipmap1.triangulationCoord);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(float)* a, sizeof(float)* b, coordinatesToTexture(clipmap1.triangulationCoord));

	glGenBuffers(1, &bufferMap2);
	glBindBuffer(GL_ARRAY_BUFFER, bufferMap2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* a + sizeof(float)* b, NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)* a, clipmap2.triangulationCoord);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(float)* a, sizeof(float)* b, coordinatesToTexture(clipmap2.triangulationCoord));

	glGenBuffers(1, &bufferMap3);
	glBindBuffer(GL_ARRAY_BUFFER, bufferMap3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* a + sizeof(float)* b, NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)* a, clipmap3.triangulationCoord);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(float)* a, sizeof(float)* b, coordinatesToTexture(clipmap3.triangulationCoord));

	glGenBuffers(1, &bufferMap4);
	glBindBuffer(GL_ARRAY_BUFFER, bufferMap4);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* a + sizeof(float)* b, NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)* a, clipmap4.triangulationCoord);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(float)* a, sizeof(float)* b, coordinatesToTexture(clipmap4.triangulationCoord));

	glGenBuffers(1, &bufferMap5);
	glBindBuffer(GL_ARRAY_BUFFER, bufferMap5);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* a + sizeof(float)* b, NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)* a, clipmap5.triangulationCoord);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(float)* a, sizeof(float)* b, coordinatesToTexture(clipmap5.triangulationCoord));

	glGenBuffers(1, &bufferMap6);
	glBindBuffer(GL_ARRAY_BUFFER, bufferMap6);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* a + sizeof(float)* b, NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)* a, clipmap6.triangulationCoord);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(float)* a, sizeof(float)* b, coordinatesToTexture(clipmap6.triangulationCoord));

	glGenBuffers(1, &bufferMap7);
	glBindBuffer(GL_ARRAY_BUFFER, bufferMap7);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* a + sizeof(float)* b, NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)* a, clipmap7.triangulationCoord);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(float)* a, sizeof(float)* b, coordinatesToTexture(clipmap7.triangulationCoord));
	//glBufferData(GL_ARRAY_BUFFER, sizeof(float) * a, clipmap7.triangulationCoord, GL_STATIC_DRAW);

	glGenBuffers(1, &skyboxBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);

	glGenBuffers(1, &cubeBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, cubeBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices)+sizeof(cubeNormals), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(cubeVertices), cubeVertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(cubeVertices), sizeof(cubeNormals), cubeNormals);

	/* Load an image and apply Textures */
	loadTexture(0, textures, "textures/suelo_1.bmp");
	loadTexture(1, textures, "textures/lake_4.bmp");
	loadTexture(2, textures, "textures/garden_4.bmp");		// -
	loadTexture(3, textures, "textures/garden_3.bmp");		// -
	loadTexture(4, textures, "textures/mountain_3.bmp");	// -
	loadTexture(5, textures, "textures/snow_3.bmp");		// -
	loadTexture(6, textures, "textures/snow_4.bmp");		// -

	/* Cube maps */
	vector<string> faces { "skybox/right.bmp", "skybox/left.bmp", "skybox/top.bmp", "skybox/bottom.bmp", 
		"skybox/back.bmp", "skybox/front.bmp" };

	loadCubemap(cubeMapTexture, faces);

}

void drawBackgrounds(Shader* &shader, GLuint& buffer, GLuint& program, int& num_vertices, vec3& color, bool line = false) {

	if (line == true) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glLineWidth(2.0);
	}
	else  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	/* Get and set: Vertex shader 'in' variables */
	GLuint vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	shader->use();

	/* Vertex Shader */
	mat4 view, projection, model;
	//view = camera.GetViewMatrix();
	view = LookAt(camera.position, camera.front, camera.up) * view;
	projection = Perspective(fovy, (GLfloat)WIDTH / (GLfloat)HEIGHT, zNear, zFar);

	shader->setMat4("projection", projection);
	shader->setMat4("view", view);
	shader->setMat4("model", model);

	/* Fragment Shader */
	shader->setVec3("backgroundColor", color);

	/*--- Draw and disable each vertex attribute array being enabled ---*/
	glDrawArrays(GL_TRIANGLES, 0, num_vertices);
	glDisableVertexAttribArray(vPosition);
}

void drawTexture(Shader* &shader, GLuint& buffer, GLuint& program, int num_vertices) {

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	/* Get and set: Vertex shader 'in' variables */
	GLuint vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	GLuint vTexCoord = glGetAttribLocation(program, "vTexCoord");
	glEnableVertexAttribArray(vTexCoord);
	glVertexAttribPointer(vTexCoord, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(clipmap0.triangulationCoord) * a));
	shader->use();

	/* Vertex Shader */
	mat4 view, projection, model;
	//view = camera.GetViewMatrix();
	view = LookAt(camera.position, camera.front, camera.up) * view;
	projection = Perspective(fovy, (GLfloat)WIDTH / (GLfloat)HEIGHT, zNear, zFar);

	shader->setMat4("projection", projection);
	shader->setMat4("view", view);
	shader->setMat4("model", model);

	/* Fragment Shade */
	shader->setInt("texture1", 0);
	shader->setInt("texture2", 1);
	shader->setInt("texture3", 2);
	shader->setInt("texture4", 3);
	shader->setInt("texture5", 4);
	shader->setInt("texture6", 5);
	shader->setInt("texture7", 6);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_2D, textures[4]);
	glActiveTexture(GL_TEXTURE5);
	glBindTexture(GL_TEXTURE_2D, textures[5]);
	glActiveTexture(GL_TEXTURE6);
	glBindTexture(GL_TEXTURE_2D, textures[6]);

	/*--- Draw and disable each vertex attribute array being enabled ---*/
	glDrawArrays(GL_TRIANGLES, 0, num_vertices);
	glDisableVertexAttribArray(vPosition);
	glDisableVertexAttribArray(vTexCoord);
}

void drawSkyBox(Shader* &shader, GLuint& buffer, GLuint& program, int numVertices)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	/* Get and set: Vertex shader 'in' variables */
	GLuint vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
	shader->use();

	/* Vertex Shader */
	mat4 view, projection;
	view = mat4WithUpperLeftMat3(upperLeftMat3(camera.GetViewMatrix()));		//  LookAt(camera.position, camera.position + camera.front,camera.up);	
	projection = Perspective(fovy, (GLfloat)WIDTH / (GLfloat)HEIGHT, zNear, zFar);

	shader->setMat4("projection", projection);
	shader->setMat4("view", view);

	//glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMapTexture);
	glDrawArrays(GL_TRIANGLES, 0, numVertices);
	glDepthFunc(GL_LESS);									// set depth function back to default
}

void cubeEnvironm(Shader* &shader, GLuint& buffer, GLuint& program, int numVertices)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	/* Get and set: Vertex shader 'in' variables */
	GLuint vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	GLuint aNormal = glGetAttribLocation(program, "aNormal");
	glEnableVertexAttribArray(aNormal);
	glVertexAttribPointer(aNormal, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(cubeVertices)));
	shader->use();


	/* Vertex Shader */
	mat4 view, projection, model;
	//view = camera.GetViewMatrix();
	view = LookAt(camera.position, camera.front, camera.up) * view;
	view= Scale(0.2, 0.2, 0.2) * Translate(0.5, 1.5, -0.5) * view;
	projection = Perspective(fovy, (GLfloat)WIDTH / (GLfloat)HEIGHT, zNear, zFar);

	shader->setMat4("projection", projection);
	shader->setMat4("view", view);
	shader->setMat4("model", model);

	/*--- Draw and disable each vertex attribute array being enabled ---*/
	glDrawArrays(GL_TRIANGLES, 0, numVertices);
	glDisableVertexAttribArray(vPosition);
	glDisableVertexAttribArray(aNormal);
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawSkyBox(skyboxShader, skyboxBuffer, skyboxProgram, numVertSkyBox);

	drawTexture(textureShader, bufferMap0, textureProgram, b / 2);
	drawTexture(textureShader, bufferMap1, textureProgram, b / 2);
	drawTexture(textureShader, bufferMap2, textureProgram, b / 2);
	drawTexture(textureShader, bufferMap3, textureProgram, b / 2);
	drawTexture(textureShader, bufferMap4, textureProgram, b / 2);
	drawTexture(textureShader, bufferMap5, textureProgram, b / 2);
	drawTexture(textureShader, bufferMap6, textureProgram, b / 2);
	drawTexture(textureShader, bufferMap7, textureProgram, b / 2);

	cubeEnvironm(cubeShader, cubeBuffer, cubeProgram, numVertCube);

	//drawBackgrounds(clipmapShader, bufferMap7, clipmapProgram, a, skyBlue3);
	//drawBackgrounds(clipmapShader, bufferMap7, clipmapProgram, a, grayDarkColor3, true);
	glutSwapBuffers();
}

void idle(void) {
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {

		case 'q': case 'Q': case 033:
			exit(EXIT_SUCCESS); break;

		case 'X': {
			camera.displacementPosX();
			break;
		}
		case 'x': {
			camera.displacementNegX();
			break;
		}
		case 'Y': {
			camera.displacementPosY();
			break;
		}
		case 'y': {
			camera.displacementNegY();
			break;
		}
		case 'Z': {
			camera.displacementPosZ();
			break;
		}
		case 'z': {
			camera.displacementNegZ(); 
			break;
		}
	}

	glutPostRedisplay();
}


int main(int argc, char **argv) {
	/* function to generate coordinates to triangulate 
	ofstream outputFile("clipmap_data/triangulization_0.txt", ofstream::out);

	double x = -0.8;
	double constant = 0.8;
	double y = 0.8;
	double offset = 0.05;
	int cont = 0;

	for (int i = 0; i < 33; i++) {
		for (int j = 0; j < 33; j++) {
			outputFile << x;
			outputFile << " 0.0 ";
			outputFile << y;
			outputFile << "\n";
			x += offset;
		}
		x = -0.8;
		constant -= offset;
		y = constant;
	}
	outputFile.close();
	*/
	/* Init glut and check if glew works */
	my_glut_init(argc, argv, WIDTH, HEIGHT);

	init();

	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
				//glutMouseFunc(mouse);
	glutMainLoop();
	
	return 0;
}