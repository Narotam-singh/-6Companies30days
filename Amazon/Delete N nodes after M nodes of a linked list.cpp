class Solution
{
    public:
    void linkdelete(struct Node* &head, int M, int N)
    {
        //Add code here
        struct Node* temp=head,*pre=head;
        int k=0;
        while(temp!=NULL){
        int i;
        if(!k)
        i=1,k=1;
        else
        i=0;
        while(i<M&&pre!=NULL)
        {
            pre=pre->next;
            i++;
        }
        if(pre==NULL)
        return;
        temp=pre->next;
        if(temp==NULL)
        return;
        i=0;
        while(i<N&&temp!=NULL)
        {
            pre->next=temp->next;
            temp->next=NULL;
            temp=pre->next;
            //pre=pre->next;
            i++;
        }
        }        
    }
};