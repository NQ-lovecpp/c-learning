#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// 哈夫曼树节点
struct HuffmanNode 
{
    char data;          // 字符
    int frequency;      // 频率
    HuffmanNode* left;  // 左子树指针
    HuffmanNode* right; // 右子树指针

    HuffmanNode(char c, int freq) : data(c), frequency(freq), left(nullptr), right(nullptr) {}
};

// 哈夫曼编码存储结构
typedef map<char, string> HuffmanCode;

class HuffmanCoding 
{
public:
    // 构造函数，接受输入字符串并构建哈夫曼树
    HuffmanCoding(const string& input) 
    {
        BuildHuffmanTree(input);
    }

    // 生成哈夫曼编码
    HuffmanCode GenerateHuffmanCodes() 
    {
        HuffmanCode huffmanCode;
        GenerateHuffmanCodes(root, "", huffmanCode);
        return huffmanCode;
    }

private:
    HuffmanNode* root;

    // 优先队列的比较函数，用于构建哈夫曼树时按频率从小到大排序
    struct CompareHuffmanNode 
    {
        bool operator()(HuffmanNode* a, HuffmanNode* b) {
            return a->frequency > b->frequency;
        }
    };

    // 构建哈夫曼树
    void BuildHuffmanTree(const string& input) 
    {
        // 统计字符频率
        map<char, int> frequencyMap;
        for (char c : input) {
            frequencyMap[c]++;
        }

        // 创建优先队列，按频率从小到大排序
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareHuffmanNode> pq;

        // 初始化优先队列
        for (const auto& pair : frequencyMap) 
        {
            pq.push(new HuffmanNode(pair.first, pair.second));
        }

        // 构建哈夫曼树
        while (pq.size() > 1) 
        {
            HuffmanNode* left = pq.top();
            pq.pop();
            HuffmanNode* right = pq.top();
            pq.pop();

            HuffmanNode* mergedNode = new HuffmanNode('$', left->frequency + right->frequency);
            mergedNode->left = left;
            mergedNode->right = right;
            pq.push(mergedNode);
        }

        root = pq.top();
    }

    // 递归生成哈夫曼编码
    void GenerateHuffmanCodes(HuffmanNode* node, string code, HuffmanCode& huffmanCode) {
        if (!node) 
        {
            return;
        }

        if (node->data != '$') 
        {
            huffmanCode[node->data] = code;
        }

        GenerateHuffmanCodes(node->left, code + "0", huffmanCode);
        GenerateHuffmanCodes(node->right, code + "1", huffmanCode);
    }
};

int main() 
{
    string input = "10,5,21,18,8,13";
    HuffmanCoding huffman(input);
    HuffmanCode huffmanCodes = huffman.GenerateHuffmanCodes();

    cout << "Huffman Codes:" << endl;
    for (const auto& pair : huffmanCodes) 
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
