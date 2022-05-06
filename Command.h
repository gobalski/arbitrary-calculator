#ifndef COMMAND_H_
#define COMMAND_H_

#include<string>
#include "GB_lib/GreatBin.hpp"

class Command{
    public:
        Command(){};
        virtual std::string exec() { return "weird.. "; };
};


class Calculation : public Command{
    private:
        GreatBin operand1_;
        GreatBin operand2_;
        char op_;
    public:
        Calculation(char, std::vector<std::string>&);

        std::string exec() override;
};


#endif // COMMAND_H_
