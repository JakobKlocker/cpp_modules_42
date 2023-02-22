#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*j;
	const Animal	*i;
	Animal **ptr;
	ptr = new Animal*[20];

	for(int i = 0; i < 20; i++)
	{
		if(i < 10)
			ptr[i] = new Cat();
		else
			ptr[i] = new Dog();
	}
	for(int i = 0; i < 20; i++)
	{
		delete ptr[i];
	}
	delete[] ptr; 
	j = new Dog();
	i = new Cat();
	i->makeSound();
	delete	i;
	delete j; //should not create a leak

	Cat a;
	Cat b;
	b.setIdea("hello");
	a = b;
	a.printIdeaAddr();
	b.printIdeaAddr();
	a.printIdea();
	b.printIdea();
}
