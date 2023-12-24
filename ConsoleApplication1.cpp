#include <iostream>
#define CONST_BLOCKS 10
#define CONST_BLOCKSIZE 1024 * 1024
#define CONST_MAXSIZE 10 * 1024 * 1024

struct Object {
    Object() {}
    int index;
    int maxSize = CONST_BLOCKSIZE;
    int allocatedSize;
    char* allocated;
    bool isFree = true;
    int Index;
    Object(int size, int Index) {
        allocatedSize = size;
        isFree = false;
        this->Index = Index;
        allocated = new char[allocatedSize];
    }
};

class Stack {

public:
    Object* array;
    int index = 1;
    int top;
    int CountBlocks = 0;
    int capacity = CONST_BLOCKSIZE;

    Stack(int size = CONST_BLOCKS) {
        array = new Object[size]();
        top = 0;
    }

    void push(int allocatedSize)
    {
        CountBlocks = allocatedSize / capacity;

        if (allocatedSize % CONST_BLOCKSIZE == 0)
        {
            for (int i = 0; i < CountBlocks; i++)
            {
                if (top < CONST_BLOCKS)
                {
                    array[top++] = Object(CONST_BLOCKSIZE, index);
                }
                else {
                    std::cout << "error! memory is full" << std::endl;
                }
            }
            index += 1;
        }
        else
        {
            std::cout << "error! push%1024^2please" << std::endl;
        }
    }

    void print()
    {
        for (int i = 0; i < CONST_BLOCKS; i++) {
            std::cout << i << ". "
                << array[i].Index << " box"
                << " --- memory " << array[i].allocatedSize
                << " --- freedom " << array[i].isFree << std::endl;
        }
    }

    void deleteBlock(int idBox) {
        for (int i = 0; i < top; i++) {
            if (idBox == array[i].Index) {
                array[i].Index = 0;
                array[i].allocatedSize = 0;
                array[i].isFree = true;
                delete array[i].allocated;
            }
        }
    }

    void defrag()
    {
        for (int i = 0; i < top - 1; i++)
        {
            if (array[i].isFree)
            {
                for (int j = i + 1; j < top; j++)
                {
                    std::swap(array[i], array[j]);
                }
            }
        }
    }
    void unification(int a, int b, int c)
    {
        for (int i = 0; i < top; i++) {
            if (a == array[i].Index) {
                array[i].Index = c;
            }
            if (b == array[i].Index) {
                array[i].Index = c;
            }
        }
    }
};

int main() {

    std::string a = "0";
    int x; int y; int z;
    Stack* stack = new Stack();
    while (a != "exit")
    {
        std::cout << "Tearlist commands" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "<><><><><><><><><><><><><><><><>" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "push - int(x) by (x * 1024^2)" << std::endl;
        std::cout << "print" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "deleteBlock - int(x) by x Block" << std::endl;
        std::cout << "unification - int(x, y, z) by (x box + y box = z box) << std::endl";
        std::cout << "" << std::endl;
        std::cout << "defrag" << std::endl;
        std::cout << "<><><><><><><><><><><><><><><><>" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "input command:" << std::endl;
        std::cin >> a;

        if (a == "push") { system("cls"); std::cout << "int x Mb" << std::endl; std::cin >> x; stack->push(x * 1024 * 1024); }
        if (a == "print") { system("cls"); stack->print(); }
        if (a == "deleteBlock") { system("cls"); std::cout << "int x Block" << std::endl; std::cin >> x; stack->deleteBlock(x); }
        if (a == "unification")
        {
            system("cls");
            std::cout << "int(x, y, z) by (x box + y box = z box)" << std::endl;
            std::cout << "int x" << std::endl; std::cin >> x;
            std::cout << "int y" << std::endl; std::cin >> y;
            std::cout << "int z" << std::endl; std::cin >> z;
            stack->unification(x, y, z);
        }
        if (a == "defrag") { system("cls"); stack->defrag(); }
    }
}