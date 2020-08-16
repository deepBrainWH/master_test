//
// Created by wangheng on 7/27/20.
//
#pragma once
#ifndef MASTER_TEST_QLEARNING_H
#define MASTER_TEST_QLEARNING_H

#include <iostream>
#include <ctime>

using namespace std;

struct FeedBack {
    int next_state;
    float reward;
    bool is_end = false;
};

class QLearning {
private:
    float alpha = 0.01f;
    float lambda = 0.9f;
    float MAX_EPISODES = 20;
    int n_states = 8;
    int n_actions = 2;
    float reword[9] = {0, 0, 0, 0, 0, 0, 0, 0, 10};
    string actions[2] = {"left", "right"};
    float **q_table;
    int current_state = 0;


public:
    void init_q_table();

    void update_environment(int, int);

    /**
     * 获取环境反馈
     */
    FeedBack get_env_feed_back(string action) {
        FeedBack f = FeedBack();
        if (action == "left") {
            if (current_state - 1 < 0) {
                f.next_state = current_state;
            } else {
                f.next_state = current_state - 1;
            }
            f.reward = reword[f.next_state];
        } else {
            if (current_state + 1 == n_states) {
                //走到了终点
                f.reward = 10;
                f.is_end = true;
            }
        }
        return f;
    }

};

void QLearning::init_q_table() {
    this->q_table = new float *[this->n_states];
    for (int i = 0; i < n_states; i++) {
        q_table[i] = new float[n_actions];
        for (int j = 0; j < n_actions; j++) {
            q_table[i][j] = 0;
        }
    }
    q_table[n_states - 1][1] = 10;
}


#endif //MASTER_TEST_QLEARNING_H
