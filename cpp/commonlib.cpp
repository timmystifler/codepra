#include "commonlib.h"

std::ifstream& open_file(std::ifstream &in, const std::string &filename)
{
	in.close();
	in.clear();

	in.open(file.c_str());
	return in;
}
