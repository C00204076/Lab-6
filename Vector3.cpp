
// C00204076
// Brandon Seah-Dempsey
// Started at 9:48 21 November 2016
// Finished at 8:30 23 November 2016
// Known bugs: None

#include "Vector3.h"

using namespace custom;

//
Vector_3::Vector_3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

//
Vector_3::Vector_3(Vector_3 v1, float x1, float y1, float z1)
{
	v1.x = x1;
	v1.y = y1;
	v1.z = z1;
}

//
Vector_3::Vector_3(float x1, float y1, float z1)
{
	x = x1;
	y = y1;
	z = z1;
}

//
float const & Vector_3::getX() const
{
	return x;
}
//
void Vector_3::setX(Vector_3 v1)
{
	x = v1.x;
}

//
float const  & Vector_3::getY() const
{
	return y;
}
//
void Vector_3::setY(Vector_3 v1)
{
	y = v1.y;
}

//
float const & Vector_3::getZ() const
{				  
	return z;	  
}				  
//				  
void Vector_3::setZ(Vector_3 v1)
{
	z = v1.z;
}

//
double Vector_3::Length(Vector_3 v1)
{
	double answer = 0;

	answer = sqrt((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z));

	return answer;
}

//
double Vector_3::LengthSquared(Vector_3 v1)
{
	double answer = 0;

	answer = (v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z);

	return answer;
}

//
void Vector_3::Normalise(Vector_3 v1)
{
	if (Length(v1) > 0.0)
	{
		double magnitude = Length(v1);

		v1.x /= magnitude;
		v1.y /= magnitude;
		v1.z /= magnitude;
	}
}


//
custom::Vector_3 custom::operator+(custom::Vector_3 v1, const Vector_3& v2)
{
	return Vector_3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

//
custom::Vector_3 custom::operator-(custom::Vector_3 v1, const Vector_3& v2)
{
	return Vector_3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

//
custom::Vector_3 custom::operator-(custom::Vector_3 v1)
{
	return Vector_3(-v1.x, -v1.y, -v1.z);
}

//
float custom::operator*(custom::Vector_3 v1, const Vector_3& v2)
{
	float answer = 0;

	answer = (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);

	return answer;
}

//
custom::Vector_3 custom::operator*(int s, const Vector_3& v2)
{
	return Vector_3(v2.x * s, v2.y * s, v2.z * s);
}
//
custom::Vector_3 custom::operator*(double s, const Vector_3& v2)
{
	return Vector_3(v2.x * s, v2.y * s, v2.z * s);
}
//
custom::Vector_3 custom::operator*(float s, const Vector_3& v2)
{
	return Vector_3(v2.x * s, v2.y * s, v2.z * s);
}

//
custom::Vector_3 custom::operator^(custom::Vector_3 v1, const Vector_3& v2)
{
	return Vector_3((v1.y * v2.z) - (v1.z * v2.y), (v1.z * v2.x) - (v1.x * v2.z), (v1.x * v2.y) - (v1.y * v2.x));
}

//
sf::String Vector_3::ToString()
{
	return to_string(x) + ", " + to_string(y) + ", " + to_string(z);
}