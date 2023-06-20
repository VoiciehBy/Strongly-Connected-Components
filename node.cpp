#include "node.h"

node::node(int value, Color color, int discovery_time, int finish_time)
{
	this->value = value;
	this->color = color;
	this->discovery_time = discovery_time;
	this->finish_time = finish_time;
}

node::node(const node& o)
{
	this->value = o.value;
	this->color = o.color;
	this->discovery_time = o.discovery_time;
	this->finish_time = o.finish_time;
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
	std::cout << char('a' + value) << ','
		<< str << ',' << "d:" << discovery_time << ','
		<< "f:" << finish_time << std::endl;
}
