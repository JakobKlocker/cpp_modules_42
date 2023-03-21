#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <vector>
#include <deque>
# include <stack>

template <class T, class container=std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		// Constructors
		MutantStack() {};
		MutantStack(const MutantStack &copy){*this = copy;};
		// Destructor
		~MutantStack(){};
		// Operators
		MutantStack & operator=(const MutantStack &assign)
		{ 
			std::stack<T, container>::operator=(assign); 
			return *this;
		};

		typedef typename container::iterator iterator;
		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
};


// template <class T, class container=std::deque<T>>
// class MutantStack
// {
// 	public:
// 		// Constructors
// 		MutantStack() : size (0);
// 		MutantStack(const MutantStack &copy);
		
// 		// Destructor
// 		~MutantStack();
		
// 		// Operators
// 		MutantStack & operator=(const MutantStack &assign);
		
// 		//Functons

// 		// Adds Variable to Container
// 		void push(const T &i)
// 		{
// 			if(mSize >= mStack.max_size)
// 			{
// 				std::cout << "Stack full, can't add " << i << std::endl;
// 				return ;
// 			}
// 			mStack.push_back(i);
// 		}

// 		// Removes last Variable from Container
// 		void pop()
// 		{
// 			mStack.pop_back();
// 		}

// 		unsigned long size()
// 		{
// 			return this->mSize;
// 		}

// 		// Returns last element in Container
// 		T top()
// 		{
// 			if(this->mSize == 0)
// 			{
// 				std::cout << "No element on the stack, 'top' failed" << std::endl;
// 				return 0;
// 			}
// 			return this->mStack[mSize - 1];
// 		}

// 		//returns if Empty
// 		bool empty() const
// 		{
// 			if(this->mSize == 0)
// 				return true;
// 			return false;
// 		}

// 		 MutantStack<T>::iterator  back()
// 		 {
// 			return mStack.back();
// 		 }
// 	private:
// 		unsigned long mSize;
// 		std::vector<T> mStack;
// };

#endif