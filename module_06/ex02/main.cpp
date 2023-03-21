#include "Base.hpp"

class A : public Base{};
class B : public Base{};
class C:  public Base{};

Base	*generate(void)
{
    int i = rand() % 3;
    if(i == 1)
    {
        std::cout << "Genearted randoom A" << std::endl;
        return new A;
    }
    if(i == 2)
    {
        std::cout << "Genearted randoom B" << std::endl;
        return new B;
    }
    else
    {
        std::cout << "Genearted randoom C" << std::endl;
        return new C;
    }
}

void	identify(Base *p)
{
    std::string classes[] = {"A", "B", "C" };
    if(dynamic_cast<A*>(p) != 0)
    {
        std::cout << "is class A" << std::endl;
    }
    else if(dynamic_cast<B*>(p) != 0)
    {
        std::cout << "is class B" << std::endl;
    }
    else if(dynamic_cast<C*>(p) != 0)
    {
        std::cout << "is class C" << std::endl;
    }
    else
        std::cout << "no valid class found" << std::endl;
}

void	identify(Base &p)
{
        std::string classes[] = {"A", "B", "C" };
    if(dynamic_cast<A*>(&p) != 0)
    {
        std::cout << "is class A" << std::endl;
    }
    else if(dynamic_cast<B*>(&p) != 0)
    {
        std::cout << "is class B" << std::endl;
    }
    else if(dynamic_cast<C*>(&p) != 0)
    {
        std::cout << "is class C" << std::endl;
    }
    else
        std::cout << "no valid class found" << std::endl;
}

int main()
{
    A testA;
    Base *ptr;

    ptr = generate();

    identify(ptr);
    identify(*ptr);

    delete ptr;
    
    ptr = generate();

    identify(ptr);
    identify(*ptr);

    delete ptr;

    ptr = generate();

    identify(ptr);
    identify(*ptr);

    delete ptr;

    ptr = generate();

    identify(ptr);
    identify(*ptr);

    delete ptr;

    ptr = generate();

    identify(ptr);
    identify(*ptr);

    delete ptr;

}