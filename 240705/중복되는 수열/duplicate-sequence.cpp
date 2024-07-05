#include <iostream>
#include <string>

#define MAX_N 10000

using namespace std;

// 변수 선언
int n;
string words[MAX_N];

// Trie에 사용되는 노드를 정의합니다.
class TrieNode {
    public:
        // 각 노드에는 '0'부터 '9'까지의 문자에 대응되는 10개의 노드 정보가 관리됩니다.
        TrieNode *children[10];
        // 해당 노드를 기점으로 하나의 단어가 완성되는지를 판단합니다.
        bool is_end;

        // 생성자입니다.
        TrieNode() {
            // 단어 완성에 대한 초기값은 false입니다.
            is_end = false;

            // 각 문자에 대응되는 노드 정보는 처음에 nullptr이 됩니다.
            for(int i = 0; i < 10; i++)
                children[i] = nullptr;
        }
};

// 루트 노드에 해당하는 TrieNode를 처음 만들어줍니다.
TrieNode *root = new TrieNode();

// 단어 s를 Trie에 넣어줍니다.
void InsertWord(string s) {
    // root에서 시작합니다.
    TrieNode *t = root;
    for(int i = 0; i < (int) s.size(); i++) {
        // 문자 순서대로 따라가면 됩니다.
        // '0'부터 '9'까지 사용되므로
        // 각각을 0부터 9까지의 index로 매핑시켜줍니다.
        int index = s[i] - '0';
        // 해당하는 노드가 아직 없다면 새로운 노드를 만들어줍니다.
        if(t->children[index] == nullptr)
            t->children[index] = new TrieNode();
        
        // index에 해당하는 노드로 옮겨갑니다.
        t = t->children[index];
    }
    // 최종 위치에 단어의 끝임을 표시해줍니다.
    t->is_end = true;
}

// 단어 s를 탐색하며
// 도중에 끝이라고 표시된 단어가 있는지 판단합니다.
// 만약 그렇다면 접두사에 해당하는 단어가 존재한다는 뜻입니다.
bool SearchWord(string s) {
    // root에서 시작합니다.
    TrieNode *t = root;
    for(int i = 0; i < (int) s.size(); i++) {
        // 만약 도중에 끝이라고 표시된 단어가 있다면 true를 반환합니다.
        if(t->is_end)
            return true;
        
        // 해당하는 노드를 계속 따라갑니다.
        int index = s[i] - '0';
        t = t->children[index];
    }

    // 끝까지 갔음에도 존재하지 않는다면
    // 그러한 경우가 없다는 뜻입니다.
    return false;
}

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> words[i];

    // Trie에 단어들을 넣어줍니다.
    for(int i = 0; i < n; i++)
        InsertWord(words[i]);
    
    // Trie에서 각 단어들을 탐색하는 도중
    // 끝이라고 표시된 단어가 있는지 확인합니다.
    // 만약 그렇다면 접두사에 해당하는 단어가 존재한다는 뜻입니다.
    bool exists = false;
    for(int i = 0; i < n; i++)
        if(SearchWord(words[i]))
            exists = true;
    
    // 답을 출력합니다.
    if(exists)
        cout << 0;
    else
        cout << 1;

    return 0;
}