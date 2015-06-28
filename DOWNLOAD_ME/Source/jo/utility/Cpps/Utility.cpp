#include"../Utility.h"
#include"../../Othello/Color.h"

using namespace jo;

Color jo::randomColor()
{
	static auto engine = std::mt19937(std::random_device()());

	return std::uniform_int_distribution<>(0, 1)(engine) == 0 ?
		jo::Color::dark() : jo::Color::light();
}
