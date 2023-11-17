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
                << " --- freedom "  << array[i].isFree << std::endl;
        }
    }

    void deleteBlock(int idBox) {
        for (int i = 0; i < top; i++) {
            if (idBox == array[i].Index) {
                array[i].Index = -842150451;
                array[i].allocatedSize = -842150451;
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
                    std::swap(array[i],array[j]);
                }
            }
        }
    }
    void unification(int a,int b,int c) 
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

    Stack* stack = new Stack();
    stack->push(1 * 1024 * 1024);
    stack->push(2 * 1024 * 1024);
    stack->push(3 * 1024 * 1024);
    stack->print();
    stack->deleteBlock(2);
    stack->unification(1, 3, 1);
    stack->defrag();
    stack->print();


}
