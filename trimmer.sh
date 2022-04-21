cat $1 | grep -v "shellcode" | sed -s 's/0x/\\x/g' | sed -s "s/, //g" | tr -d '\n' | tr -d "}" | tr -d ';' ; echo
#Takes 0x00, 0x01, etc. output (no char shellcode[] = ... or unsigned int = ... etc) and turns it into shellcode
#Good for making exploits
