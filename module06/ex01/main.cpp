#include"Serializer.hpp"

int main()
{
    Data* dataPtr = new Data;
    dataPtr->value = 99;

    std::cout<<dataPtr<<std::endl;

    uintptr_t serializedPtr = Serializer::serialize(dataPtr);
    
    std::cout<<sizeof(serializedPtr)<<std::endl;
    std::cout<<sizeof(dataPtr->value)<<std::endl;
    std::cout<<sizeof(dataPtr)<<std::endl;

    Data* deserializedData = Serializer::deserialize(serializedPtr);
    
    std::cout<<serializedPtr<<std::endl;
    std::cout<<deserializedData<<std::endl;

    delete(dataPtr);
}
