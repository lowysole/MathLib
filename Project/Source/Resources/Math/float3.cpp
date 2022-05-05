#include "float3.h"


// --- Arithmetic operators ---
float3 float3::operator+(const float3& v) const
{
	return float3(x + v.x, y + v.y, z + v.z);
}

float3 float3::operator-(const float3& v) const
{
	return float3(x - v.x, y - v.y, z - v.z);
}

float3 float3::operator*(const float scalar) const
{
	return float3(x * scalar, y * scalar, z * scalar);
}

float3 float3::operator/(const float scalar) const
{
	float invScalar = 1.f / scalar;
	return float3(x * invScalar, y * invScalar, z * invScalar);
}

// --- Assignment operators ---

float3& float3::operator+=(const float3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}

float3& float3::operator-=(const float3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}

float3& float3::operator*=(const float scalar) {
	x = x * scalar;
	y = y * scalar;
	z = z * scalar;

	return *this;
}

float3& float3::operator/=(const float scalar) {
	float invScalar = 1.0f / scalar;
	x = x * invScalar;
	y = y * invScalar;
	z = z * invScalar;

	return *this;
}

// --- Vector operations ---




std::ostream& operator<<(std::ostream& out, const float3& v) {
	out << "x: " << v.x << ", y: " << v.z << ", z: " << v.z;

	return out;
}