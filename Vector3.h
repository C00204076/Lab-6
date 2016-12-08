#pragma once
#define _USE_MATH_DEFINES


// C00204076
// Brandon Seah-Dempsey
// Started at 9:17 21 November 2016
// Finished at 10:39 21 November
// Known bugs: None

#include <iostream>
#include <cmath>
#include <string.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

using namespace std;
using namespace sf;



namespace custom
{
	
	class Vector_3
	{
		//
		friend Vector_3 operator +(Vector_3 v1, const Vector_3& v2);
		//
		friend Vector_3 operator -(Vector_3 v1, const Vector_3& v2);
		//
		friend Vector_3 operator -(Vector_3 v1);
		//
		friend float operator *(Vector_3 v1, const Vector_3& v2);
		//
		friend Vector_3 operator *(int s, const Vector_3& v2);
		//
		friend Vector_3 operator *(double s, const Vector_3& v2);
		//
		friend Vector_3 operator *(float s, const Vector_3& v2);
		//
		friend Vector_3 operator ^(Vector_3 v1, const Vector_3& v2);

	public:
		//
		Vector_3();
		//
		Vector_3(Vector_3 v1, float x1, float y1, float z1);
		//
		Vector_3(float x1, float y1, float z1);

		//
		float const & getX() const;
		void setX(Vector_3 v1);
		//
		float const & getY() const;
		void setY(Vector_3 v1);
		//
		float const & getZ() const;
		void setZ(Vector_3 v1);

		//
		double Length(Vector_3 v1);
		//
		double LengthSquared(Vector_3 v1);
		//
		void Normalise(Vector_3 v1);

		//
		sf::String ToString();


	private:
		float x, y, z;
	};

}