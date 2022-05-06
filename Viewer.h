#ifndef VIEWER_H_
#define VIEWER_H_

#include<string>

class Viewer{
    private:
        std::string content {""};
        std::string prefix {"> "};
    public:
        Viewer(){};

        inline void setContent (std::string c) {this->content=c;}
        inline std::string getContent () {return this->content;}
        inline std::string getPrefix () {return this->prefix;}

        void show(const std::string&);
        void prompt();

};


#endif // VIEWER_H_
