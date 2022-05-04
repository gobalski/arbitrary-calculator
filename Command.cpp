#include "Command.h"
#include <stdexcept>

std::string Calculation::exec(){
    switch (op_) {
        case '+':
            return operand1_.add(operand2_).dec_string();
        case '-':
            return operand1_.sub(operand2_).dec_string();
        case '*':
            return operand1_.mul(operand2_).dec_string();
        case '/':
            return operand1_.div(operand2_).first.dec_string();
    }
    throw std::invalid_argument {"Operator not implemented.."};
}


Calculation::Calculation(char op, std::vector<std::string>& operands_vec){
    if (operands_vec.size() != 2) throw std::invalid_argument { "Too many operands.." };
    op_ = op;
    GreatBin operand1_ { operands_vec[0] };
    GreatBin operand2_ { operands_vec[1] };

}
