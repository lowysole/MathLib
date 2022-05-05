#pragma once

#include <iostream>

class float3
{
private:
	float x;
	float y;
	float z;

public:

	// --- Constructors ---
	float3(float _x, float _y, float _z) :
		x{ _x }, y{ _y }, z{ _z } {};

	float3(float scalar) : x{ scalar }, y{ scalar }, z{ scalar } {};

	// --- Copy constructor ---
	float3(const float3& v) {
		x = v.x; y = v.y; z = v.z;
	};

	// --- Arithmetic operators ---
	float3 operator+(const float3& v) const;
	float3 operator-(const float3& v) const;
	float3 operator*(const float scalar) const;
	float3 operator/(const float scalar) const;

	// --- Assignment operators ---
	float3& operator+=(const float3& v);
	float3& operator-=(const float3& v);
	float3& operator*=(const float scalar);
	float3& operator/=(const float scalar);


	// --- Vector operations ---


	friend std::ostream& operator<<(std::ostream& out, const float3& v);

};