#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// 트라이 노드를 정의하는 클래스
class TrieNode
{
public:
    unordered_map<char, TrieNode*> children; // 자식 노드를 저장하는 맵
    bool isEndOfWord; // 단어의 끝을 표시하는 플래그

    // 생성자: isEndOfWord를 false로 초기화
    TrieNode() : isEndOfWord(false) {}
};

// 트라이 구조를 정의하는 클래스
class Trie
{
private:
    TrieNode* root; // 루트 노드를 가리킴

    // 모든 노드를 삭제하는 재귀 함수
    void deleteNodes(TrieNode* node)
    {
        for (auto& child : node->children)
        {
            deleteNodes(child.second); // 자식 노드를 재귀적으로 삭제
        }
        delete node; // 현재 노드 삭제
    }

public:
    // 생성자: 루트 노드를 초기화
    Trie()
    {
        root = new TrieNode();
    }

    // 소멸자: 모든 노드를 삭제하여 메모리 해제
    ~Trie()
    {
        deleteNodes(root); // 루트 노드부터 모든 노드 삭제
    }

    // 문자열을 트라이에 삽입하는 함수
    void insert(const string& word)
    {
        TrieNode* node = root;
        for (char ch : word) // 단어의 각 문자를 순회
        {
            // 문자가 자식 노드에 없다면 새로 추가
            if (node->children.find(ch) == node->children.end())
            {
                node->children[ch] = new TrieNode();
            }
            // 다음 노드로 이동
            node = node->children[ch];
        }
        // 단어의 끝에 도달했음을 표시
        node->isEndOfWord = true;
    }

    // 문자열이 트라이에 있는 단어의 접두사인지 확인하는 함수
    bool startsWith(const string& prefix)
    {
        TrieNode* node = root;
        for (char ch : prefix) // 접두사의 각 문자를 순회
        {
            // 문자가 자식 노드에 없으면 접두사 아님
            if (node->children.find(ch) == node->children.end())
            {
                return false;
            }
            // 다음 노드로 이동
            node = node->children[ch];
        }
        return true; // 모든 문자 순회 시 접두사 확인 완료
    }
};

int main()
{
    ios::sync_with_stdio(false); // C 표준 입출력과의 동기화 비활성화
    cin.tie(nullptr); // cin과 cout의 묶음을 해제하여 입출력 성능 향상

    int N, M;
    cin >> N >> M;
    Trie trie;
    string word;

    // S 집합의 단어들을 트라이에 삽입
    for (int i = 0; i < N; ++i)
    {
        cin >> word;
        trie.insert(word);
    }

    int count = 0;

    // P 집합의 각 단어가 접두사로 존재하는지 확인
    for (int i = 0; i < M; ++i)
    {
        cin >> word;
        if (trie.startsWith(word))
        {
            ++count;
        }
    }

    // 접두사로 존재하는 단어의 개수 출력
    cout << count << '\n';

    return 0;
}
