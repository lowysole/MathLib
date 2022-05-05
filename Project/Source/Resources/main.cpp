#include "float2.h"
#include <iostream>

int main() {

	if (0) {
		float2 f1{ 1.0f, 2.0f };
		float2 f2{ 1.0f, 2.0f };

		float2 f3 = f1 + f2;
		float2 f4 = f1 - f2;
		float2 f5 = f1 * 4;
		float2 f6 = f1 / 2;

		std::cout << f3 << "\n";
		std::cout << f4 << "\n";
		std::cout << f5 << "\n";
		std::cout << f6 << "\n";

		float2 f7;
		std::cout << f7 << "\n";

		float2 f8{ f1 };
		std::cout << f8 << "\n";

		f7 += f1;
		std::cout << f7 << "\n";
		f7 -= float2(2.0f, 4.0f);
		std::cout << f7 << "\n";
		f7 *= 8.0f;
		std::cout << f7 << "\n";
		f7 /= 2;
		std::cout << f7 << "\n";
	}

	float2 f1{ 1.0f, 1.0f };
	float2 f2{ -1.0f, -1.0f };

	float f3 = f1.Dot(f2);
	float angle = f1.AngleBetween(f2);
	std::cout << angle << "\n";
	
}