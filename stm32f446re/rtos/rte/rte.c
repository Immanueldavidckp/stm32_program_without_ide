#include "RTE.h"
#include "Os.h"
#include "Resource.h"

#define MAX_TASKS 5
#define BUFFER_SIZE 256

static char message_buffers[MAX_TASKS][BUFFER_SIZE];

void rte_init() {
    for (int i = 0; i < MAX_TASKS; i++) {
        message_buffers[i][0] = '\0'; // Initialize buffers to empty
    }
}

void rte_send_data(uint8_t task_id, const char *data) {
    if (task_id < MAX_TASKS) {
        lock_resource();  // Prevent simultaneous access
        int i = 0;
        while (data[i] != '\0' && i < BUFFER_SIZE - 1) {
            message_buffers[task_id][i] = data[i];
            i++;
        }
        message_buffers[task_id][i] = '\0'; // Null-terminate string
        unlock_resource();
    }
}

const char *rte_receive_data(uint8_t task_id) {
    if (task_id < MAX_TASKS) {
        return message_buffers[task_id]; // Return buffer content
    }
    return NULL;
}
