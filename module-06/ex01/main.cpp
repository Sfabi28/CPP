#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data *data = new Data("Hello", 42);
    uintptr_t raw = Serializer::serialize(data);
    Data *data2 = Serializer::deserialize(raw);

    std::cout << "Raw: " << raw << "\ndata: " << reinterpret_cast<uintptr_t>(data) << std::endl;
    std::cout << "Data 2: " << data2->getStr() << " " << data2->getNum() << std::endl;

    delete data;

    return 0;
}