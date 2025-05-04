# Coding Standard
The following rules are to be followed during development.
These guidelines will be dynamically updated.
1. [Bad Practice](#1-bad-practice)
2. [Scope size](#2-function-size)
3. [Nesting](#3-nesting)
4. [Comments](#4-comments)
5. [Scope purpose](#5-scope)
6. [MACROS](#6-macros)
7. [namingConvention](#7-namingConvention)
8. [Commits](#8-commits)
9. [Exceptions/Error-handling](#9-exceptions-and-errors)

## 1. Bad Practice 
The following practices are never to be used without proper reason.

- **GOTO statements**: Leads to unreadable error prone spaghetti code
- **not checking return values**: Not checking return values of non void functions leads to unexpected / error prone behaviour.
- **Unitiliazed variables**: Unpredictable behaviour , espacially when deealing with raw pointers.
- **raw pointers**: C++ offers smart pointers that deal with the memory management, not using these amplifies the complexity of the code.



## 2. Scope size
The size of the scope of functions and classes shouldn't exceed a certain limit to mantain readability.
1. The size of functions should generally be kept under **35 lines of code**, this is to avoid going against the **Single-Responsibility-Principle**. This is not a hard limit , exceptions can happen, but they should be the **exception**.
2. The size of classes (this references only the header declaration, not the implementation), shpuldn't exceed **70 lines of code**. This is a generous limit , meaning the goal should be to actually keep it way belo 70 , we don't want Monolithic classes.


## 3. Nesting
Whenever dealing with loops/if-statements/case statements , there should be a hard limit as to how deep nesting is allowed. 
Nesting makes the code **exponentially** unreadable.           
The limit for nesting is 2, this mean the following:


``` 
if(condition){
    if(anotherCondition){
        // No more if!
    }
}
```
**Should there be a case where the nesting goes to a third level , the code should be redone.This is a hard limit**

## 4. Comments
Comments are good practice and are more damaging in absence than in abundance. To mantain readability , comments should be written in blocks of logic.
``` 
/*
Comment here what the next block of 
Code does , do not comment line for line. 
*/

int userInput = convertInput(userStringInput);
if(userInput == 5){
    cout << "User inputted 5 << endl;
}
```
A class/function should always have a comment in the beginning defining purpose,behaviour,input and output values.

## 5. Scope purpose
This is part is crucial to adhere to good practice of OOP. 
**A function or a class should always do one thing, this lets us adhere to the DRY and SRP principles.** 
Including whatever functionality we have already coded without having to think about dependencies and repeating ourselves.

## 6. MACROS
Whenever using constant reocurring variables that are used as a reference value , these should be handled with enums/defines, to mantain readibility and not with inconsitent named variables.

## 7. namingConvention
To keep a coherent style and mantain readibility , the naming convention for classes and variables is camelCase.     
For reference: [https://en.wikipedia.org/wiki/Camel_case](url)   
In this project the convention starts with lower letter, this means we dont use CamelCase, rather **camelCase**.

## 8. Commits
Commits should be done , with a coherent piece of code , this mean not uploading half finished functions. The commit message should explicitely explain what was changed and wheter or not a new feature has been tested.

## 9. Exceptions and Errors

Proper exception and error handling ensures the application is robust, debuggable, and does not crash unexpectedly. The following guidelines apply:

- **Always catch known exceptions**: Handle all known exception types gracefully. Do not use empty `catch(...)` blocks.

```cpp
try {
    doSomething();
} catch (const std::runtime_error& e) {
    logError(e.what());
}
