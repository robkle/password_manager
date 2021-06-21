# password_manager
Unix (command-line) password manager written in C++

Work in progress...  

### Current features
* Password generator  
* Write generated password to file (.store)

### Usage
Repository contains a Makefile for:   
* compiling executable (**make all**)  
* deleting executable (**make fclean**)  
* recompiling (**make re**)    

View passwords:  
```ts
./pwd
```
Insert password for an application (e.g. gmail) and write to file:  
```ts
./pwd insert gmail <password>
```
