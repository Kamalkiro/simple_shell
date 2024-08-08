Repository for the purpose of creating a simple shell 
After writing notes and understanding the key concepts related to the project
The plan to start making the simple shell is to create the main function which will:

1 - Take commands using getline

2 - tokenize them using strtok 

3 - execute commands and arguments using execve

Handling the PATH (environ, _getenv, ...) is intended to be done in other functions.
Functions to write, compare, handle edge cases and replacing unallowed functions will be in other files.
Each file will contain 1 function even if I am allowed up to 5 functions per file to be able to trace them seperatly.
Each file will be named after the function it contains.
