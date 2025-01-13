# agonlight2-projetcs
Utilities for [agonlight2](https://www.olimex.com/Products/Retro-Computers/AgonLight2/open-source-hardware)

The projects are built with VSCODE AgDev on windows and binaries are provided, that you can put in the /mos directory of the SD-card. Version of MOS and VDP are, console8 MOS 2.10.1 and VDP 2.3.1 or above, not tested with previous versions.  

Currently the program uses the memory address 0x0B000 in the Makefile for AgDev and the program is placed in the `/mos directory`, in a future version of mos, you will be able to put them in the `/bin directory` by modifying the address 0x0B000 to 0x04000 on Makefile, you will need to recompile the program.  
I have done the updates but I may have forgotten some.  
If the program not work, put it to /bin directory and launch ot directly.

In some assembler routines I refer to mos_api.inc via a path relative to where your project is located.
Don't forget to change this path relative to where your source is located: `include '../../lib/libc/mos_api.inc'`  

>Default projet are on folder CEdev/AgExamples/ (MyProject/src, MyProject/bin)

Link for AgDev and instructions for installation [AgDev](https://github.com/pcawte/AgDev).  
Link for VDU 25 PLOT command [PLOT](https://agonconsole8.github.io/agon-docs/vdp/PLOT-Commands/?h=plot).  
Link for VDU commands [VDU](https://agonconsole8.github.io/agon-docs/vdp/VDU-Commands/?h=vdu).  
Link for VDP System Command [VDP](https://agonconsole8.github.io/agon-docs/vdp/System-Commands/?h=vdp).  
Agon MOS TOOLS [Agon-MOS-Tools](https://github.com/nihirash/Agon-MOS-Tools).  
Agon flash [Agon FLASH](https://github.com/envenomator/agon-flash/releases/tag/v1.7).  
Update firmware by Web [Update](https://envenomator.github.io/).  
CP/M 2.2 from nihirash [CP/M 2.2](https://github.com/nihirash/Agon-CPM2.2).  
Firmware [MOS](https://github.com/AgonConsole8/agon-mos).  
Firmware [VDP](https://github.com/AgonConsole8/agon-vdp).

### scani2c
allows you to scan the i2c bus of a module connected to the UEXT connector. The i2c address is displayed if an module i2c is found.

launch scani2c from bin directory.  
Example command line: `scani2c`

output:

`I2C bus scanning`

`Address 0x3C`


### send
allows to send file to RS232 (UEXT) to PC host. Escape Key to cancel transfert.  
Default BAUD is 115200  
Put a file to /bin directory  

**Command line:**  
`send <filename>`    on Agon (ex: send myfile.bin)  
`rcvfile <filename><com port><baud>` on PC hosts (ex: rcvfile myfile.bin COM2)

### dumpview
allows to dump a file to screen.  
Example command line: `dumpview <filename>`  
show readme file from dumpview for more information

### ansiterm
Ansi terminal.  
Put a file to /bin directory  
Example command line: `ansiterm [parameters]` 

`Usage: mosterm [OPTIONS]`  
`-h this help`  
`-b <baud> (default 115200)`  
`-d <databits> (default is 8 (5, 6, 7, 8))`  
`-p <parity> (default is N (N, E, O))`  
`-r Add CRLF`

### ascii
allows show ascii table.  
Put a file to /bin directory  
Example command line: `ascii`

### atconfig

allow configure wifi or restore to default factory the esp8266. Default baud is 115200.  
Show readme file from folder atconfig for more informations.

### comfile  
Allow to transfert binary or text file from PC to Agon
Show readme file from folder comfile for more informations.

### pause  
allows to pause on batch file.  
Put a file to /bin directory  
Example command line: `pause`  
Result: `Press any key to continue ...`

### textprogress  

Sample code that show progress bar on text mode (progress bar, spinner ...)  
Put a file txtprogress.bin to /bin directory  
Example command line: `txtprogress`

### shell  

Alow to show how call shell mos from c code.  
Put a file on /bin directory
Command line: `shell`  

### crc32  

Allow generate the CRC-32 value for the file named in the command line argument.  
Put a file on /bin directory  
Command line: `crc32 <filename>`

### MD5

MD5 Code adapted for AgonLight from Zunawe (https://github.com/Zunawe/md5-c),
forked by MilchRatchet  (https://github.com/MilchRatchet/md5-c)  

Allow calculate MD5 from string or file.  
Put a file on /bin directory  

**Command line:**  
`MD5 <string>   ex: MD5 Hello`  
`MD5 <filename> ex: MD5 myfile.txt`

### CP437  
Allow load font CP437 to Agon  
Put a file on /bin directory  
Parameter reset permit to reset default font for Agon  

Command line: `cp437 [reset]`

### render
Allow rendering 8x8 monochrome bitmap font. Adapted from Daniel Hepper render.  
Put a file on /mos directory  
Command line: `render <char_code>` (ex: render 65)  
Ascii char code range it 0-127 but only 32 to 127 is rendering.  

### listdir  

Allow to show how API FatFs on AgDev work.  
It list mos directory.  
Put a file on /bin directory  
Command line: `listdir`

### keytest
Allow testing keyboard key from UART1.  
You have to connect UART1 to serial with USB-TTL 3.3v on PC and use terminal (teraterm or other).  
or connect keyboard with for example uterm-s or other
Put a file on /bin directory  
Command line: `keytest`  
Press CTRL+C for quit.  
