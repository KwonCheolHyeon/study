#include <iostream>
#include <string>
#include <deque>
#include <map>

enum Command {
    PUSH_FRONT,
    PUSH_BACK,
    POP_FRONT,
    POP_BACK,
    SIZE,
    EMPTY,
    FRONT,
    BACK,
    UNKNOWN
};

std::map<std::string, Command> commandMap = {
    {"push_front", PUSH_FRONT},
    {"push_back", PUSH_BACK},
    {"pop_front", POP_FRONT},
    {"pop_back", POP_BACK},
    {"size", SIZE},
    {"empty", EMPTY},
    {"front", FRONT},
    {"back", BACK}
};

void compareCommend(const std::string& _com, std::deque<int>& dq, int _index = -1);

int main() {
    int N = 0;
    std::cin >> N;
    std::cin.ignore(); // 줄 바꿈 문자 소비

    std::deque<int> deq;

    for (int index = 0; index < N; index++) {
        std::string commend;
        getline(std::cin, commend);

        if (commend.empty()) {
            --index;
            continue;
        }

        size_t space_pos = commend.find(' ');
        int number = (space_pos != std::string::npos) ? std::stoi(commend.substr(space_pos + 1)) : -1;

        compareCommend(commend.substr(0, (space_pos == std::string::npos) ? commend.size() : space_pos), deq, number);
    }

    return 0;
}

void compareCommend(const std::string& _com, std::deque<int>& dq, int _index) {
    switch (commandMap[_com]) 
    {
    case PUSH_FRONT:
        dq.push_front(_index);
        break;
    case PUSH_BACK:
        dq.push_back(_index);
        break;
    case POP_FRONT:
        if (!dq.empty()) {
            std::cout << dq.front() << std::endl;
            dq.pop_front();
        }
        else {
            std::cout << -1 << std::endl;
        }
        break;
    case POP_BACK:
        if (!dq.empty()) {
            std::cout << dq.back() << std::endl;
            dq.pop_back();
        }
        else {
            std::cout << -1 << std::endl;
        }
        break;
    case SIZE:
        std::cout << dq.size() << std::endl;
        break;
    case EMPTY:
        std::cout << (dq.empty() ? 1 : 0) << std::endl;
        break;
    case FRONT:
        if (!dq.empty()) {
            std::cout << dq.front() << std::endl;
        }
        else {
            std::cout << -1 << std::endl;
        }
        break;
    case BACK:
        if (!dq.empty()) {
            std::cout << dq.back() << std::endl;
        }
        else {
            std::cout << -1 << std::endl;
        }
        break;
    default:
        // 알 수 없는 명령
        break;
    }
}
