### For Linux:
* Works for me. ( Using:  **_kubuntu(19.04)_** _[Debian]_ )
* Make sure that **_gcc_** is installed on your system before proceeding further.(It *should* be installed by default unless something was done by the user.)
    * Execute any one in bash: `bash gcc --version `  **or**  `bash g++ --version `  **or**  `bash cc --version `
    * If you get output like this, you can move to further steps: ```bash
cc (Ubuntu 8.3.0-6ubuntu1) 8.3.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
```
    * If you're not getting the above output (**_gcc_** is not installed) then execute this in bash: ```bash
sudo apt-get install gcc 
```
* Install codeblocks using: 
```bash
sudo apt-get install codeblocks 
```
* Install GL library:
```bash
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev 
```
* Try compiling and running this code in codeblocks:
```cpp
#include<GL/glut.h>
int main(){return 0;}
```
* After running the c++ code:
    * If it compiles **successfully** then you're good to go.
    * If it doesn't then try following the steps once again carefully, else Google is your best friend.

***
    
### For Windows:

* Follow this video, if you have better way of doing this then let me know I'll try to include it here :
    * [Go to Youtube link...](https://www.youtube.com/watch?v=HtJAQS2YDCY "It's not my video btw")
