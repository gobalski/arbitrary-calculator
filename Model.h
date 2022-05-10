#ifndef MODEL_H_
#define MODEL_H_

#include <string>
#include <map>


class Model{
    private:
        std::map<std::string, std::string> data_ {};
    public:
        Model(){};

        /// searches for the given string in the varible map and returns the value of it.
        std::string getValueOf(std::string&);

        /// checks if given key is in the map
        bool check(std::string&);

        /// stores the first parameter as the name of the second value.
        void store(std::string&, std::string&);

};





#endif
