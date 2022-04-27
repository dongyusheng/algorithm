// https://blog.csdn.net/qq_41453285/article/details/108050681
#include <iostream>
#include <stdexcept>

using namespace std;

struct BinaryTreeNode
{
    int             m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

BinaryTreeNode* ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder);

/**
 * @description: 构建二叉树
 * @param:
        preorder:  前序遍历数组
        inorder:   中序遍历数组
        length:    数组大小, 遍历结果的数量都是一样的, 所以上面的数组大小也是一样的
 * @return: 重构二叉树的根节点
 * @author: Dongshao
 */
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <=0)
        return NULL;
    
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}


/**
 * @description: 构建二叉树
 * @param :
        startPreorder: 前序遍历数组的起点
        endPreorder:   前序遍历数组的终点
        startInorder   中序遍历数组的起点
        endInorder:    中序遍历数组的终点
 * @return: 重构二叉树的根节点
 * @author: Dongshao
 */
BinaryTreeNode* ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
    // 得到根节点的值
    int rootValue = startPreorder[0];

    // 创建根节点
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;

    // 如果最后只有一个元素了, 那么直接将这个节点返回就可以了
    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            throw std::runtime_error("Invalid input");
    }
    
    // 在中序遍历中找到根节点的值
    int *rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;
    // 如果在中序遍历中没有找到根节点的值, 说明输入的数组有误
    if(rootInorder == endInorder && *rootInorder != rootValue)
        throw std::runtime_error("Invalid input");
    

    // 在中序遍历中找到根节点之后, 中序遍历的左侧的都是左子树, 中序遍历的右侧的都是右子树
    int leftLength = rootInorder - startInorder;       // 中序遍历中根节点左侧的节点数量
    int *leftPreorderEnd = startPreorder + leftLength; // 根据leftLnegth, 就可以确定左子树在前序遍历中的数量了
    // 构建左子树
    if(leftLength > 0)
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder -1);
    // 构建右子树
    if(leftLength < endPreorder - startPreorder)
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);

    return root;
}


// 前序遍历
void PreorderTree(BinaryTreeNode *root)
{
    if(root != nullptr)
    {
        std::cout << root->m_nValue << " ";
        PreorderTree(root->m_pLeft);
        PreorderTree(root->m_pRight);
    }
}

// 中序遍历
void InorderTree(BinaryTreeNode *root)
{
    if(root != nullptr)
    {
        InorderTree(root->m_pLeft);
        std::cout << root->m_nValue << " ";
        InorderTree(root->m_pRight);
    }
}

// 后续遍历
void PostorderTree(BinaryTreeNode *root)
{
    if(root != nullptr)
    {
        PostorderTree(root->m_pLeft);
        PostorderTree(root->m_pRight);
        std::cout << root->m_nValue << " ";
    }
}


void Test(char *testName, int *preorder, int *inorder, int length)
{
    std::cout << "*************" << testName << "*************" << std::endl;

    try
    {
        BinaryTreeNode *root = Construct(preorder, inorder, length);

        std::cout << "Preorder: ";
        PreorderTree(root);
        std::cout << std::endl;

        std::cout << "Inorder: ";
        InorderTree(root);
        std::cout << std::endl;

        std::cout << "Postorder: ";
        PostorderTree(root);
        std::cout << std::endl << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Invalid Input" << std::endl;
    }
    
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
    
    Test("test1", preorder, inorder, length);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};
    
    Test("test2", preorder, inorder, length);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};
    
    Test("test3", preorder, inorder, length);
}

// 树中只有一个结点1
void test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};
    
    Test("test4", preorder, inorder, length);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};
    
    Test("test5", preorder, inorder, length);
}

// 输入空指针
void test6()
{
    Test("test6", nullptr, nullptr, 0);
}

// 输入的两个序列不匹配
void test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    Test("test7", preorder, inorder, length);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
}
