#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "materiasource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &source)
{
    std::cout << "materiasource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        materias[i] = source.materias[i];
}

MateriaSource& MateriaSource::operator = (const MateriaSource &source)
{
    std::cout << "materiasource copy operator called" << std::endl;
    if (this != &source)
    {
        for (int i = 0; i < 4; i++)
        {
            if (materias[i])
                delete (materias[i]);
            materias[i] = source.materias[i];
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "materiasource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete (materias[i]);
    }
}

void    MateriaSource::learnMateria(AMateria* materia)
{
    int i = 0;

    while (materias[i])
        i++;
    if (i == 4 || materia == NULL)
        return ;
    materias[i] = materia;
    std::cout << "materia saved" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;

    while (materias[i])
    {
        if (materias[i]->getType() == type)
        {
            std::cout << type << " materia created" << std::endl;
            return (materias[i]->clone());
        }
        i++;
    }
    return (NULL);
}