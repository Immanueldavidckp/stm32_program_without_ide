#include "Os.h"

// Extern variables to track tasks
extern Task tasks[MAX_TASKS];
extern uint8_t current_task;
extern uint8_t task_count;

// Pointer to save the current task stack
void save_context(uint32_t **stack) {
    __asm volatile (
        "MRS   R0, PSP\n"         // Get process stack pointer
        "STMDB R0!, {R4-R11}\n"   // Save registers R4-R11 to stack
        "STR   R0, [%0]\n"        // Save updated stack pointer
        : "=r" (*stack)           // Output operand
        :                          // No input
        : "memory"                 // Clobbered registers
    );
}

// Pointer to restore the new task stack
void restore_context(uint32_t *stack) {
    __asm volatile (
        "LDR   R0, [%0]\n"        // Load new stack pointer
        "LDMIA R0!, {R4-R11}\n"   // Restore registers R4-R11
        "MSR   PSP, R0\n"         // Update process stack pointer
        :                          // No output
        : "r" (stack)              // Input operand
        : "memory"                 // Clobbered registers
    );
}

// PendSV Handler (Switch Tasks)
void PendSV_Handler(void) {
    // Save the context of the current task
    save_context(&tasks[current_task].stack_pointer);

    // Switch to the next task
    current_task = (current_task + 1) % task_count;

    // Restore the context of the new task
    restore_context(tasks[current_task].stack_pointer);
}
