#include "Game.h"

bool flip = false;
int current = 1;
unsigned int framelimit = 60;
int angle = 1;

custom::Vector_3 vertexA(-1.0f, 1.0f, -5.0f); 
custom::Vector_3 vertexB(-1.0f, -1.0f, -5.0f);
custom::Vector_3 vertexC(1.0f, -1.0f, -5.0f);
custom::Vector_3 vertexD(1.0f, 1.0f, -5.0f);

custom::Vector_3 vertexE(1.0f, 1.0f, -15.0f);
custom::Vector_3 vertexF(1.0f, -1.0f, -15.0f);
custom::Vector_3 vertexG(-1.0f, -1.0f, -15.0f);
custom::Vector_3 vertexH(-1.0f, 1.0f, -15.0f);

custom::Matrix_3 rotateMatrix, translateMatrix, scaleMatrixPlus, scaleMatrixMinus;

sf::Keyboard input;


Game::Game() : window(VideoMode(800, 600), "OpenGL Cube"), primitives(1)
{
	index = glGenLists(primitives);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	//sf::Window::setFramerateLimit(framelimit);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(vertexD.getX(), vertexD.getY(), vertexD.getZ());
		glVertex3f(vertexA.getX(), vertexA.getY(), vertexA.getZ());
		glVertex3f(vertexB.getX(), vertexB.getY(), vertexB.getZ());
		glVertex3f(vertexC.getX(), vertexC.getY(), vertexC.getZ());

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(vertexE.getX(), vertexE.getY(), vertexE.getZ());
		glVertex3f(vertexH.getX(), vertexH.getY(), vertexH.getZ());
		glVertex3f(vertexG.getX(), vertexG.getY(), vertexG.getZ());
		glVertex3f(vertexF.getX(), vertexF.getY(), vertexF.getZ());

		// Right face
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(vertexD.getX(), vertexD.getY(), vertexD.getZ());
		glVertex3f(vertexC.getX(), vertexC.getY(), vertexC.getZ());
		glVertex3f(vertexF.getX(), vertexF.getY(), vertexF.getZ());
		glVertex3f(vertexE.getX(), vertexE.getY(), vertexE.getZ());

		// Left face
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(vertexA.getX(), vertexA.getY(), vertexA.getZ());
		glVertex3f(vertexB.getX(), vertexB.getY(), vertexB.getZ());
		glVertex3f(vertexG.getX(), vertexG.getY(), vertexG.getZ());
		glVertex3f(vertexH.getX(), vertexH.getY(), vertexH.getZ());

		// Top face
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(vertexA.getX(), vertexA.getY(), vertexA.getZ());
		glVertex3f(vertexD.getX(), vertexD.getY(), vertexD.getZ());
		glVertex3f(vertexE.getX(), vertexE.getY(), vertexE.getZ());
		glVertex3f(vertexH.getX(), vertexH.getY(), vertexH.getZ());

		// Bottom face
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(vertexB.getX(), vertexB.getY(), vertexB.getZ());
		glVertex3f(vertexG.getX(), vertexG.getY(), vertexG.getZ());
		glVertex3f(vertexF.getX(), vertexF.getY(), vertexF.getZ());
		glVertex3f(vertexC.getX(), vertexC.getY(), vertexC.getZ());

		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primitives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}

	rotateMatrix = rotateMatrix.Rotation(angle);
	//rotateMatrix = rotateMatrix.RotationX(angle);
	//rotateMatrix = rotateMatrix.RotationY(angle);
	translateMatrix = translateMatrix.Translate(4, 4);
	scaleMatrixPlus = scaleMatrixPlus.Scale(99.5f, 99.5f);
	scaleMatrixMinus = scaleMatrixMinus.Scale(-102.5f, -102.5f);
	//scaleMatrix = scaleMatrix.Scale3D(dX, dY);

	//
	if (sf::Keyboard::isKeyPressed(input.R) == true)
	{
		vertexA = vertexA * rotateMatrix;
		vertexB = vertexB * rotateMatrix;
		vertexC = vertexC * rotateMatrix;
		vertexD = vertexD * rotateMatrix;
		vertexE = vertexE * rotateMatrix;
		vertexF = vertexF * rotateMatrix;
		vertexG = vertexG * rotateMatrix;
		vertexH = vertexH * rotateMatrix;
	}
	//
	if (sf::Keyboard::isKeyPressed(input.T) == true)
	{
		vertexA = vertexA * -rotateMatrix;
		vertexB = vertexB * -rotateMatrix;
		vertexC = vertexC * -rotateMatrix;
		vertexD = vertexD * -rotateMatrix;
		vertexE = vertexE * -rotateMatrix;
		vertexF = vertexF * -rotateMatrix;
		vertexG = vertexG * -rotateMatrix;
		vertexH = vertexH * -rotateMatrix;
	}
	//
	if (sf::Keyboard::isKeyPressed(input.Right) == true)
	{
		vertexA = vertexA * translateMatrix;
		vertexB = vertexB * translateMatrix;
		vertexC = vertexC * translateMatrix;
		vertexD = vertexD * translateMatrix;					
		vertexE = vertexE * translateMatrix;
		vertexF = vertexF * translateMatrix;
		vertexG = vertexG * translateMatrix;
		vertexH = vertexH * translateMatrix;
	}
	//
	if (sf::Keyboard::isKeyPressed(input.Left) == true)
	{
		vertexA = vertexA * -translateMatrix;
		vertexB = vertexB * -translateMatrix;
		vertexC = vertexC * -translateMatrix;
		vertexD = vertexD * -translateMatrix;
		vertexE = vertexE * -translateMatrix;
		vertexF = vertexF * -translateMatrix;
		vertexG = vertexG * -translateMatrix;
		vertexH = vertexH * -translateMatrix;
	}
	//
	if (sf::Keyboard::isKeyPressed(input.S) == true)
	{
		vertexA = vertexA * scaleMatrixPlus;
		vertexB = vertexB * scaleMatrixPlus;
		vertexC = vertexC * scaleMatrixPlus;
		vertexD = vertexD * scaleMatrixPlus;				
		vertexE = vertexE * scaleMatrixPlus;
		vertexF = vertexF * scaleMatrixPlus;
		vertexG = vertexG * scaleMatrixPlus;
		vertexH = vertexH * scaleMatrixPlus;
	}
	//
	if (sf::Keyboard::isKeyPressed(input.D) == true)
	{
		vertexA = vertexA * scaleMatrixMinus;
		vertexB = vertexB * scaleMatrixMinus;
		vertexC = vertexC * scaleMatrixMinus;
		vertexD = vertexD * scaleMatrixMinus;
		vertexE = vertexE * scaleMatrixMinus;
		vertexF = vertexF * scaleMatrixMinus;
		vertexG = vertexG * scaleMatrixMinus;
		vertexH = vertexH * scaleMatrixMinus;
	}
	
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	initialize();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << current << endl;
	glLoadIdentity();
	//glRotatef(rotationAngle, 0, 5, 0); // Rotates the camera on Y Axis
	


	glCallList(current);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

