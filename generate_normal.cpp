
#include <iostream>
#include <cmath>

void	normalize(const double *xyz)
{
	const double	v = sqrt((xyz[0] * xyz[0]) + (xyz[1] * xyz[1]) + (xyz[2] * xyz[2]));
	double			normalized[3];

	if (v < 0.1)
		return ;
	normalized[0] = xyz[0] / v;
	normalized[1] = xyz[1] / v;
	normalized[2] = xyz[2] / v;
	std::cout << "Final vector: " << normalized[0] << ',' << normalized[1] << ','  << normalized[2] << std::endl;
}

int main()
{
	double	xyz[3];
	int		size = 3;
	bool	attempt = true;
	std::cout << "Please enter three numbers (X Y Z)" << std::endl;
	for (int i = 0; i < size; i++)
	{
		while (attempt)
		{
			std::cin >> xyz[i];
			std::cin.clear();
			if (!std::cin.fail())
				attempt = false;
			else
				std::cout << "error, try again" << std::endl;
		}
		attempt = true;
	}
	normalize(xyz);
}