 -- for compile                              g++ filename.cpp    (use any prompt, output renaming is alternative)*

 -- for decompose in assembly                gcc -S filename.cpp   (use any prompt)*

 -- for inspect binary (.exe)                format-hex filename.exe > filename.txt   (use power-shell 5.0 or above)*


 
 -- Revised
 -- for preprocess                       g++ -E file.cpp -o file.ii
 -- for genrate assembly                 g++ -S file.ii -o file.s 
 -- for compile assembly(get obj file)   g++ -c file.s -o file.o
 -- for linking                          g++ file.o

 -- all togather                         g++ -Wall -save-temps file.cpp