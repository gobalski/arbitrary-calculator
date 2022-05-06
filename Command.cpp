#include "Command.h"
#include <stdexcept>

std::string Calculation::exec(){
    switch (op_) {
        case '+':
            std::cout << "trying to add.. " << std::endl;
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
    std::cout << "Calculation initialized.. " << std::endl;
    std::cout << "with: " << std::endl;
    // std::cout << operand1_ << "\n";
    // std::cout << operand2_ << "\n";
    operand1_.print_digits(std::cout) << "\n";
    operand2_.print_digits(std::cout) << "\n";
}
