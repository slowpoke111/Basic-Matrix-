// main.cpp

#include <iostream>
#include <string>

// 1 indexing
class Matrix{
  public:
    int sizeX, sizeY;
    
    int elements[128][128];
    
    Matrix(int SizeY, int SizeX){
      sizeY = SizeY;
      sizeX = SizeX;
      
    }

    void setElement(int x, int y, int value){
      
      *(((int*)elements)+y*sizeX+x) = value;
    }
    
    void setElement(int value){
      for (int i=0; i<sizeY; i++){
        for (int j=0;j<sizeX;j++){
          elements[i][j] = value;
        }  
      }
    }
    
    Matrix operator+(Matrix const& a){
      
      Matrix temp(a.sizeY, a.sizeX);
      
      for (int y=0; y<sizeY; y++){
        for (int x=0;x<sizeX;x++){
          
          temp.elements[y][x] = a.elements[y][x] + elements[y][x]; 
          
        }
      }
      return temp;
    }
    
    std::string toString(){
      std::string out;
      
      for (int i=0;i<sizeY;i++){
        for (int j=0;j<sizeX;j++){
          out += std::to_string(elements[i][j]) + " ";
        }
        out+="\n";
      }
      return out;
    }

};


int main() {

    Matrix x = Matrix(20, 10);
    Matrix y = Matrix(20, 10);
    
    x.setElement(1);
    
    y.setElement(1);
    
   // std::cout<<x.elements;
    Matrix z = x+y;
    
    //std::cout << z;
    
   std::cout << z.toString();
}

