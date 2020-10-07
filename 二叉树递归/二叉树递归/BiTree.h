//�������ڵ�
struct BiTreeNode {
	int data;
	BiTreeNode *left;
	BiTreeNode *right;
};

//дһ���࣬����������Ľ�����ɾ��
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
	void OutputValueAndDepthByQIANXU(BiTreeNode *currentNode, int depthOfFather); //������˼������ƴ��
};