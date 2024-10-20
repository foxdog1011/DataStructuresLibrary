#include <stdio.h>
#include <assert.h>
#include "stack.h"

void test_create_stack() {
    Stack* stack = create_stack();
    assert(stack != NULL);
    assert(is_empty(stack));
    free_stack(stack);
    printf("test_create_stack passed.\n");
}

void test_push_pop() {
    Stack* stack = create_stack();
    assert(push(stack, 100) == true);
    assert(push(stack, 200) == true);
    assert(!is_empty(stack));

    int data;
    assert(pop(stack, &data) == true);
    assert(data == 200);
    assert(pop(stack, &data) == true);
    assert(data == 100);
    assert(is_empty(stack));

    free_stack(stack);
    printf("test_push_pop passed.\n");
}

void test_peek() {
    Stack* stack = create_stack();
    push(stack, 300);
    int data;
    assert(peek(stack, &data) == true);
    assert(data == 300);
    assert(!is_empty(stack));
    free_stack(stack);
    printf("test_peek passed.\n");
}

void test_pop_empty() {
    Stack* stack = create_stack();
    int data;
    assert(pop(stack, &data) == false);
    free_stack(stack);
    printf("test_pop_empty passed.\n");
}

int main() {
    test_create_stack();
    test_push_pop();
    test_peek();
    test_pop_empty();
    printf("All stack tests passed.\n");
    return 0;
}
