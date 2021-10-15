#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/init.h"
#include "threads/thread.h"

static thread_func thread_fun;
void my_test (void) 
{
    for(int i = 0; i < 5; i++){
        char name [20];
        snprintf(name, 20,"%s%d","thread ", i);
        thread_create (name, PRI_DEFAULT + 1, thread_fun, NULL);
        display_threadsReadyList();

    }
 

}

static void
thread_fun (void *aux UNUSED) 
{
  msg ("Thread created! Name: %s, TID: %d\n",thread_name(), thread_tid());

  print_thread_info(thread_current());

  msg ("Thread finised! Name: %s, TID: %d\n",thread_name(), thread_tid());
}
