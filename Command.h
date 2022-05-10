#ifndef COMMAND_H_
#define COMMAND_H_

#include <stdexcept>
#include<string>
#include <vector>
#include "GB_lib/GB_math.hpp"
#include "Model.h"

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

class Assignment : public Command{
    private:
        std::string name_;
        std::string value_;
        char op_;
        Model* model_;
    public:
        Assignment(char, std::vector<std::string>&, Model*);
        std::string exec() override;
};

class Function : public Command{
    protected:
        std::string name_;
        std::vector<std::string> parameters_;
        char op_;
    public:
        Function (char, std::vector<std::string>&);
};

class Euler : public Function{
    public:
        Euler (char op, std::vector<std::string>& operands)
        : Function(op, operands){
            if ( parameters_.size() != 1 ) throw std::invalid_argument { "not the right number of arguments given.. " };
        }
        std::string exec() override;
};


class Pi : public Function{
    public:
        Pi (char op, std::vector<std::string>& operands)
        : Function(op, operands){
            if ( parameters_.size() != 1 ) throw std::invalid_argument { "not the right number of arguments given.. " };
        }
        std::string exec() override;
};

class Factorial : public Function{
    public:
        Factorial (char op, std::vector<std::string>& operands)
        : Function(op, operands){
            if ( parameters_.size() != 1 ) throw std::invalid_argument { "not the right number of arguments given.. " };
        }
        std::string exec() override;
};

class GoodBye : public Command{
    public:
        GoodBye(){};
        std::string exec() override { return "Good Bye"; };
};

#endif // COMMAND_H_
