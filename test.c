#include <stdio.h>
 
int scope = 1; // global.
 
int main(){
  printf("%d\n", scope); //no scope variable in this scope, go up (to global) and look there.
  {
    int scope = 2; // this is fine!
    {
      int scope = 3; // so is this!
      {
        printf("%d\n",scope); // no scope variable in this scope, it will go ONE up!
      }
      printf("%d\n", scope); // there is a scope variable in this scope, use it
    }
    printf("%d\n", scope); // we re-entered a scope, the child scope is...out-of-scope, and we're now ref'ing a different scope var
  }
  return scope;
}
