/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterDeleteOperation(Node *head, int n, int m)
{
	// Write your code here.
	int cnt=1;
	Node* temp=head;
	Node* prev=temp;
	while(temp)
	{
		//Skipping M Nodes
		if(cnt<=m)
		{
			prev=temp;
			temp=temp->next;
			cnt++;
		}
		else
		{
			cnt=1;
			int ncnt=1;
			//Deleting Next N Nodes
			while(ncnt<=n)
			{
				Node* next=temp->next;
				if(next==nullptr)
				{
					prev->next=nullptr;
					return head;
				}

				delete(temp);
				temp=next;
				ncnt++;
			}
			prev->next=temp;
			
		}
	}
	return head;
}
