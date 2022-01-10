class Solution{
    
public:
 struct Node{
    	unordered_map<char,Node*> next;
    	bool end;
    	Node(){
    		for (char i = 'a'; i <= 'z'; i++)
    			next[i] = NULL;
    		end = false;
    	}
    };
    Node *root = NULL;
    
    void insert(string s){
    	int len = s.length();
    	Node *itr = root;
    	for (int i = 0; i < len; i++){
    		Node *next_node = itr->next[s[i]];
    		if (next_node == NULL){
    			next_node = new Node();
    			itr->next[s[i]] = next_node;
    		}
    		itr = next_node;
    		if (i == len - 1)
    			itr->end = true;
    	}
    }
    
    void insert(string s[],int n){
    	root = new Node();
    	for (int i = 0; i < n; i++)
    		insert(s[i]);
    }
    
    void display(Node *curr, string str, 
                            vector<string> &vec){
    	if (curr->end)
    		    vec.push_back(str);
    	for (char i = 'a'; i <= 'z'; i++){
    		Node *next_node = curr->next[i];
    		if (next_node != NULL)
    			display(next_node, str + (char)i, vec);
    	}
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        insert(contact, n);
    	Node *prev = root;
        vector<vector<string>> ans;
    	string str = "";
    	int len = s.length();
    	int i;
    	for (i = 0; i < len; i++){
    		vector<string> v;
    		str += (char)s[i];
    		char last = str[i];
    		Node *curr = prev->next[last];
    		if (curr == NULL)
            {
    			v.push_back("0");
    			ans.push_back(v);
    			i++;
    			break;
    		}
    		display(curr, str, v);
    		prev = curr;
    		ans.push_back(v);
    	}
    	while(i<len){
    	    vector<string> v;
    	    v.push_back("0");
    	    ans.push_back(v);
            i++;
    	}
    	return ans;
    }
};