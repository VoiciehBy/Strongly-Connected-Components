#include "node.h"

node::node(int value, Color color)
{
	this->value = value;
	this->color = color;
}

node::node(const node& o)
{
	this->value = o.value;
	this->color = o.color;
}

node& node::operator=(const node& o) {
	if (this == &o)
		return *this;
	this->value = o.color;
	return *this;
}

bool node::operator==(const node& o) {
	return value == o.value && color == o.color;
}

bool node::operator<(const node& o)
{
	return value < o.value;
}

void node::printLetter()
{
	std::cout << char('a' + value);
}

void node::print()
{
	std::string str;
	switch (color) {
	case WHITE:
		str = "WHITE";
		break;
	case GRAY:
		str = "GRAY";
		break;
	case BLACK:
		str = "BLACK";
		break;
	}
	std::cout << char('a' + value) << ',' << str << ' ';
}
