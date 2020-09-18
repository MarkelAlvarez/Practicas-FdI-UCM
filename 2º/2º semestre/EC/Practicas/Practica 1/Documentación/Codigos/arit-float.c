
// Probad primero con las variables como float y posteriormente como double
float f1,f2,f3;

int main() {

  f1 = 1.2;
  f2 = 1.1;
  f3 = f1- f2; 

  
  f1 = 1300235677; // Comprobar su representacion en memoria y pasadlo de nuevo a base 10
  f2 = 0.03;
  f3 = f1 + f2; //  comprobad el resultado

  
  f1 = 1300235677; 
  f2 = f1 / 123.8;
  f3 = f1 - (f2*123 + f2*0.8); 
                               
  if (f3 == 0.0) 
    f3 = 1.0;
  else
    f3 = 2.0;

  return 0;

}

