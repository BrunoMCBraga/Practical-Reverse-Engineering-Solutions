#cleaning
rm ./*.o
rm ./lib/*.o
find . -type f -regex "./.*_call" -exec rm {} \;

#Compiling modules

nasm -f elf64 -o ./lib/memcpy.o ./lib/memcpy.asm
nasm -f elf64 -o ./lib/strchr.o ./lib/strchr.asm
nasm -f elf64 -o ./lib/memset.o ./lib/memset.asm
nasm -f elf64 -o ./lib/strcmp.o ./lib/strcmp.asm
nasm -f elf64 -o ./lib/strlen.o ./lib/strlen.asm
nasm -f elf64 -o ./lib/strset.o ./lib/strset.asm

#ld -m elf_i386 "$1.o" -o "$1"
#gcc -m64 -o "$1" "$1.o"


nasm -f elf64 -o "$1_call".o "$1_call".asm

gcc -m64 -o  "$1_call" ./"$1_call".o ./lib/*.o
 
