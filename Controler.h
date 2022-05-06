#ifndef CONTROLER_H_
#define CONTROLER_H_

#include<string>
#include<array>
#include <vector>
#include "Viewer.h"
#include "Command.h"

class Controler{
    private:
        std::string cmd_str_ {};
        std::vector<std::string> cmd_tokens_;
        Command cmd_;
        const std::array<char, 4> OPERATORS_ { '+', '-', '*', '/' };

    public:
        Controler(){};

        void eval(const std::string&);

        /// @brief: takes the command and returns a vector of the form [ operator, operands ..  ]
        std::vector<std::string> tokenize (std::string&);

        /// @brief: searches for a unique operator in cmd_tokens_. If it finds one, it is deleted from cmd_tokens_
        char getOperator();

        /// @brief: checks if any token has a stored variable and replaces it
        void substitute();

        /// @brief: creates an instance of the corresponding command
        void makeCmd();

        void UpperCase(Viewer&);

        inline void setCmd_str(std::string s){ cmd_str_ = s; }
        inline std::string getCmd_str(){ return cmd_str_; }

};

#endif // CONTROLER_H_
