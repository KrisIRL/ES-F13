#include "mbed.h"

DigitalOut myled(LED1);
Serial pc(USBRX, USBTX);
Serial dev(p13, p14); // corrected pin mapping

void dev_recv(){
    while(dev.readable()){
        pc.putc(dev.getc()); // added missing semicolon   
    }    
}

void pc_recv(){
    while(pc.readable()){
        dev.putc(pc.getc());    
    }    
}

int main() {
    pc.baud(9600);
    dev.baud(115200); // corrected variable name
    pc.attach(&pc_recv);
    dev.attach(&dev_recv); // corrected function name and parameter
    pc.printf("Hello!! \r\n");
    
    while(1) {
        myled = 1;
        wait(1);
        myled = 0;
        wait(1);
    }
}

/*Errors corrected:
1. Variable name "device1" was corrected to "dev"
2. Function name "atach" was corrected to "attach"
3. The semicolon was added after the line `pc.putc(dev.getc())`.
4. The function name "dev" was corrected to "dev_recv"
5. The correct pins `p13` and `p14` were used for `Serial dev`.

Runtime Error:
The error message indicates that the specified pin mapping for the `Serial` object was not found. In the corrected code, the correct pins `p13` and `p14` are used for `Serial dev`, which should resolve this runtime error.
*/
