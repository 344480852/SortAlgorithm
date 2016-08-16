//
// Created by 344480852 on 2016/8/16.
//

#ifndef INC_344480852_CODEHEADER_H
#define INC_344480852_CODEHEADER_H

#endif //INC_344480852_CODEHEADER_H
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};