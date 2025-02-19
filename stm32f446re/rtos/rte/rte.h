#ifndef RTE_H
#define RTE_H

#include <stdint.h>

void rte_init();
void rte_send_data(uint8_t task_id, const char *data);
const char *rte_receive_data(uint8_t task_id);

#endif
