//This is a C++ snippet you can compile to test your shellcode before deployment. 

#include <windows.h>
#include <iostream>

int main() {
	//Just delete these two lines and replace with the contents of your chosen compiled .txt file of shellcode
    unsigned char shellcode[] = { /* FILL IN */ };
    unsigned int shellcode_size = -1; //FILL IN

    HANDLE mem_handle = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_EXECUTE_READWRITE, 0, shellcode_size, NULL);

    void* mem_map = MapViewOfFile(mem_handle, FILE_MAP_ALL_ACCESS | FILE_MAP_EXECUTE, 0x0, 0x0, shellcode_size);

    memcpy(mem_map, shellcode, sizeof(shellcode));

    std::cout << ((int(*)())mem_map)() << std::endl;

    return 0;
}
