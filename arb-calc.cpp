#include "Viewer.h"
#include "Controler.h"

int main(){
    Controler c {};
    Viewer v {};

    for (int i = 0; i < 10; i++) {
        v.prompt();
        c.eval(v.getContent());
        v.show();
    }

    return 0;
}
