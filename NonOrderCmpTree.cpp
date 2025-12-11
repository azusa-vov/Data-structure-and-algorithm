#include <list>
#include <string>
#include "TreeNode.h"

// 判断两棵树是否“非序等价”（孩子顺序忽略）：根值相等，且子树集合一一对应
template <class T>
bool SpecialEqualTree(TreeNode<T>* r1, TreeNode<T>* r2) {
	// 均为 nullptr 等价；一个空一个非空不等价
	if ((r1 == nullptr) && (r2 == nullptr)) return true;
	if ((r1 == nullptr) || (r2 == nullptr)) return false;

	// 根值不同直接 false
	if (r1->Value() != r2->Value()) return false;
	// 叶子同时为叶则等价（此时无需比较孩子）
	if (r1->isLeaf() && r2->isLeaf()) return true;

	using namespace std;
	list<TreeNode<T>*> chs1, chs2; // 分别存 r1、r2 的孩子列表

	// 收集 r1 的所有孩子
	for (auto* c1 = r1->LeftMostChild(); c1 != nullptr; c1 = c1->RightSibling()) {
		chs1.push_back(c1);
	}
	// 收集 r2 的所有孩子
	for (auto* c2 = r2->LeftMostChild(); c2 != nullptr; c2 = c2->RightSibling()) {
		chs2.push_back(c2);
	}

	// 孩子数不同直接 false
	if (chs1.size() != chs2.size()) return false;
      list<TreeNode<T>*>::iterator it1,it2;
	// 依次取 r1 的每个子树，去 r2 的孩子列表里找能递归匹配的子树，找到后从 chs2 移除，继续下一个
	for (auto it1 = chs1.begin(); it1 != chs1.end(); ++it1) {
		bool matched = false;
		for (auto it2 = chs2.begin(); it2 != chs2.end(); ++it2) {
			if (SpecialEqualTree(*it1, *it2)) {
				chs2.erase(it2); // 找到匹配则移除，避免重复匹配
				matched = true;
				break;
			}
		}
		if (!matched) return false; // 当前子树未找到匹配
	}

	// 所有子树都找到匹配
	return true;
}

// 根据需要实例化模板（可按用到的类型补充或移除）
template bool SpecialEqualTree<int>(TreeNode<int>*, TreeNode<int>*);
template bool SpecialEqualTree<char>(TreeNode<char>*, TreeNode<char>*);
template bool SpecialEqualTree<std::string>(TreeNode<std::string>*, TreeNode<std::string>*);