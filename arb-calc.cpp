#include "Viewer.h"
#include "Controler.h"
#include <stdexcept>

int main(){
    Model m {};
    Controler c {&m};
    Viewer v {};

    while(!c.done_){
        v.prompt();
        const auto content { v.getContent() };
        std::string result;
        try {
            result = c.eval( content );
        } catch (std::invalid_argument exc) {
            result = exc.what();
        }
        v.show( result );
    }

    return 0;
}
