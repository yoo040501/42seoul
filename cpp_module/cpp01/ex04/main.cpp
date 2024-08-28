#include <iostream>
#include <fstream>
#include <string>


int	main(int ac, char **av)
{
	std::ifstream inf(av[1]);
	std::ofstream outf;
	std::string outfile;
	std::string contents;
	std::string s1;
	std::string s2;
	int s1_len;
	int s2_len;

	if (ac != 4)
	{
		std::cout << "Error: argc must be 4" << std::endl; 
		return (1);
	}
	s1 = av[2];
	s2 = av[3];
	s1_len = s1.length();
	s2_len = s2.length();
	if (std::strlen(av[1]) == 0 || s1_len == 0 || s2_len == 0)
	{
		std::cout << "Error: argv length is 0" << std::endl; 
		return (1);
	}

	if (inf.is_open())
	{
		std::cout << "Error: can't open " << av[1] << std::endl;
		return (1); 
	}

	outfile = av[1];
	outfile.append(".replace"); 
	outf.open(outfile);
	if (outf.fail())
	{
		std::cout << "Error: can't open " << outfile << std::endl;
		return (1); 
	}

	while (1)
	{
		std::getline(inf, contents);
		
		std::string::size_type pos = 0;
		while (1)
		{
			pos = contents.find(s1, pos);
			if (pos == std::string::npos)
				break ;
			contents.erase(pos, s1_len);
			contents.insert(pos, s2);
			pos += s2_len;
		}
		outf << contents;
		if (inf.eof())
			break ;
		outf << std::endl;	
	}
	return (0);
}
