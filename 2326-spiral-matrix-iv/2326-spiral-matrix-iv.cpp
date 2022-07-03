/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int>(n,-1));
        int left=0, right=n-1;
        int top=0, bottom=m-1;
        int temp=0;
        while(left<=right && top<=bottom){
            if(temp==0){
                for(int i=left;i<=right;i++){
                    matrix[top][i]=head->val;
                    head=head->next;
                    if(head==NULL)
                        break;
                }
                top++;    
            }
            if(temp==1){
                for(int i=top;i<=bottom;i++){
                    matrix[i][right]=head->val;
                    head=head->next;
                    if(head==NULL)
                        break;
                }
                right--;
            }
            if(temp==2){
                for(int i=right;i>=left;i--){
                    matrix[bottom][i]=head->val;
                    head=head->next;
                    if(head==NULL)
                        break;
                }
                bottom--;    
            }
            if(temp==3){
                for(int i=bottom;i>=top;i--){
                matrix[i][left]=head->val;
                    head=head->next;
                    if(head==NULL)
                        break;
                }
                left++;
            }
            if(head==NULL)
                break;
            temp=(temp+1)%4;
        }
        return matrix;
    }
};