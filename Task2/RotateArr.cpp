#include <iostream>

void RotateFoo(int*, const size_t, size_t);

int main() {

    size_t size;
    size_t n;
    
    std::cout << "Enter size -> ";
    std::cin >> size;
    
    int* arr = new int[size];
    
    std::cout << "Fill array elements" << std::endl;
    for(size_t i = 0; i < size; i++){
        std::cin >> arr[i];
    }
    for(size_t i = 0; i < size; i++){
        std::cout << arr[i] << ' ';
    }
    
    std::cout << "Enter N to rotate the array elements -> ";
    std::cin >> n;
    
    RotateFoo(arr, size, n);
    
    for(size_t i = 0; i < size; i++){
        std::cout << arr[i] << ' ';
    }
    
    delete []arr;

    return 0;
}

void RotateFoo(int* ptr, const size_t size, size_t n){
    n = n % size;
    if(n == 0){
        return;
    }
    
    int* tmp = new int[size-n];
    for(size_t i = 0; i < size-n; i++){
        tmp[i] = ptr[i];
    }
    
    size_t j = 0;
    for(size_t i = 0; i < size; i++){
        ptr[i] = ptr[size-n+i];
        if(i >= n){
            ptr[i] = tmp[j];
            j++;
        }
    }

    delete []tmp;
}
