gcc -Wall -Werror -Wextra -pedantic *.c -o hsh#SIMPLE-SHELL
----------------
Description
--------------
Simple shell is a command-line interpreter or shell that provides a command line user interface for unix-like operating systems, in the tradition of the first Unix shell written by Ken Thompson in 1971.
--------------
#Requirements
--------------------------------
The project is designed to run in the Ubuntu 14.04 LTS linux environment and to be compiled using the GNU (Compiler Colletion) version 4.8.4 or never.
---------------
#Installation
---------------------
Clone this repository: git@github.com:DanielBaquero28/simple_shell.git.
Change directories into the repository: cd simple_shell
Compile: gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
Run the shell in interactive mode: ./hsh
Or run the shell  enter the interactive mode after compilation: echo "pwd" | ./hsh