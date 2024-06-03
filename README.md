Purpose:
  Have you find yourself distracted with some nonesense errors while developing your new-fresh TO-DO List?
  Now you don't have to exit focus mode to type error in google, instead you can paste it in StackScraper.
  StackScraper is console based application developed in C++ and CMake.
  With StackScraper you can paste error, and get instant respond with question related to your problem from StackOverflow.
  Question on itself won't help you much, that is why we also include answers ;)

Installation:
  Currently working on 1st version of app

Development:
  For development of app, you need C++ compiler with CMake (VSC with MinGW or other compiler and CMake addon or CLion).
  Also, as we use Conan package manager you need Python 3.6 (or newer) and installed Conan. Follow https://www.jetbrains.com/help/clion/conan-plugin.html for CLion setup with Conan.
  Rest of libs is downloaded runtime with CMake itself.

Coding conventions:
  functions - PascalCase
  rest - camelCase

Comments:
  Doxxygen:
  multiline comment:
  
   /**
    * 
    *  @return 
    */

  singleline comment:
  ///

  inline comment:
  ///<
  
Documentation:
https://michalshy.github.io/StackScraperDox/
