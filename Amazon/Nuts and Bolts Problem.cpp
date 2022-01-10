class Solution{

public:	
    
    int choose(char ch)
    {
        switch(ch)
        {
            case '!':return 1;
            case '#':return 2;
            case '$':return 3;
            case '%':return 4;
            case '&':return 5;
            case '*':return 6;
            case '@':return 7;
            case '^':return 8;
            case '~':return 9;
        }
    }
    char in_choose(int ch)
    {
        switch(ch)
        {
            case 0:return '!';
            case 1:return '#';
            case 2:return '$';
            case 3:return '%';
            case 4:return '&';
            case 5:return '*';
            case 6:return '@';
            case 7:return '^';
            case 8:return '~';
        }
    }
    
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        arr[i]=choose(nuts[i])-1;
	    }
	    sort(arr,arr+n);
	    char arr1[n];
	    for(int i=0;i<n;i++)
	    {
	        arr1[i]=in_choose(arr[i]);
	    }
	    for(int i=0;i<n;i++)
	    {
	        nuts[i]=arr1[i];
	        bolts[i]=arr1[i];
	    }
	}

};