#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int INF = 1000000000;
const int maxBit = 1 << 5;
const int maxNode = 1 << 10;
const int maxCode = 1 << 10;
struct Node
{
    string value;
    float weight;
    int parent;
    int lchild;
    int rchild;
};
struct Code
{
    int bit[maxBit];
    int start;
    string value;
};
Node huffman[maxNode];
Code huffmanCode[maxCode];
int n;
void initHuffmanTree()
{
    for (int i = 0; i < (2 * n) - 1; i++)
    {
        huffman[i].weight = 0;
        huffman[i].value = "";
        huffman[i].parent = -1;
        huffman[i].lchild = -1;
        huffman[i].rchild = -1;
    }
}
void huffmanTree()
{
    for (int i = 0; i < n - 1; i++)
    {
        int m1 = INF;
        int m2 = INF;
        int x1 = 0;
        int x2 = 0;
        for (int j = 0; j < n + i; j++)
        {
            if (huffman[j].weight < m1 && huffman[j].parent == -1)
            {
                m2 = m1;
                x2 = x1;
                m1 = huffman[j].weight;
                x1 = j;
            }
            else if (huffman[j].weight < m2 && huffman[j].parent == -1)
            {
                m2 = huffman[j].weight;
                x2 = j;
            }
        }
        huffman[x1].parent = n + i;
        huffman[x2].parent = n + i;
        huffman[n + i].weight = huffman[x1].weight + huffman[x2].weight;
        huffman[n + i].lchild = x1;
        huffman[n + i].rchild = x2;
    }
}
void huffmanEncoding()
{
    Code cd;
    int child, parent;
    for (int i = 0; i < n; i++)
    {
        cd.value = huffman[i].value;
        cd.start = n - 1;
        child = i;
        parent = huffman[child].parent;
        while (parent != -1)
        {
            if (huffman[parent].lchild == child)
            {
                cd.bit[cd.start] = 0;
            }
            else
            {
                cd.bit[cd.start] = 1;
            }
            cd.start--;
            child = parent;
            parent = huffman[child].parent;
        }
        for (int j = cd.start + 1; j < n; j++)
        {
            huffmanCode[i].bit[j] = cd.bit[j];
        }
        huffmanCode[i].start = cd.start;
        huffmanCode[i].value = cd.value;
    }
}
void printHuffmanCode()
{
    for (int i = 0; i < n; i++)
    {
        cout << "第" << i + 1 << "个字符" << huffmanCode[i].value << "的Huffman编码为：";
        for (int j = huffmanCode[i].start + 1; j < n; j++)
        {
            cout << huffmanCode[i].bit[j];
        }
        if (i != n - 1)
            cout << endl;
    }
    cout << "。" << endl;
}
void HuffmanDecoding(string s)
{
    vector<string> v;
    int ok = 1;
    for (int i = 0; i < s.length();)
    {
        int x = (2 * n) - 1 - 1;
        while (huffman[x].lchild != -1 && huffman[x].rchild != -1)
        {
            if (s[i] == '0')
            {
                x = huffman[x].lchild;
            }
            else
            {
                x = huffman[x].rchild;
            }
            i++;
            if (i == s.length() && huffman[x].lchild != -1)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            v.push_back(huffman[x].value);
        }
    }
    if (ok)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << endl;
    }
    else
    {
        cout << "解码有问题" << endl;
    }
}
int main()
{
    while (true)
    {
        cout << "字符串个数(0退出)：";
        cin >> n;
        if (!n)
        {
            break;
        }
        initHuffmanTree();
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << "/" << n << ":";
            cin >> huffman[i].value;
            cin >> huffman[i].weight;
        }
        huffmanTree();
        huffmanEncoding();
        printHuffmanCode();
        while (true)
        {
            cout << "0,1序列(q退出)：";
            string s;
            cin >> s;
            if (s[0] == 'q')
            {
                cout << endl;
                break;
            }
            cout << "解码后，得出结果为：";
            HuffmanDecoding(s);
        }
    }
    return 0;
}

