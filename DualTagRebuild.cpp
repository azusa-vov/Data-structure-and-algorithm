#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Node {
    //真实结点
    std::string info;              // 节点数据
    Node* left;                    // 最左孩子
    Node* right;                   // 右兄弟
    explicit Node(std::string v) : info(std::move(v)), left(nullptr), right(nullptr) {}
};

struct DualTag {                    // 带双标记的层次序元素
    int ltag;                       // 1 有左子，0 无
    std::string info;               // 节点数据
    int rtag;                       // 1 有右兄弟，0 无
};

// 按教材图 6.17 的逻辑：已知层次次序的 (ltag, info, rtag) 序列，重建左孩子-右兄弟链
Node* RebuildFromDualTag(const std::vector<DualTag>& seq) {
    if (seq.empty()) return nullptr;                     // 空序列直接返回
    int n = static_cast<int>(seq.size());
    std::vector<Node*> nodes;                            // 逐个创建实际节点
    nodes.reserve(n);
    for (auto& e : seq) nodes.push_back(new Node(e.info));

    std::queue<Node*> pending;                           // 队首是“等待确定最左孩子”的父节点

    for (int i = 0; i < n; ++i) {
        // 1) 兄弟链接：若前一节点 rtag=1，则当前节点是它的右兄弟
        if (i > 0 && seq[i - 1].rtag == 1) {
            nodes[i - 1]->right = nodes[i];
        }

        // 2) 若当前节点有左孩子标记，入队等待稍后确定其最左孩子
        if (seq[i].ltag == 1) {
            pending.push(nodes[i]);
        }

        // 3) 若前一兄弟链结束（rtag=0），当前节点应挂到队首父节点的最左孩子位置
        if (i > 0 && seq[i - 1].rtag == 0 && !pending.empty()) {
            pending.front()->left = nodes[i];
            pending.pop();
        }
    }

    return nodes[0];                                    // 层序首元素为森林首棵树的根
}

// 层次打印验证（左孩子-右兄弟）
void PrintLevel(Node* root) {
    if (!root) return;                                  // 空树直接返回
    std::queue<Node*> q;                                // 层序打印用队列
    for (Node* p = root; p; p = p->right) q.push(p);    // 将每棵树的根入队（支持森林）
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        std::cout << cur->info << ' ';
        for (Node* c = cur->left; c; c = c->right) q.push(c); // 将孩子链入队
    }
    std::cout << "\n";
}

int main() {
    // 教材示例：层次序列 info = A G B C D H I E F J
    // ltag = 0 1 0 1 0 0 1 0 0 0
    // rtag = 1 1 0 1 1 1 1 0 1 0
    std::vector<DualTag> seq = {
        {0, "A", 1}, {1, "G", 1}, {0, "B", 0}, {1, "C", 1}, {0, "D", 1},
        {0, "H", 1}, {1, "I", 1}, {0, "E", 0}, {0, "F", 1}, {0, "J", 0}
    };

    Node* root = RebuildFromDualTag(seq);
    std::cout << "Level order after rebuild:\n";
    PrintLevel(root);

    // 简单释放
    std::queue<Node*> q;
    if (root) {
        for (Node* p = root; p; p = p->right) q.push(p);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            if (cur->left) q.push(cur->left);
            delete cur;
        }
    }
    return 0;
}
