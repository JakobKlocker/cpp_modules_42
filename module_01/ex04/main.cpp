#include "main.hpp"

int	main(int argc, char **argv)
{
    std::string file;
	if (argc != 4)
    {
        std::cout << "Wrong amout of args\n";
        return (-1);
    }
    file = fileToString(argv[1]);
    if(file.empty())
    {
        std::cout << "File is empty/not found or not sufficent permitions\n";
        return (-1);
    }
    replaceStr(file, argv[2], argv[3]);
    writeNewFile(file, argv[1]);
}

int    writeNewFile(std::string content, std::string oldName)
{
    std::fstream newFile;
    newFile.open((oldName + ".replace").c_str(), std::ios::out);
    if(newFile.fail())
    {
        std::cout << "Failed opening file\n";
        return -1;
    }
    newFile << content;
    return 0;
}

void    replaceStr(std::string &file, std::string toFind, std::string toReplace)
{
    int pos;
    while(file.find(toFind) != std::string::npos)
    {
        pos = file.find(toFind);
        file.erase(pos, toFind.length());
        file.insert(pos, toReplace);
    }
}

std::string fileToString(std::string str)
{
    std::string ret;
	std::fstream file;
	file.open(str.c_str(), std::ios::in);
	if (file.fail() || !file)
		return (ret);
	std::string line;
	while (getline(file, line))
	{
        ret = ret + line;
        if (!file.eof())
            ret = ret + "\n";
	}
    return (ret);
}
