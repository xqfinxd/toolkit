#include <iostream>
#include <vector>

struct Element {
	std::string hello;
	Element() {}
};

using Vector = std::vector<Element>;

static Vector s_vec = {
	Element(), Element(), Element(), Element(),
};

const Vector GetVector() {
	return s_vec;
}

int main() {
	{
		std::cout << s_vec.size() << std::endl;
		auto vec = GetVector();
		std::cout << vec.size() << std::endl;
	}
	std::cout << s_vec.size() << std::endl;
}