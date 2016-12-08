
// C00204076
// Brandon Seah-Dempsey
// Started at 10:39 21 November 2016
// Finished at 8:50 23 November 2016
// Known bugs: None


#include "Matrix3.h"

using namespace custom;
//
Matrix_3::Matrix_3()
{
	//
	m_11 = 0.0f;
	m_12 = 0.0f;
	m_13 = 0.0f;
	//		
	m_21 = 0.0f;
	m_22 = 0.0f;
	m_23 = 0.0f;
	//		
	m_31 = 0.0f;
	m_32 = 0.0f;
	m_33 = 0.0f;
}

//
Matrix_3::Matrix_3(Vector_3 row1, Vector_3 row2, Vector_3 row3)
{
	//
	m_11 = row1.getX();
	m_12 = row1.getY();
	m_13 = row1.getZ();
	//
	m_21 = row2.getX();
	m_22 = row2.getY();
	m_23 = row2.getZ();
	//
	m_31 = row3.getX();
	m_32 = row3.getY();
	m_33 = row3.getZ();
}

//
Matrix_3::Matrix_3(float M_11, float M_12, float M_13,
	float M_21, float M_22, float M_23,
	float M_31, float M_32, float M_33)
{
	//
	m_11 = M_11;
	m_12 = M_12;
	m_13 = M_13;
	//
	m_21 = M_21;
	m_22 = M_22;
	m_23 = M_23;
	//
	m_31 = M_31;
	m_32 = M_32;
	m_33 = M_33;
}

//
custom::Vector_3 custom::operator*(custom::Matrix_3 m1, const Vector_3& v1)
{
	return Vector_3((m1.m_11 * v1.getX()) + (m1.m_12 * v1.getY()) + (m1.m_13 * v1.getZ()),
					(m1.m_21 * v1.getX()) + (m1.m_22 * v1.getY()) + (m1.m_23 * v1.getZ()),
					(m1.m_31 * v1.getX()) + (m1.m_32 * v1.getY()) + (m1.m_33 * v1.getZ()));
}

//
custom::Vector_3 custom::operator*(custom::Vector_3 v1, const Matrix_3& m1)
{
	return Vector_3((m1.m_11 * v1.getX()) + (m1.m_21 * v1.getY()) + (m1.m_31 * v1.getZ()), 
					(m1.m_12 * v1.getX()) + (m1.m_22 * v1.getY()) + (m1.m_32 * v1.getZ()),
					(m1.m_13 * v1.getX()) + (m1.m_23 * v1.getY()) + (m1.m_33 * v1.getZ()));
}

//
custom::Matrix_3 custom::Transpose(custom::Matrix_3 m1)
{
	return Matrix_3( m1.m_11, m1.m_21, m1.m_31,
					 m1.m_12, m1.m_22, m1.m_32,
					 m1.m_13, m1.m_23, m1.m_33);
}

//
custom::Matrix_3 custom::operator+(custom::Matrix_3 m1, const Matrix_3& m2)
{
	return Matrix_3(m1.m_11 + m2.m_11, m1.m_21 + m2.m_21, m1.m_31 + m1.m_31,
					m1.m_12 + m2.m_12, m1.m_22 + m2.m_22, m1.m_32 + m1.m_32,
					m1.m_13 + m2.m_13, m1.m_23 + m2.m_23, m1.m_33 + m1.m_33);
}

//
custom::Matrix_3 custom::operator-(custom::Matrix_3 m1, const Matrix_3& m2)
{
	return Matrix_3(m1.m_11 - m2.m_11, m1.m_21 - m2.m_21, m1.m_31 - m1.m_31,
					m1.m_12 - m2.m_12, m1.m_22 - m2.m_22, m1.m_32 - m1.m_32,
					m1.m_13 - m2.m_13, m1.m_23 - m2.m_23, m1.m_33 - m1.m_33);
}

//
custom::Matrix_3 custom::operator+(float s, const Matrix_3& m1)
{
	return Matrix_3(m1.m_11 + s, m1.m_21 + s, m1.m_31 + s,
					m1.m_12 + s, m1.m_22 + s, m1.m_32 + s,
					m1.m_13 + s, m1.m_23 + s, m1.m_33 + s);
}

//
custom::Matrix_3 custom::operator*(custom::Matrix_3 m1, const Matrix_3& m2)
{
	return Matrix_3((m1.m_11 * m2.m_11) + (m1.m_12 * m2.m_21) + (m1.m_13 * m2.m_31), (m1.m_11 * m2.m_12) + (m1.m_12 * m2.m_22) + (m1.m_13 * m2.m_32), (m1.m_11 * m2.m_13) + (m1.m_12 * m2.m_23) + (m1.m_13 * m2.m_33),
					(m1.m_21 * m2.m_11) + (m1.m_22 * m2.m_21) + (m1.m_23 * m2.m_31), (m1.m_21 * m2.m_12) + (m1.m_22 * m2.m_22) + (m1.m_23 * m2.m_32), (m1.m_21 * m2.m_13) + (m1.m_22 * m2.m_23) + (m1.m_23 * m2.m_33),
					(m1.m_31 * m2.m_11) + (m1.m_32 * m2.m_21) + (m1.m_33 * m2.m_31), (m1.m_31 * m2.m_12) + (m1.m_32 * m2.m_22) + (m1.m_33 * m2.m_32), (m1.m_31 * m2.m_13) + (m1.m_32 * m2.m_23) + (m1.m_33 * m2.m_33));
}

//
custom::Matrix_3 custom::operator-(custom::Matrix_3 m1)
{
	return Matrix_3(-m1.m_11, -m1.m_12, -m1.m_13,
					-m1.m_21, -m1.m_22, -m1.m_23,
					-m1.m_31, -m1.m_32, -m1.m_33);
}

//
float Matrix_3::Determinant(Matrix_3 m1)
{
	return (m1.m_11 * (m1.m_22 * m1.m_33 - m1.m_32 * m1.m_23)) - (m1.m_21 * (m1.m_33 * m1.m_12 - m1.m_32 * m1.m_13)) + (m1.m_31 * (m1.m_23 * m1.m_12 - m1.m_22 * m1.m_13));
}

//
Vector_3 Matrix_3::Row(int i)
{
	switch (i)
	{
	case 0:
		return Vector_3(m_11, m_12, m_13);
	case 1:
		return Vector_3(m_21, m_22, m_23);
	case 2:
	default:
		return Vector_3(m_31, m_32, m_33);
	}
}

//
Vector_3 Matrix_3::Column(int i)
{
	switch (i)
	{
	case 0:
		return Vector_3(m_11, m_21, m_31);
	case 1:
		return Vector_3(m_12, m_22, m_32);
	case 2:
	default:
		return Vector_3(m_13, m_23, m_33);
	}
}

//
Matrix_3 Matrix_3::Inverse(Matrix_3 m1)
{
	float determinant = Determinant(m1);

	if (determinant == 0)
	{
		return Matrix_3();
	}
	else
	{
		float scale = 1 / determinant;

		return Matrix_3(scale * (m1.m_22 * m1.m_33 - m1.m_23 * m1.m_32), scale * (m1.m_13 * m1.m_32 - m1.m_12 * m1.m_33), scale * (m1.m_12 * m1.m_23 - m1.m_13 * m1.m_22),
						scale * (m1.m_23 * m1.m_31 - m1.m_21 * m1.m_33), scale * (m1.m_11 * m1.m_33 - m1.m_13 * m1.m_31), scale * (m1.m_13 * m1.m_21 - m1.m_11 * m1.m_23),
						scale * (m1.m_21 * m1.m_32 - m1.m_22 * m1.m_31), scale * (m1.m_12 * m1.m_31 - m1.m_11 * m1.m_32), scale * (m1.m_11 * m1.m_22 - m1.m_12 * m1.m_21));
	}
}

//
Matrix_3 Matrix_3::Rotation(int angle)
{
	double dAngle = M_PI / 180 * angle;

	return Matrix_3((float)std::cos(dAngle), (float)std::sin(dAngle), 0,
					-(float)std::sin(dAngle), (float)std::cos(dAngle), 0,
					  0,					   0,						1);
}

//
Matrix_3 Matrix_3::Translate(int dx, int dy)
{
	return Matrix_3(1.0f, 0.0f, dx, 
					0.0f, 1.0f, dy,
					0.0f, 0.0f, 1.0f);

	//return Matrix_3(1.0f, 0.0f, 0.0f,
	//				0.0f, 1.0f, 0.0f,
	//				dx, dy, 1.0f);
}

//
Matrix_3 Matrix_3::Scale(int dx, int dy)
{
	return Matrix_3((float)dx / 100, 0.0f,			  0.0f,
					0.0f,            (float)dy / 100, 0.0f,
					0.0f,            0.0f,			  1.0f);
}

//
Matrix_3 Matrix_3::RotationX(int angle)
{
	double dAngle = M_PI / 180 * angle;

	return Matrix_3(1,						 0,						   0,
					0, (float)std::cos(dAngle), -(float)std::sin(dAngle),
					0, (float)std::sin(dAngle), (float)std::cos(dAngle));
}

//
Matrix_3 Matrix_3::RotationY(int angle)
{
	double dAngle = M_PI / 180 * angle;

	return Matrix_3((float)std::cos(dAngle),  0, (float)std::sin(dAngle),
					0,						  1,					   0,
					-(float)std::sin(dAngle), 0, (float)std::cos(dAngle));
}

//
Matrix_3 Matrix_3::RotationZ(int angle)
{
	double dAngle = M_PI / 180 * angle;

	return Matrix_3((float)std::cos(dAngle), -(float)std::sin(dAngle), 0,
					(float)std::sin(dAngle), (float)std::cos(dAngle),  0,
					0,						 0,						   1);
}

//
Matrix_3 Matrix_3::Scale3D(int dx)
{
	return Matrix_3((float)dx / 100, 0,				  0, 
					0,				 (float)dx / 100, 0,
					0,				 0,				  (float)dx / 100);
}