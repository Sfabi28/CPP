
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;

std::cout << std::endl;

Animal *arr[10];

for (int i = 0; i < 10; i++)
{
    if (i % 2)
        arr[i] = new Dog();
    else
        arr[i] = new Cat();
}

for (int i = 0; i < 10; i++)
{
    delete arr[i];
}

return 0;

}