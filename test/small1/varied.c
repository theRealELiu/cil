/* An example with various kinds of pointers */

typedef struct list {
  struct list *next; // We'll use this safely
  char *data;
} LIST;

#pragma boxpoly("copy")
void *copy(void *x) {
  return x;
}

int ga[8];

int **w;

int main() {
  int x;
  int * px = &x;
  int * * qx = & px; // SEQ to FSEQ to int
  
  int * * c = copy(qx);
  
  if(x) {
    px = & ga[5];
  } else {
    px ++;
  }
  c += *px;

  {
    char * pw = &w;
    char * * cpw = copy(& pw);

    x = * * cpw;
  }

  {
    int * intcast = (int *)6;
    *px = *intcast;
  }

  {
    int ** pp1, *p2;
    void *v1 = pp1;
    void *v2 = p2;
    v1 = v2;
  }

  {
    void *vi1 = 5;
    void *vi2 = vi1;
  }

  {
    void *vi3 = 5;
    void *vi4 = vi3;
    int *p3 = vi4;
    int **pp4 = vi4;
  }


}
