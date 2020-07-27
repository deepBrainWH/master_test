//
// Created by wangheng on 7/27/20.
//
#pragma once
#ifndef MASTER_TEST_QLEARNING_H
#define MASTER_TEST_QLEARNING_H

#include <iostream>
#include <ctime>

using namespace std;


typedef int current_state;
typedef int action;

struct FeedBack{
    current_state next_state;
    float reward;
    bool is_end = false;
};

class QLearning {
private:
    float alpha = 0.01f;
    int n_states = 8;
    int n_actions = 2;
    float reword[9] = {0, 0, 0, 0, 0, 0, 0, 0, 10};
    string actions[2] = {"left", "right"};
    float** q_table;

public:
    void init_q_table();
    //更新环境状态
    void update_environment(current_state, action);

    void choose_action(current_state);

};

void QLearning::init_q_table() {
    this->q_table = new float*[this->n_states];
    for(int i = 0;i<n_states;i++){
        q_table[i] = new float[n_actions];
        for(int j = 0;j<n_actions;j++){
            q_table[i][j] = 0;
        }
    }
    q_table[n_states-1][1] = 10;
}

void QLearning::choose_action(current_state s) {
    FeedBack f;
    srand(time(NULL));
    int i = rand() % 2;
    string action = actions[i];
    if(action == "left"){
        if(s-1 < 0){
            f.next_state = s;
        }else{
            f.next_state = s-1;
        }
        f.reward = this->reword[f.next_state];
    }else{
        if(s+1 == n_states){
            //走到了终点
            f.reward = 10;

        }
    }

}

#endif //MASTER_TEST_QLEARNING_H
