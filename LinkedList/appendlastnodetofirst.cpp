Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    int i=0;
    while(i<n && head!=NULL)
    {
        Node* temp = head;
        Node* prev=NULL;
        while(temp->next!=NULL)
        {
            prev = temp;
            temp=temp->next;
        }
        temp->next=head;
        prev->next=NULL;
        head = temp;
        i++;
    }
    return head;
}