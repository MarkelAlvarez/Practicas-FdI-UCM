/*   1  */  #include <stdio.h>
/*   2  */  typedef struct {
/*   3  */      char data[4096];
/*   4  */      int key;
/*   5  */  } item;
/*   6  */  
/*   7  */  item array[] = {
/*   8  */      {"bill", 3},
/*   9  */      {"neil", 4},
/*  10  */      {"john", 2},
/*  11  */      {"rick", 5},
/*  12  */      {"alex", 1},
/*  13  */  };
/*  14  */  
/*  15  */  void sort(item *a, int n) { 
/*  16  */
/*  17  */      int i = 0, j = 0;
/*  18  */      int s = 1;
/*  19  */  
/*  20  */      for(; i < n & s != 0; i++) {
/*  21  */              s = 0;
/*  22  */              for(j = 0; j < n; j++) {
/*  23  */                      if(a[j].key > a[j+1].key) {
/*  24  */                              item t = a[j];
/*  25  */                              a[j] = a[j+1];
/*  26  */                              a[j+1] = t;
/*  27  */                              s++;
/*  28  */                      }
/*  29  */              }
/*  30  */              n--;
/*  31  */      }
/*  32  */  }
/*  33  */  
/*  34  */  int main()
/*  35  */  {
/*  36  */          int i;
/*  37  */          sort(array,5); 
/*  38  */          for(i = 0; i < 5; i++)
/*  39  */                  printf("array[%d] = {%s, %d}\n",
/*  40  */                          i, array[i].data, array[i].key);
/*  41  */          return 0;
/*  42  */  }
