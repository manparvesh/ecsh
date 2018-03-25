#include <assert.h>
#include <stdlib.h>

//
// Created by manparvesh on 25/3/18.
//
int main() {
    int status = system("./ecsh > /dev/null");
    assert(status == 0);
    return 0;
}
