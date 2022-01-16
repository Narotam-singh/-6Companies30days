vector<string> generate(int N)
{
	// Your code here
	vector<string> v;
	queue<string> q;
	q.push("1");
	
	int i=0;
	while(i<N)
	{
	    string x=q.front();
	    v.push_back(x);
	    q.pop();
	    q.push(x+"0");
	    q.push(x+"1");
	    i++;
	}
	return v;
}