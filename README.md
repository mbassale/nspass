# ownpass: My Own Password Manager
![GitHub top language](https://img.shields.io/github/languages/top/mbassale/ownpass) [![GitHub license](https://img.shields.io/github/license/mbassale/ownpass)](https://github.com/mbassale/ownpass/blob/main/LICENSE) 

This is my own personal password manager to replace paid password services.  
Currently is a desktop application with an encrypted key-value database to store my passwords.  
Then I'll create a swift mobile app to have my passwords on the go.  
I'm programming it on C++ because I want an small app to store my passwords and other secret information.

### Requirements
- C++17 compatible toolchain.
- CMake.
- Boost libraries.
- LibGCrypt.

### Installation

To compile and run this application just run cmake on the sources directory, 
there are two target executables, the executable ownpass, and the tests binary 
that uses [Catch2](https://github.com/catchorg/Catch2) unit testing library.

### Disclaimer.

This is a personal project, released under the MIT license, so obviously **don't
expect any warranty or liability of any kind** when using this application to
store your passwords. **Use it at your own risk!**  

I'm constantly improving this application for my personal use, but this program 
could have defects that might put your personal information at risk.
