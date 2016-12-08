#pragma once
#define _USE_MATH_DEFINES

// C00204076
// Brandon Seah-Dempsey
// Started at 9:07 21 November 2016
// Finished at 8:45 23 November 2016
// Known bugs: None

#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"


using namespace std;
using namespace sf;

namespace custom
{
	class Matrix_3
	{
		//
		friend Vector_3 operator *(Matrix_3 m1, const Vector_3& v1);
		//
		friend Vector_3 operator *(Vector_3 v1, const Matrix_3& m1);
		//
		friend Matrix_3 Transpose(Matrix_3 m1);
		//
		friend Matrix_3 operator +(Matrix_3 m1, const Matrix_3& m2);
		//
		friend Matrix_3 operator -(Matrix_3 m1, const Matrix_3& m2);
		//
		friend Matrix_3 operator +(float s, const Matrix_3& m1);
		//
		friend Matrix_3 operator *(Matrix_3 m1, const Matrix_3& m2);
		//
		friend Matrix_3 operator -(Matrix_3 m1);

	public:
		//
		Matrix_3();
		//	  
		Matrix_3(Vector_3 row1, Vector_3 row2, Vector_3 row3);
		//	  
		Matrix_3(float m_11, float m_12, float m_13, float m_21, float m_22, float m_23, float m_31, float m_32, float m_33);



		//
		float Determinant(Matrix_3 m1);
		//
		Vector_3 Row(int i);
		//
		Vector_3 Column(int i);
		//
		Matrix_3 Inverse(Matrix_3 m1);
		//
		Matrix_3 Rotation(int angle);
		//
		Matrix_3 Translate(int dx, int dy);
		//
		Matrix_3 Scale(int dx, int dy);
		//
		Matrix_3 RotationX(int angle);
		//
		Matrix_3 RotationY(int angle);
		//
		Matrix_3 RotationZ(int angle);
		//
		Matrix_3 Scale3D(int dx);


	private:
		float m_11, m_12, m_13, m_21, m_22, m_23, m_31, m_32, m_33;
	};
}