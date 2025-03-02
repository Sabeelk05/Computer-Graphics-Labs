#include <iostream>

int main() {
	std::cout << "Hello World! \n" << std::endl;

	float angleInDegrees = 95.0f;
	float pi = 3.1415927f;

	float andgleInRadians = angleInDegrees * pi / 180.0f;
	std::cout << angleInDegrees << " degrees is equal to "
		<< andgleInRadians << " radians." << std::endl;

	std::cout << "\nIf statements\n --------------" << std::endl;
	std::cout << angleInDegrees << " degrees is an ";
	if (angleInDegrees < 90)
		std::cout << "acute angle." << std::endl;
	else
		std::cout << "obtuse angle." << std::endl;

	std::cout << "\nFor loops\n ---------------" << std::endl;
	int powerOfTwo = 1;
	for (unsigned int i = 0; i < 10; i++) {
		powerOfTwo *= 2;
		std::cout << "2^" << i + 1 << " = " << powerOfTwo << std::endl;
	}

	int n, step, nsave;
	n = 10;
	step = 0;
	nsave = n;
	std::cout << "\nWhile loops\n ----------------" << std::endl;

	while (n > 1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else
			n = 3 * n + 1;
		
		step++;
		std::cout << " -> " << n; 
	}

	std::cout << "\n\nThe Collatz sequence starting at " << nsave
		<< "took " << step << "steps to reach 1." << std::endl;



	return 0;
}
