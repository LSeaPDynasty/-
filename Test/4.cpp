#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 函数声明
void initializeQueues(vector<queue<int>>& queues, int k);
bool processTrain(vector<int>& inputTrack, vector<queue<int>>& buffers, int& nowOut);

int main() {
    int n, k; // n: 入轨车厢数量, k: 缓冲轨数量
    cin >> n >> k;
    
    vector<int> inputTrack(n);
    for (int i = 0; i < n; ++i) {
        cin >> inputTrack[i];
    }
    
    vector<queue<int>> buffers(k); // 初始化 k 个队列
    int nowOut = 1; // 下一个要输出的车厢编号
    
    if (!processTrain(inputTrack, buffers, nowOut)) {
        cout << "无法完成调度" << endl;
    }
    
    return 0;
}

// 初始化 k 个队列
void initializeQueues(vector<queue<int>>& queues, int k) {
    for (int i = 0; i < k; ++i) {
        queue<int> q;
        queues.push_back(q);
    }
}

// 处理火车车厢调度
bool processTrain(vector<int>& inputTrack, vector<queue<int>>& buffers, int& nowOut) {
    int i = 0; // 入轨车厢索引
    while (i < inputTrack.size()) {
        // 3.1 如果入轨中的车厢编号等于 nowOut
        if (inputTrack[i] == nowOut) {
            cout << "输出车厢: " << inputTrack[i] << endl;
            nowOut++;
            i++;
        } else {
            bool found = false;
            // 3.2 考察每一个缓冲轨队列
            for (int j = 0; j < buffers.size(); ++j) {
                if (!buffers[j].empty() && buffers[j].front() == nowOut) {
                    cout << "从缓冲轨 " << j + 1 << " 输出车厢: " << buffers[j].front() << endl;
                    buffers[j].pop();
                    nowOut++;
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                // 3.3 如果入轨和缓冲轨的队头元素没有编号为 nowOut 的车厢
                int targetQueue = -1;
                for (int j = 0; j < buffers.size(); ++j) {
                    if (buffers[j].empty() || buffers[j].back() < inputTrack[i]) {
                        targetQueue = j;
                        break;
                    }
                }
                
                if (targetQueue != -1) {
                    // 3.3.2 如果 j 存在，则把入轨中的第一个车厢移至缓冲轨 j
                    buffers[targetQueue].push(inputTrack[i]);
                    cout << "将车厢 " << inputTrack[i] << " 移至缓冲轨 " << targetQueue + 1 << endl;
                    i++;
                } else {
                    // 如果没有合适的缓冲轨，说明无法完成调度
                    return false;
                }
            }
        }
    }
    
    // 检查缓冲轨中是否还有剩余车厢
    for (int j = 0; j < buffers.size(); ++j) {
        while (!buffers[j].empty()) {
            if (buffers[j].front() == nowOut) {
                cout << "从缓冲轨 " << j + 1 << " 输出车厢: " << buffers[j].front() << endl;
                buffers[j].pop();
                nowOut++;
            } else {
                return false;
            }
        }
    }
    
    return true;
}