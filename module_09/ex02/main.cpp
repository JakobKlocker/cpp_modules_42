#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	clock_t listTime, vecTime;
    double lTime, vTime;
    checkArgv(argc, argv);
    std::vector<int> inpVec = argvToVec(argv);
    std::list<int> inpList = argvToList(argv);

    checkForDoubles(inpVec);

    std::cout << "Before: ";
    printVec(inpVec);

	listTime = clock();
	inpList = mergeInsertionSortList(inpList);
	lTime =  static_cast<double>(clock() - listTime ) / CLOCKS_PER_SEC * 1000; 

	vecTime = clock();
	inpVec = mergeInsertionSortVec(inpVec);
    vTime = static_cast<double>(clock() - vecTime ) / CLOCKS_PER_SEC * 1000; 

    std::cout << "After: ";
    printVec(inpVec);

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector " 
        << std::setprecision(5) << std::fixed <<  vTime << " us" << std::endl;
    	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list " 
        << std::setprecision(5) << std::fixed << lTime << " us" << std::endl;
}
