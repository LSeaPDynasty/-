#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// ��������
void initializeQueues(vector<queue<int>>& queues, int k);
bool processTrain(vector<int>& inputTrack, vector<queue<int>>& buffers, int& nowOut);

int main() {
    int n, k; // n: ��쳵������, k: ���������
    cin >> n >> k;
    
    vector<int> inputTrack(n);
    for (int i = 0; i < n; ++i) {
        cin >> inputTrack[i];
    }
    
    vector<queue<int>> buffers(k); // ��ʼ�� k ������
    int nowOut = 1; // ��һ��Ҫ����ĳ�����
    
    if (!processTrain(inputTrack, buffers, nowOut)) {
        cout << "�޷���ɵ���" << endl;
    }
    
    return 0;
}

// ��ʼ�� k ������
void initializeQueues(vector<queue<int>>& queues, int k) {
    for (int i = 0; i < k; ++i) {
        queue<int> q;
        queues.push_back(q);
    }
}

// ����𳵳������
bool processTrain(vector<int>& inputTrack, vector<queue<int>>& buffers, int& nowOut) {
    int i = 0; // ��쳵������
    while (i < inputTrack.size()) {
        // 3.1 �������еĳ����ŵ��� nowOut
        if (inputTrack[i] == nowOut) {
            cout << "�������: " << inputTrack[i] << endl;
            nowOut++;
            i++;
        } else {
            bool found = false;
            // 3.2 ����ÿһ����������
            for (int j = 0; j < buffers.size(); ++j) {
                if (!buffers[j].empty() && buffers[j].front() == nowOut) {
                    cout << "�ӻ���� " << j + 1 << " �������: " << buffers[j].front() << endl;
                    buffers[j].pop();
                    nowOut++;
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                // 3.3 ������ͻ����Ķ�ͷԪ��û�б��Ϊ nowOut �ĳ���
                int targetQueue = -1;
                for (int j = 0; j < buffers.size(); ++j) {
                    if (buffers[j].empty() || buffers[j].back() < inputTrack[i]) {
                        targetQueue = j;
                        break;
                    }
                }
                
                if (targetQueue != -1) {
                    // 3.3.2 ��� j ���ڣ��������еĵ�һ��������������� j
                    buffers[targetQueue].push(inputTrack[i]);
                    cout << "������ " << inputTrack[i] << " ��������� " << targetQueue + 1 << endl;
                    i++;
                } else {
                    // ���û�к��ʵĻ���죬˵���޷���ɵ���
                    return false;
                }
            }
        }
    }
    
    // ��黺������Ƿ���ʣ�೵��
    for (int j = 0; j < buffers.size(); ++j) {
        while (!buffers[j].empty()) {
            if (buffers[j].front() == nowOut) {
                cout << "�ӻ���� " << j + 1 << " �������: " << buffers[j].front() << endl;
                buffers[j].pop();
                nowOut++;
            } else {
                return false;
            }
        }
    }
    
    return true;
}