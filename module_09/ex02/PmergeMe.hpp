#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <list>
# include <vector>
# include <time.h>
# include <iomanip>

std::list<int> mergeSortList(std::list<int> &input);
std::vector<int> mergeSortVec(std::vector<int> &input);

std::list<int> mergeInsertionSortList(std::list<int> &input);
std::vector<int> mergeInsertionSortVec(std::vector<int> &input);

void insectionVec(std::vector<int> &input, int left, int right);
void insectionList(std::list<int> &input, int left, int right);

void printList(std::list<int> &list);
void printVec(std::vector<int> &vec);

void checkForDoubles(std::vector<int> inpVec);

std::list<int> argvToList(char **argv);
std::vector<int> argvToVec(char **argv);

void	checkArgv(int argc, char **argv);

// class PmergeMe
// {
// 	public:
// 		// Constructors
// 		PmergeMe();
// 		PmergeMe(const PmergeMe &copy);
		
// 		// Destructor
// 		~PmergeMe();
		
// 		// Operators
// 		PmergeMe & operator=(const PmergeMe &assign);
		
// 	private:
		
// };

#endif