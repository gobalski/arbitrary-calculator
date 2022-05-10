#include "Model.h"
#include <stdexcept>
#include <utility>

void Model::store(std::string& name, std::string& value){
    data_.insert(std::pair<std::string, std::string>(name, value));
}

bool Model::check(std::string & name){
    return data_.find(name) != data_.end();
}

std::string Model::getValueOf(std::string& name){
    if ( !this->check(name) ) return name;
    return data_.at(name);
}
