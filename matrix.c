class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {


  vector<int>res;
        res.clear();
        int row=matrix.size();//����
        int collor=matrix[0].size();//����
        //�����ӡ��Ȧ��
        int circle=((row<collor?row:collor)-1)/2+1;//Ȧ��
        for(int i=0;i<circle;i++){
            //�������Ҵ�ӡ
            for(int j=i;j<collor-i;j++)
                res.push_back(matrix[i][j]);         
            //�������µ�ÿһ������
            for(int k=i+1;k<row-i;k++)
                res.push_back(matrix[k][collor-1-i]);
            //�ж��Ƿ���ظ���ӡ(���������ÿ������)
            for(int m=collor-i-2;(m>=i)&&(row-i-1!=i);m--)
                res.push_back(matrix[row-i-1][m]);
            //�ж��Ƿ���ظ���ӡ(�������ϵ�ÿһ������)
            for(int n=row-i-2;(n>i)&&(collor-i-1!=i);n--)
                res.push_back(matrix[n][i]);}
        return res;
    
    }
};