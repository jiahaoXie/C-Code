//二叉树节点
struct BiTreeNode {
	int data;
	BiTreeNode *left;
	BiTreeNode *right;
};

//写一个类，方便二叉树的建立和删除
class BiTree {
private:
	void deleteAllNode(BiTreeNode *root);
public:
	BiTreeNode *root;
	BiTree();
	~BiTree();
	void CreateTree();
	void deleteLeaves(BiTreeNode *root);
	bool DepthOfTheNode(BiTreeNode *currentNode, BiTreeNode *p, int depthOfFather);
	void FindMaxValue(BiTreeNode *currentNode, int *maxValue);
	void ExchangeLeftAndRight(BiTreeNode *currentNode);
	void OutputValueAndDepthByQIANXU(BiTreeNode *currentNode, int depthOfFather); //不好意思，用了拼音
};