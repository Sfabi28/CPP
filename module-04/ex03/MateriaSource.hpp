#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class   MateriaSource : public IMateriaSource
{
    private:
		AMateria* materias[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &source);
        MateriaSource &operator = (const MateriaSource &source);
        ~MateriaSource();

    	void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};

#endif