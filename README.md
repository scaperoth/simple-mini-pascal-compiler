simple-mini-pascal-compiler
===========================

mini (very mini) pascal compiler written using flex, bison, c and MIPS

###How to use this

- run ```make```
- using the test files run ```./project3.2 /optionalpath/nameoftestfile.pas```
- the output of this will tell you if your file is syntactically correct and will generate a "nameoftestfile.s" file
- once this file is generated you can run it in Mars to execute your code!

###Dependencies
*Instructions on how to download the first two can be found relatively easily online*  

- flex 
- bison  
- [mars](http://courses.missouristate.edu/KenVollmar/MARS/download.htm)  
  - open the *.s file and hit ```f3``` to assemble the code then ```f5``` to run it

> Note: In Ubuntu, flex and bison can be installed using ```apt-get```  
```$sudo apt-get update```  
```$sudo apt-get upgrade ```  
```$sudo apt-get install flex bison```
