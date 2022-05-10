#include "Command.h"
#include "GB_lib/GB_math.hpp"
#include <stdexcept>

std::string Calculation::exec(){
    switch (op_) {
        case '+':
            // std::cout << "trying to add.. " << std::endl;
            return operand1_.add(operand2_).dec_string();
        case '-':
            if ( operand1_.less(operand2_) ) throw std::invalid_argument { "sub: can't result negative numbers " };
            return operand1_.sub(operand2_).dec_string();
        case '*':
            return operand1_.mul(operand2_).dec_string();
        case '/':
            return operand1_.div(operand2_).first.dec_string();
    }
    throw std::invalid_argument {"Operator not implemented.."};
}

Calculation::Calculation(char op, std::vector<std::string>& operands_vec)
    :op_(op), operand1_ (operands_vec[0]), operand2_(operands_vec[1]) {
    if (operands_vec.size() != 2) throw std::invalid_argument { "Too many operands.." };
    // std::cout << "Calculation initialized.. " << std::endl;
    // std::cout << "with: " << std::endl;
    // std::cout << operand1_ << "\n";
    // std::cout << operand2_ << "\n";
    // operand1_.print_digits(std::cout) << "\n";
    // operand2_.print_digits(std::cout) << "\n";
}


std::string Assignment::exec(){
    if (model_->check(name_)) throw std::invalid_argument { "variable name already taken.. "};
    else {
        model_->store(name_, value_);
        return value_;
    }
}

Assignment::Assignment(char op, std::vector<std::string>& operands_vec, Model* model)
    :op_(op), name_(operands_vec[0]), value_(operands_vec[1]), model_(model){
    if (operands_vec.size() != 2) throw std::invalid_argument { "Too many operands.." };
}


Function::Function(char op, std::vector<std::string>& operands_vec)
    :op_(op){
    name_ = operands_vec[0];
    for ( auto it=operands_vec.begin()+1; it!=operands_vec.end(); it++ ){
        parameters_.push_back(*it);
    }
}

std::string Euler::exec(){
    int precision = std::stoi(parameters_.at(0));
    GreatBinExp e { PrecisionLib::func::E(precision) };
    return e.dec_string();
}

std::string Pi::exec(){
    int precision = std::stoi(parameters_.at(0));
    GreatBinExp pi { PrecisionLib::func::PI(precision) };
    return pi.dec_string();
}

std::string Factorial::exec(){
    int n = std::stoi(parameters_.at(0));
    GreatBin fac { PrecisionLib::func::fac(n) };
    return fac.dec_string();
}
