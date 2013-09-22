#include "commonlib.h"
#include "text.h"
#include <fstream>
#include <set>
#include <cstdlib>
using namespace std;


void print_results(const set<TextQuery::line_no>& locs,
		const string & sought, const TextQuery &file)
{
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();

	cout << "\n" << sought << "occurs "
		 << size << " "
}

int main(int argc, char **argv)
{
	ifstream infile;
	if(argc < 2 || !open_file(infile, argv[1]))
	{
		cerr << "no input file!" << endl;
		return EXIT_FAILURE;
	}
	TextQuery tq;
	tq.read_file(infile);

	while(1)
	{
		cout << "enter the word to look for, or q to quit:";
		string word;
		cin >> word;
		if(!cin || word == q)
			break;
		set<TextQuery::line_no> locs = tq.run_query(word);

		print_results(locs, word, tq);
	}
}
