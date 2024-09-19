#include <iostream>
#include <math.h>

class Circle
{
    public:
        Circle() : x(0),y(0),r(0) {}
        Circle(double x, double y, double r) : x(x),y(y),r(r) {}
        
        double getR(){ 
            return r;
        }
        bool Touch(const Circle& other){
            double tmp = sqrt((x-other.x) * (x-other.x) + (y-other.y) * (y-other.y));
            return tmp == r + other.r;
        }
        bool Contain(const Circle& other){
            double tmp = sqrt((x-other.x) * (x-other.x) + (y-other.y) * (y-other.y));
            return tmp + other.r <= r;
        }
        bool NotContain(const Circle& other){
            double tmp = sqrt((x-other.x) * (x-other.x) + (y-other.y) * (y-other.y));
            return tmp > r + other.r;
        }
    private:
        double x;
        double y;
        double r;
};

void isTouch(Circle *arr, int len){
    Circle max = arr[0];
    for(int i = 1; i < len; i++){
        if(max.getR()< arr[i].getR()){
            max = arr[i];
        }
    }
    for(int i = 0; i < len; i++){
        if(max.Contain(arr[i]) == 0){
            std::cout << "NO" << std::endl;
            return;
        }
    }

    std::cout << "Yes" << std::endl;
}

void isContain(Circle *arr, int len){
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(i != j && arr[i].NotContain(arr[j]) == 0){
                std::cout << "No" << std::endl;
                return;
            }
        }
    }

    std::cout << "Yes" << std::endl;
}

void isNotContain(Circle *arr, int len){
    int num = 0;
    int max_count = 0;
    for(int i = 0; i < len; i++){
    int count = 0;
    for(int j = 0; j < len; j++){
            if(arr[i].Touch(arr[j]) ){
                count++;
            }
        }
        if(max_count < count){
            max_count = count;
            num = i;
        }
    }
    std::cout << num << std::endl;
}

int main(){
    int n;
    std::cout << "Enter n -> ";
    std::cin >> n;
    Circle* arr = new Circle[n];
    
    for(int i = 0; i < n; i++){
        std::cout << "< " << i+1 << " >" << std::endl;
        double x = 0;
        double y = 0;
        double r = 0;
        std::cout << "x = ";
        std::cin >> x;
        std::cout << "y = ";
        std::cin >> y;
        std::cout << "r = ";
        std::cin >> r;
        arr[i] = Circle(x,y,r);
    }
    
    isTouch(arr,n);
    isContain(arr,n);
    isNotContain(arr,n);

    delete []arr;
}
