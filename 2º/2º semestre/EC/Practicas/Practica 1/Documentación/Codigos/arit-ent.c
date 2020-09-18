
int x;
short y1;
unsigned short y2;
char z;

int main() {
  unsigned short a,b;

  x=9;
  z = x + 126;
  a = 4;
  b = a - 7;
  
  z = 9 /2;

  y1 = 128*128 + (128*128-1); // 2^7*2^7) + (2^14-1)
  y1 = y1 + 1; // Comprobar si el resultado es el esperado

  y2 = 128*128 + (128*128-1); // 2^7*2^7) + (2^14-1)
  y2 = y2 + 1; //Comprobar si el resultado es el esperad


  y2 = 256*128 + (256*128-1); // (2^8*2^7) + (2^15-1)
  y2 = y2 + 1; //Comprobar si el resultado es el esperad

  return 0;
}
