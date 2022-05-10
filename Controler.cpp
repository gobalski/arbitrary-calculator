#include "Controler.h"
#include "Command.h"
#include <iterator>
#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

std::string Controler::eval(const std::string& cmd){
    cmd_str_ = cmd;
    cmd_tokens_ = tokenize(cmd_str_);
    // for ( auto token : cmd_tokens_ ) std::cout << token << " ";
    // std::cout << std::endl;
    makeCmd();
    // std::cout << "executing command.. " << std::endl;
    return cmd_->exec();
}

void Controler::UpperCase(Viewer& v){
    std::string content = v.getContent();
    for (auto it = content.begin(); it != content.end(); it++) {
        *it = toupper(*it);
    }
    v.setContent(content);
}

std::vector<std::string> Controler::tokenize(std::string& cmd_str){
    std::istringstream iss(cmd_str);
    return { std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
}

char Controler::getOperator(){
    char op {'\0'}; // dummy value
    int token_nr { 0 };
    std::vector<std::string> tmp_cmd_tokens = cmd_tokens_;
    for (std::string token : cmd_tokens_) {
        // check if exactly one operator is in cmd_tokens
        for (auto jt = OPERATORS_.begin(); jt!=OPERATORS_.end(); jt++) {
            if (token[0] == *jt){
                if (op=='\0') op = token[0];
                else throw std::invalid_argument{"Too many operators.."};
                tmp_cmd_tokens.erase(tmp_cmd_tokens.begin() + token_nr);
            }
        }
        token_nr++;
    }
    cmd_tokens_ = tmp_cmd_tokens;
    return op;
}

void Controler::substitute(){
    for ( auto it=cmd_tokens_.begin(); it!=cmd_tokens_.end(); it++ ){
        std::string tmp_value { model_->getValueOf(*it) };
        *it = tmp_value;
    }
}

void Controler::makeCmd(){
    substitute();
    char op { getOperator() };

    // std::cout << op << std::endl;
    if ( '+'==op or '-'==op or '*'==op or '/'==op )  this->cmd_ = new Calculation { op, cmd_tokens_ };
    else if ( '='==op )  this->cmd_ = new Assignment { op, cmd_tokens_, model_ };
    else if ( '>'==op and cmd_tokens_[0]=="EULER")  this->cmd_ = new Euler { op, cmd_tokens_ };
    else if ( '>'==op and cmd_tokens_[0]=="FAC")  this->cmd_ = new Factorial { op, cmd_tokens_ };
    else if ( '>'==op and cmd_tokens_[0]=="PI")  this->cmd_ = new Pi { op, cmd_tokens_ };
    else if ( op=='\0' and cmd_tokens_[0]=="exit" ) {
        done_=true;
        this->cmd_ = new GoodBye();
    }
    else if ( op=='\0' ) throw std::invalid_argument { "No operator found.." };

}
