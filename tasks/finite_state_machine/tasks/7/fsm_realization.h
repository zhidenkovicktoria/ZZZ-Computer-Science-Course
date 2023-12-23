#pragma once

#include "shared_header.h"
#include "state.h"

StateMachine* MakeStateMachine(const char* in_file_name, const char* out_file_name, int32_t shift) {
    StateMachine* sm = (StateMachine*)malloc(sizeof(StateMachine));
    sm->pipeline = MakeStates();
    sm->cur_state = START;
    // Не забыть закрыть
    sm->in_file = fopen(in_file_name, "r");
    sm->out_file = fopen(out_file_name, "w");
    sm->c = ' ';
    sm->char_counter = 0;
    sm->shift = shift;
    return sm;
}

int Step(StateMachine* sm) {
    StateName next = sm->pipeline[(int)sm->cur_state].action(sm);
    if (next == END) {
        return 1;
    }
    sm->cur_state = next;
    return 0;
}

void DeleteStateMachine(StateMachine* sm) {
    fclose(sm->in_file);
    fclose(sm->out_file);
    DeleteStates(sm->pipeline);
    free(sm);
}