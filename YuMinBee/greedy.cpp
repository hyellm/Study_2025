#include <stdio.h>
#include <string.h>

int solution(const char* name) {
    int len = strlen(name);
    int answer = 0;

    for (int i = 0; i < len; i++) {
        char c = name[i];
        int up = c - 'A';
        int down = 'Z' - c + 1;
        answer += (up < down) ? up : down;
    }

 
    int move = len - 1; // 그냥 오른쪽으로 움직였을 때

    for (int i = 0; i < len; i++) {
        int next = i + 1;

        while (next < len && name[next] == 'A') {
            next++;
        }

        int back_move = 2 * i + len - next;
        int forward_move = i + 2 * (len - next);
        int cur_move = (back_move < forward_move) ? back_move : forward_move;

        if (cur_move < move)
            move = cur_move;
    }

    answer += move;
    return answer;
}