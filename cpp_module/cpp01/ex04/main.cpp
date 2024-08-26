#include <iostream>
#include <fstream>
#include <string>


int	main(int ac, char **av)
{
	if (ac != 4)
		std::cout << "Error: retry again\n";
	else
	{
		std::ifstream in(av[1]);
		std::string newfile;
		std::string s1 = av[2];
		std::string s2 = av[3];
		if (in.is_open()){
			in.seekg(0, std::ios::end); // 위치 지정자를 파일 끝으로 옮긴다.

			int size = in.tellg(); // 그 위치를 읽는다 (파일의 크기)
			newfile.resize(size); // 그 크기의 문자열을 할당

			in.seekg(0, std::ios::beg); // 위치 지정자를 다시 처음으로 옮김
			in.read(&newfile[0], size); // newfile에 파일 내용 저장

			newfile.find(s1);

			std::string	filename = strcat(av[1], ".replace");
			std::ofstream out(filename , std::ios::trunc);
		}

			outfile = av[1];
	outfile.append(".replace"); 
	ofs.open(outfile);
	if (ofs.fail())
	{
		std::cout << "sorry, can't open " << outfile << std::endl;
		return (1); 
	}

	while (true)
	{
		std::getline(ifs, contents);
		
		size_t pos = 0;
		while (true)
		{
			pos = contents.find(s1, pos);
			if (pos == std::string::npos)
			{
				break ;
			}
			contents.erase(pos, s1_len);
			contents.insert(pos, s2);
			pos += s2_len;
		}
		ofs << contents;
		if (ifs.eof())
			break ;
		ofs << std::endl;	
	}
	
	return (0);
	}
}
