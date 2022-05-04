#include "Viewer.h"
#include<iostream>
#include<string>

void Viewer::show(){
    std::cout << this->getContent() << "\n";
}

void Viewer::prompt(){
    std::string content {};
    std::cout << this->getPrefix();
    std::getline(std::cin, content);
    this->setContent(content);
    if (content.length() == 0) prompt();
}
