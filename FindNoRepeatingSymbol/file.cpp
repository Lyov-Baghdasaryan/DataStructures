#include <iostream>

char FindFirstSymbol(char*, const int&);

int main()
{
	char arr[] = {'a', 'b', 'c', 'v', 'a'};
	const int size = sizeof(arr) / sizeof(char);

	char result = FindFirstSymbol(arr, size);
	std::cout << "size : " << result << std::endl;

	return 0;
}

char FindFirstSymbol(char* ptr, const int &size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(i == j){
				continue;
			}else if(ptr[i] == ptr[j]){
				break;
			}
			if(j == size-1){
				return ptr[i];
			}
		}
	}

	return '_';
}


