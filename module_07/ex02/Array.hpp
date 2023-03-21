#ifndef _Array_HPP_
#define _Array_HPP_

#include <iostream>

template<typename T>
class	Array
{
	public	:
		Array () : arr(new T()), n(1){}
		Array (unsigned int nb) : arr(new T[nb]), n(nb){}
		Array (const Array  &obj) {
			this->n = obj.n;
			this->arr = new T[n];
			for(unsigned int i = 0; i < this->n; i++)
			{
				this->arr[i] = obj.arr[i];
			}
		};
		T& operator[](unsigned int i){
			if(i >= this->n)
				throw Array::indexOutOfBoundException();
			return this->arr[i];
		}
		~Array () {delete[] this->arr;};
		Array &operator= (const Array &obj)
		{
			if(this->arr)
				delete [] this->arr;
			this->n = obj.n;
			this->arr = new T[n];
			for(unsigned int i = 0; i < this->n; i++)
			{
				this->arr[i] = obj.arr[i];
			}
			return *this;
		};
		class indexOutOfBoundException : public std::exception
		{
				public:
				const char* what() const throw(){return "Index out of Bound";}
		};

		unsigned int size(){return this->n;}
	private	:
		T *arr;
		unsigned int n;
		//	DataType	attributes.
};

#endif
