#ifndef MAIN_HPP
# define MAIN_HPP

# include <fstream>
# include <iostream>
# include <stdlib.h>

std::string fileToString(std::string str);
int		writeNewFile(std::string content, std::string oldName);
void	replaceStr(std::string &file, std::string toFind,
			std::string toReplace);
#endif