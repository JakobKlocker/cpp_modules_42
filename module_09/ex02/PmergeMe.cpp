#include "PmergeMe.hpp"

void	checkForDoubles(std::vector<int> inpVec)
{
	std::sort(inpVec.begin(), inpVec.end());
	if(std::adjacent_find(inpVec.begin(), inpVec.end()) != inpVec.end())
	{
		std::cout << "Duplicate found, quiting." << std::endl;
		std::exit(1);
	}

}

void	insectionVec(std::vector<int> &input, int left, int right)
{
	int	cur;
	int	j;

	for (int i = left + 1; i < right; i++)
	{
		cur = input[i];
		j = i - 1;
		while (j >= left && input[j] > cur)
		{
			input[j + 1] = input[j];
			j--;
		}
		input[j + 1] = cur;
	}
}

void	insectionList(std::list<int> &input, int left, int right)
{
	int	cur;

	std::list<int>::iterator itl = input.begin();
	std::list<int>::iterator itr = input.begin();
	std::list<int>::iterator start, tmp, tmp2;
	std::advance(itl, left);
	std::advance(itr, right);
	start = itl;
	itl++;
	for (; itl != itr; itl++)
	{
		cur = *itl;
		tmp = itl;
		tmp2 = tmp;
		while (tmp != start && *(--tmp2) > cur)
		{
			*tmp = *(tmp2);
			std::advance(tmp, -1);
			tmp2 = tmp;
		}
		*tmp = cur;
	}
}

std::list<int> mergeSortList(std::list<int> &input)
{
	int				l;
	int				m;
	unsigned long	i;
	unsigned long	k;

	l = 0;
	m = input.size() / 2;
	insectionList(input, l, m);
	insectionList(input, m, input.size());
	std::list<int> sorted;
	i = 0;
	k = 0;
	std::list<int>::iterator itl = input.begin();
	std::list<int>::iterator itr = input.begin();
	std::advance(itr, m);
	while (i + k < input.size())
	{
		if (k >= input.size() || (*itl < *itr && i < input.size() / 2))
		{
			sorted.push_back(*itl);
			i++;
			itl++;
		}
		else
		{
			sorted.push_back(*itr);
			k++;
			itr++;
		}
	}
	return (sorted);
}

std::vector<int> mergeSortVec(std::vector<int> &input)
{
	unsigned long	l;
	unsigned long	m;

	l = 0;
	m = input.size() / 2;
	insectionVec(input, l, m);
	insectionVec(input, m, input.size());
	std::vector<int> sorted;
	while ((l + m) - input.size() / 2 < input.size())
	{
		if (m >= input.size() || (input[l] < input[m] && l < input.size() / 2))
		{
			sorted.push_back(input[l]);
			l++;
		}
		else
		{
			sorted.push_back(input[m]);
			m++;
		}
	}
	return (sorted);
}

std::list<int> mergeInsertionSortList(std::list<int> &input)
{
	const int	threshold  = 8;

	if (input.size() <= threshold)
	{
		insectionList(input, 0, input.size());
		return input;
	}
	std::list<int> ret = mergeSortList(input);
	return ret;
}

std::vector<int> mergeInsertionSortVec(std::vector<int> &input)
{
	const int	threshold  = 8;

	if (input.size() <= threshold)
	{
		insectionVec(input, 0, input.size());
		return input;
	}
	std::vector<int> ret = mergeSortVec(input);
	return ret;
}

void	printList(std::list<int> &list)
{
	for (std::list<int>::iterator i = list.begin(); i != list.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

void	printVec(std::vector<int> &vec)
{
	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

void	checkArgv(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		std::cout << "Wrong amount of arguments." << std::endl;
		std::exit(1);
	}
	i = 0;
	for (int i = 1, j = 0; argv[i]; i++)
	{
		while (argv[i][j])
		{
			if (argv[i][j] != ' ' && !isdigit(argv[i][j]))
			{
				std::cout << "Error. Only positive integers" << std::endl;
				std::exit(1);
			}
            j++;
		}
        j = 0;
	}
}

std::list<int> argvToList(char **argv)
{
    std::list<int> ret;
    for(int i = 1; argv[i]; i++)
        ret.push_back(atoi(argv[i]));
    return ret;
}

std::vector<int> argvToVec(char **argv)
{
    std::vector<int> ret;
    for(int i = 1; argv[i]; i++)
        ret.push_back(atoi(argv[i]));
    return ret;
}

// // Constructors
// PmergeMe::PmergeMe()
// {
// 	std::cout << "\e[0;33mDefault Constructor called of PmergeMe\e[0m" << std::endl;
// }

// PmergeMe::PmergeMe(const PmergeMe &copy)
// {
// 	(void) copy;
// 	std::cout << "\e[0;33mCopy Constructor called of PmergeMe\e[0m" << std::endl;
// }

// // Destructor
// PmergeMe::~PmergeMe()
// {
// 	std::cout << "\e[0;31mDestructor called of PmergeMe\e[0m" << std::endl;
// }

// // Operators
// PmergeMe & PmergeMe::operator=(const PmergeMe &assign)
// {
// 	(void) assign;
// 	return (*this);
// }
