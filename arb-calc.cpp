#include "Viewer.h"
#include "Controler.h"

int main(){
    Controler c {};
    Viewer v {};

    for (int i = 0; i < 10; i++) {
        v.prompt();
        const auto content { v.getContent() };
        c.eval( content );
        v.show();
    }

    return 0;
}
