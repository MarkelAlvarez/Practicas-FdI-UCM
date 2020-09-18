
int x; // 4 bytes
short y; // 2 bytes
char z; // 1 byte
int main() {
  unsigned short a,b; // 1 byte 
    
  // representacion de enteros (4,2 y 1 byte)
  // Comprobar direcciones de cada uno, endiannes, tamaño...
	x = 3; 
	y = -1; 
  z = 129;  
  a = x - 7; 
  b = 4; 
  return 0;
}
