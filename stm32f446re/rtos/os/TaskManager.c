#include "TaskManager.h"
#include "Os.h"

void create_task(void (*task_func)()) {
    os_add_task(task_func);
}
