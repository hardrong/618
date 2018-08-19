#include"BinaryTree.h"

BTNode* BuyBTNode(BTDataType x) 
{
	BTNode * buy = (BTNode *)malloc(sizeof(BTNode));
	buy->_data = x;
	buy->_left = NULL;
	buy->_right = NULL;

	return buy;
}
BTNode* CreateBTree(BTDataType* a, int* pIndex, BTDataType invalid)
{
	
	if(a[(*pIndex)] != '#')
	{
		BTNode * root = BuyBTNode(*pIndex);
		root->_data = a[(*pIndex)];
		++(*pIndex);
		root->_left = CreateBTree(a,pIndex,invalid);
		++(*pIndex);
		root->_right = CreateBTree(a,pIndex,invalid);

		return root;

	}
	else
		return NULL;
          
}
void BinaryTreeDestory(BTNode* root)
{
	if(root->_left == NULL && root->_right == NULL)
		{
			free(root);
			root = NULL;
			return;
	    }
	else
	{
		BinaryTreeDestory(root->_left);
		BinaryTreeDestory(root->_right);
	}

	      
}
size_t BTreeSize(BTNode* root)
{

	if(root == NULL)
		return 0;

	return BTreeSize(root->_left)
		+ BTreeSize(root->_right)+ 1;
}
size_t BTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->_left == NULL
		&& root->_right == NULL)
		return 1;

	return BTreeLeafSize(root->_left)
		+ BTreeLeafSize(root->_right);

}
size_t BTreeKLevelSize(BTNode* root, size_t k)
{
	//��ȻҪK��Ľ�㣬��ô��Ҫ�ߵ�K�㣬��Kÿ�μ�һ�����͵�K����
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BTreeKLevelSize(root->_left, k-1)
		+ BTreeKLevelSize(root->_right, k-1);
}
void BTreePrevOrder(BTNode* root)
{
	if( root == NULL)
		return ;
	printf("%d\n",root->_data);
	BTreePrevOrder(root->_left);
	BTreePrevOrder(root->_right);


}
size_t BTreeDepth(BTNode* root,size_t left,size_t right)
{
	//���ȥ����ȣ���һ�ֿ���Ϊȥ�����ǵ�Ȩֵ��Ҳ����·�����
	//����̫���ӣ���������˼���ǵݹ飬��������Ӧ���뵽���»�С��С�»���
	//�ȷ������ڵ㣬������������û������ʱ����ôӦ��������������ȼ�һ��
	//��ͬʱ��������ʱ��Ӧ������ȴ�ļ�һ
	if(root == NULL)
		return 0;
	
      left= BTreeDepth(root->_left,left,right);
	 right= BTreeDepth(root->_right,left,right);

	return (left > right)?left+1:right+1 ;

}
void TestBinaryTree() 
{ 
	int a[] = {1, 2, 3, '#', '#',4,7,'#','#', '#', 5, 6,'#' ,'#' ,'#' }; 
 int sz = 0;
  size_t Depth = 0;
int *index = &sz ; 

BTNode* tree = CreateBTree(a, index, '#'); 
  Depth =   BTreeDepth(tree,0,0);
  printf("%d\n",Depth);
   BTreePrevOrder(tree);
   
}