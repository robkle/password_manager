# password_manager
Unix (command-line) password manager written in C++

Work in progress...   

### Current features
* Insert passwords to file (.store)  
* View passwords  
* Remove passwords  

### Usage
Repository contains a Makefile for:   
* compiling executable (**make all**)  
* deleting executable (**make clean**)  
* recompiling (**make re**)    

View all stored passwords:  
```ts
./pw
```
View stored password for defined application:  
```ts
./pw <application>  
```
Generate and display password:
```ts
./pw create
```
Insert user defined password for an application:  
```ts
./pw create <application> <password>
```
Insert generated password for an application:
```ts
./pw create <application>
```
Remove password from file:
```ts
./pw remove <application>  
```
